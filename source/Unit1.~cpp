//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainform *Mainform;
//---------------------------------------------------------------------------
__fastcall TMainform::TMainform(TComponent* Owner)
        : TForm(Owner)
{
        login->RendreTransparent(dashboard);
        login->RendreTransparent(projet);
        login->RendreTransparent(logout);
        login->RendreTransparent(recherche);
        login->RendreTransparent(user);
        login->RendreTransparent(logo);
        login->RendreTransparent(background);
        login->RendreTransparent(bg);
        btnPosition = Ajouter->Top;
        logoutPosition = logout->Top;

}
//---------------------------------------------------------------------------
void __fastcall TMainform::FormClose(TObject *Sender, TCloseAction &Action)
{
        Application->Terminate();        
}
//---------------------------------------------------------------------------

void __fastcall TMainform::FormCreate(TObject *Sender)
{
    DateDebut->Date = Date();
    DateFin->Date = Date();
    DateFin->Checked = false;
    
    ChargerProjets();
    AfficherTousProjets(2);
}
//---------------------------------------------------------------------------

void __fastcall TMainform::FormDestroy(TObject *Sender)
{
    ViderAffichage();
}

void __fastcall TMainform::ChargerProjets()
{
    projets.clear();

    //ShowMessage("1. Début ChargerProjets");

    try {
        Database->Query->Close();
        Database->Query->SQL->Clear();
        Database->Query->SQL->Text = "SELECT * FROM projet JOIN priorite ON projet.Id_priorite = priorite.Code_p WHERE id_ut = " + IntToStr(login->IdUser) + " " + "ORDER BY CASE WHEN statut_p = 'en_cours' THEN 1 WHEN statut_p = 'termine' THEN 2 END, Id_p DESC";

        //ShowMessage("2. SQL préparé");

        Database->Query->Open();

        //ShowMessage("2. SQL ouvert");
        //int compteur = 0;
        Database->Query->First();
        while(!Database->Query->Eof)
        {
            Projet p;
            p.id = Database->Query->FieldByName("Id_p")->AsInteger;
            p.titre = Database->Query->FieldByName("titre_p")->AsString;
            p.categorie = Database->Query->FieldByName("categori_p")->AsString;
            p.description = Database->Query->FieldByName("description_p")->AsString;
            p.priorite = Database->Query->FieldByName("Type_p")->AsString;
            p.statut = Database->Query->FieldByName("statut_p")->AsString;
            p.dateDebut = Database->Query->FieldByName("date_debut")->AsDateTime;
            p.note = Database->Query->FieldByName("note_p")->AsString;
            
            //if(!Database->Query->FieldByName("date_fin")->IsNull)
                p.dateFin = Database->Query->FieldByName("date_fin")->AsDateTime;
            //else
                //p.dateFin = 0;
            
            projets.push_back(p);
            //compteur++;
            Database->Query->Next();

            //ShowMessage("4. " + IntToStr(compteur) + " projet(s) chargé(s) dans le vecteur");
        }
    }
    catch(Exception &e) {
        ShowMessage("Erreur de chargement: " + e.Message);
    }
}

void __fastcall TMainform::CreerCarteProjet(Projet projet, int index, int Row)
{
        //ShowMessage("8. Début CreerCarteProjet pour: " + projet.titre);
        
    int cardsPerRow = Row;
    int cardWidth = 300;
    int cardHeight = 292;
    int marginX = 30;
    int marginY = 25;
    
    int col = index % cardsPerRow;
    int row = index / cardsPerRow;
    
    int left = marginX + (col * (cardWidth + marginX));
    int top = marginY + (row * (cardHeight + marginY));

    TPanel *card = new TPanel(ScrollBoxProjets);
    card->Parent = ScrollBoxProjets;
    card->Left = left;
    card->Top = top;
    card->Width = cardWidth;
    card->Height = cardHeight;
    card->Color = (TColor)0x00F0E8E2;
    card->BevelOuter = bvNone;
    card->Tag = projet.id;

    TLabel *lblTitre = new TLabel(card);
    lblTitre->Parent = card;
    lblTitre->Caption = projet.titre;
    lblTitre->Left = 25;
    lblTitre->Top = 25;
    lblTitre->Font->Size = 12;
    lblTitre->Font->Name = "Montserrat";
    lblTitre->Font->Style = TFontStyles() << fsBold;
    lblTitre->Font->Color = (TColor)0x2a170f;
    lblTitre->Transparent = true;

    TLabel *lblCategorie = new TLabel(card);
    lblCategorie->Parent = card;
    lblCategorie->Caption = projet.categorie;
    lblCategorie->Left = 25;
    lblCategorie->Top = 48;
    lblCategorie->Font->Size = 8;
    lblCategorie->Font->Name = "Montserrat";
    lblCategorie->Font->Color = clGray;
    lblCategorie->Transparent = true;

    TPanel *badgePriorite = new TPanel(card);
    badgePriorite->Parent = card;
    badgePriorite->Left = 180;
    badgePriorite->Top = 20;
    badgePriorite->Width = 95;
    badgePriorite->Height = 28;
    badgePriorite->Caption = projet.priorite.UpperCase();
    badgePriorite->Font->Name = "Montserrat";
    badgePriorite->Font->Color = clWhite;
    badgePriorite->Font->Style = TFontStyles() << fsBold;
    badgePriorite->Font->Size = 8;
    badgePriorite->BevelOuter = bvNone;

    if(projet.priorite == "Urgent")
        badgePriorite->Color = (TColor)0x3b4ce7;
    else if(projet.priorite == "Important")
        badgePriorite->Color = (TColor)0x0b9ef5;
    else
        badgePriorite->Color = (TColor)0x71cc2e;

    TMemo *memoDesc = new TMemo(card);
    memoDesc->Parent = card;
    memoDesc->Left = 25;
    memoDesc->Top = 75;
    memoDesc->Width = 250;
    memoDesc->Height = 51;
    memoDesc->Lines->Text = projet.description;
    memoDesc->ReadOnly = true;
    memoDesc->BorderStyle = bsNone;
    memoDesc->Color = card->Color;
    memoDesc->ScrollBars = ssNone;
    memoDesc->WordWrap = true;
    memoDesc->Font->Name = "Montserrat";

    TLabel *lblDateDebut = new TLabel(card);
    lblDateDebut->Parent = card;
    lblDateDebut->Caption = "Début: " + DateToStr(projet.dateDebut);
    lblDateDebut->Left = 25;
    lblDateDebut->Top = 145;
    lblDateDebut->Font->Size = 8;
    lblDateDebut->Font->Name = "Times New Roman";
    lblDateDebut->Font->Color = clGray;
    lblDateDebut->Transparent = true;
    
    TLabel *lblDateFin = new TLabel(card);
    lblDateFin->Parent = card;
    String dateFin = DateToStr(projet.dateFin) ;
    if(dateFin == "30/12/1899")
        dateFin = "Non spécifiée";
    else
        dateFin = dateFin;
    lblDateFin->Caption = "Fin: " + dateFin;
    lblDateFin->Left = 25;
    lblDateFin->Top = 160;
    lblDateFin->Font->Size = 8;
    lblDateFin->Font->Name = "Times New Roman";
    lblDateFin->Font->Color = clGray;
    lblDateFin->Transparent = true;

    TPanel *badgeStatut = new TPanel(card);
    badgeStatut->Parent = card;
    badgeStatut->Left = 180;
    badgeStatut->Top = 145;
    badgeStatut->Width = 95;
    badgeStatut->Height = 24;
    badgeStatut->Caption = projet.statut;
    badgeStatut->Font->Name = "Montserrat";
    badgeStatut->Font->Size = 8;
    badgeStatut->Font->Style = TFontStyles() << fsBold;
    badgeStatut->BevelOuter = bvNone;
    
    if(projet.statut == "en_cours") {
        badgeStatut->Color = (TColor)0xfdf2e3;
        badgeStatut->Font->Color = (TColor)0xd27619;
    } else {
        badgeStatut->Color = (TColor)0xe8f5e8;
        badgeStatut->Font->Color = (TColor)0x327d2e;
    }
    
    // Boutons d'action
    int btnTop = 220;
    int btnSize = 38  ;
    bool termine = (projet.statut == "termine");
    
    // Bouton Supprimer
    TImage *btnDelete = new TImage(card);
    btnDelete->Parent = card;
    btnDelete->Left = 25;
    btnDelete->Top = btnTop;
    btnDelete->Width = btnSize;
    btnDelete->Height = btnSize;
    btnDelete->Picture->LoadFromFile("icon\\trash.bmp");
    login->RendreTransparent(btnDelete);
    btnDelete->Tag = projet.id;
    btnDelete->OnClick = BtnDeleteClick;
    
    // Bouton Voir
    TImage *btnView = new TImage(card);
    btnView->Parent = card;
    btnView->Left = 75;
    btnView->Top = btnTop;
    btnView->Width = btnSize;
    btnView->Height = btnSize;
    btnView->Picture->LoadFromFile("icon\\eye.bmp");
    login->RendreTransparent(btnView);
    btnView->Tag = projet.id;
    btnView->OnClick = BtnViewClick;
    
    // Bouton Modifier
    TImage *btnEdit = new TImage(card);
    btnEdit->Parent = card;
    btnEdit->Left = 125;
    btnEdit->Top = 219;
    btnEdit->Width = btnSize;
    btnEdit->Height = btnSize ;
    btnEdit->Picture->LoadFromFile("icon\\edit.bmp");
    btnEdit->Tag = projet.id;
    btnEdit->OnClick = BtnEditClick;
    btnEdit->Visible = !termine;
    login->RendreTransparent(btnEdit);
    
    // Bouton Terminer
    TImage *btnCheck = new TImage(card);
    btnCheck->Parent = card;
    btnCheck->Left = 175;
    btnCheck->Top = btnTop;
    btnCheck->Width = btnSize;
    btnCheck->Height = btnSize;
    btnCheck->Picture->LoadFromFile("icon\\check.bmp");
    login->RendreTransparent(btnCheck);
    btnCheck->Tag = projet.id;
    btnCheck->OnClick = BtnCheckClick;
    btnCheck->Visible = !termine;
}
void __fastcall TMainform::AfficherTousProjets(int PerRow)
{
    ViderAffichage();
    
    for(size_t i = 0; i < projets.size(); i++)
    {
        CreerCarteProjet(projets[i], i, PerRow);
    }
}

void __fastcall TMainform::ViderAffichage()
{
    while(ScrollBoxProjets->ControlCount > 0)
    {
        delete ScrollBoxProjets->Controls[0];
    }
}

void __fastcall TMainform::BtnDeleteClick(TObject *Sender)
{
    TImage *btn = dynamic_cast<TImage*>(Sender);
    if(!btn) return;

    int projetId = btn->Tag;

    String nomProjet = "";
    for(size_t i = 0; i < projets.size(); i++) {
        if(projets[i].id == projetId) {
            nomProjet = projets[i].titre;
            break;
        }
    }

    String message = "Voulez-vous vraiment supprimer ce projet :\n\n\"" + nomProjet + "\" ?";
    if(MessageDlg(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
    {
        Database->QueryCUD->Close();
        Database->QueryCUD->SQL->Clear();
        String sqlDelete = "DELETE FROM projet WHERE Id_p = " + IntToStr(projetId);
        Database->QueryCUD->SQL->Add(sqlDelete);
        try {
            Database->QueryCUD->ExecSQL();
            //ShowMessage("Projet supprimé avec succès !");
            //ChargerProjets();
            //AfficherTousProjets();
            TimerRefresh->Enabled = true;
        }
        catch(Exception &e) {
            ShowMessage("Erreur lors de la suppression : " + e.Message);
        }
    }
}

void __fastcall TMainform::BtnEditClick(TObject *Sender)
{
    TImage *btn = dynamic_cast<TImage*>(Sender);
    if(!btn) return;

    int projetId = btn->Tag;
    for(size_t i = 0; i < projets.size(); i++) {
        if(projets[i].id == projetId) {
            editProjet.id = projets[i].id;
            editProjet.titre = projets[i].titre;
            editProjet.description = projets[i].description;
            editProjet.priorite = projets[i].priorite;
            editProjet.categorie = projets[i].categorie;
            editProjet.statut = projets[i].statut;
            editProjet.note = projets[i].note;
            editProjet.dateDebut = projets[i].dateDebut;
            editProjet.dateFin = projets[i].dateFin;
            break;
        }
    }
    Libelle->Caption = "Modification du projet";
    if(!Formulaire->Visible){
        Formulaire->Visible = true;
        DetailProjet->Visible = false;
    }
    Reset->Visible = false;
    Ajouter->Visible = false;
    Valider->Visible = true;
    Annuler->Visible = true;

    titreProjet->Text = editProjet.titre;
    Description->Text = editProjet.description;
    Categorie->Text = editProjet.categorie;
    DateDebut->Date = editProjet.dateDebut;

    if(DateToStr(editProjet.dateFin) == "30/12/1899"){
        DateFin->Date = Date();
        DateFin->Checked = false;
    }else
        DateFin->Date = editProjet.dateFin;

    NoteAdditionnelle->Text = editProjet.note;

    if(editProjet.priorite == "Normal"){
        RadioNormal->Checked = true;
        RadioNormal->Color = (TColor) 0x0081B910;
        RadioImportant->Color = (TColor) 0x00f0e8e2;
        RadioUrgent->Color =  (TColor) 0x00f0e8e2;

    }else if(editProjet.priorite == "Important"){
        RadioImportant->Checked = true;
        RadioNormal->Color = (TColor) 0x00f0e8e2;
        RadioImportant->Color = (TColor) 0x000b9ef5;
        RadioUrgent->Color =  (TColor) 0x00f0e8e2;

    }if(editProjet.priorite == "Urgent"){
        RadioUrgent->Checked = true;
        RadioNormal->Color = (TColor) 0x00f0e8e2;
        RadioImportant->Color = (TColor) 0x00f0e8e2;
        RadioUrgent->Color =  (TColor) 0x004444ef;
    }

}

void __fastcall TMainform::BtnViewClick(TObject *Sender)
{
    TImage *btn = dynamic_cast<TImage*>(Sender);
    if(!btn) return;

    Projet viewProjet;
    int projetId = btn->Tag;
    for(size_t i = 0; i < projets.size(); i++) {
        if(projets[i].id == projetId) {
            viewProjet.id = projets[i].id;
            viewProjet.titre = projets[i].titre;
            viewProjet.description = projets[i].description;
            viewProjet.priorite = projets[i].priorite;
            viewProjet.categorie = projets[i].categorie;
            viewProjet.statut = projets[i].statut;
            viewProjet.note = projets[i].note;
            viewProjet.dateDebut = projets[i].dateDebut;
            viewProjet.dateFin = projets[i].dateFin;
            break;
        }
    }
    Libelle->Caption = "Détails du projet";
    DetailProjet->Left = 776;
    DetailProjet->Top = 88;
    Formulaire->Visible = false;
    DetailProjet->Visible = true;

    DetailTitre->Caption = viewProjet.titre;
    DetailDescription->Text = viewProjet.description;
    DetailCategorie->Caption = viewProjet.categorie;
    DetailDateDebut->Caption = DateToStr(viewProjet.dateDebut);

    if(DateToStr(viewProjet.dateFin) == "30/12/1899")
        DetailDateFin->Caption = "Non spécifiée";
    else
        DetailDateFin->Caption = viewProjet.dateFin;

    DetailStatut->Caption = viewProjet.statut;

    if(viewProjet.note.IsEmpty())
        DetailNote->Text = "Sans note";
    else
        DetailNote->Text = viewProjet.note;

}

void __fastcall TMainform::BtnCheckClick(TObject *Sender)
{
    TImage *btn = dynamic_cast<TImage*>(Sender);
    if(!btn) return;

    int projetId = btn->Tag;

    String nomProjet = "";
    for(size_t i = 0; i < projets.size(); i++) {
        if(projets[i].id == projetId) {
            nomProjet = projets[i].titre;
            break;
        }
    }

    String message = "On a besoin de votre confirmation s'il vous plait \n\n\:)";
    if(MessageDlg(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
    {
        Database->QueryCUD->Close();
        Database->QueryCUD->SQL->Clear();
        sql = "UPDATE projet SET Statut_p = 'termine' WHERE Id_p = " + IntToStr(projetId);
        Database->QueryCUD->SQL->Add(sql);
        try {
            Database->QueryCUD->ExecSQL();
            ShowMessage("Félicitation vous avez fini le projet : '" + nomProjet + "'");
            //ChargerProjets();
            //AfficherTousProjets();
            TimerRefresh->Enabled = true;
        }
        catch(Exception &e) {
            ShowMessage("Erreur lors de la suppression : " + e.Message);
        }
    }
}


//---------------------------------------------------------------------------






//---------------------------------------------------------------------------








void __fastcall TMainform::logoutClick(TObject *Sender)
{
        String message = "Êtes-vous sur de vous déconnecter";
        if(MessageDlg(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes){
                login->IdUser = 0;
                this->Hide();
                login->Show();
        }
}
//---------------------------------------------------------------------------


void __fastcall TMainform::RadioImportantEnter(TObject *Sender)
{
        RadioNormal->Color = (TColor) 0x00f0e8e2;
        RadioImportant->Color = (TColor) 0x000b9ef5;
        RadioUrgent->Color =  (TColor) 0x00f0e8e2;
}
//---------------------------------------------------------------------------


void __fastcall TMainform::RadioUrgentEnter(TObject *Sender)
{
        RadioNormal->Color = (TColor) 0x00f0e8e2;
        RadioImportant->Color = (TColor) 0x00f0e8e2;
        RadioUrgent->Color =  (TColor) 0x004444ef;
}
//---------------------------------------------------------------------------

void __fastcall TMainform::RadioNormalEnter(TObject *Sender)
{
        RadioNormal->Color = (TColor) 0x0081B910;
        RadioImportant->Color = (TColor) 0x00f0e8e2;
        RadioUrgent->Color =  (TColor) 0x00f0e8e2;
}
//---------------------------------------------------------------------------


void __fastcall TMainform::AjouterMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{

        login->mouse_stat = true;
        login->HoverEffect(Ajouter, btnPosition);
        login->HoverEffect(Valider, btnPosition);
}
//---------------------------------------------------------------------------

void __fastcall TMainform::backgroundMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = false;
        login->HoverEffect(Ajouter, btnPosition);
        login->HoverEffect(Reset, btnPosition);
        login->HoverEffect(Valider, btnPosition);
        login->HoverEffect(Annuler, btnPosition);
        login->HoverEffect(Retour, btnPosition);

}
//---------------------------------------------------------------------------



void __fastcall TMainform::ResetMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = true;
        login->HoverEffect(Reset, btnPosition);
        login->HoverEffect(Annuler, btnPosition);
        login->HoverEffect(Retour, btnPosition);
        login->HoverEffect(logout, logoutPosition);        
}
//---------------------------------------------------------------------------


void __fastcall TMainform::AjouterClick(TObject *Sender)
{
    Projet nouveauProjet;
    TDateTime dateCreation = Date();
    
    nouveauProjet.titre = titreProjet->Text.Trim();
    nouveauProjet.description = Description->Text.Trim();
    nouveauProjet.dateDebut = DateDebut->Date;
    nouveauProjet.note = NoteAdditionnelle->Text.Trim();
    nouveauProjet.categorie = Categorie->Text;
    nouveauProjet.IdUser = login->IdUser;
    //ShowMessage(nouveauProjet.IdUser);
    if (RadioNormal->Checked)
        nouveauProjet.prioriteId = 1;
    else if (RadioImportant->Checked)
        nouveauProjet.prioriteId = 2;
    else if (RadioUrgent->Checked)
        nouveauProjet.prioriteId = 3;

    //ShowMessage(nouveauProjet.dateFin);

    if (nouveauProjet.titre.IsEmpty() || nouveauProjet.description.IsEmpty() || nouveauProjet.categorie.IsEmpty())
    {
        ShowMessage("Veuillez remplir les champs avec (*) !");
        return;
    }

    if(DateFin->Checked)
    {
        if(DateFin->Date < DateDebut->Date)
        {
            ShowMessage("La date de fin doit être postérieure à la date de début");
            DateFin->SetFocus();
            return;
        }
        else
        {
            nouveauProjet.dateFin = DateFin->Date;
            sql = "INSERT INTO projet(`titre_p`, `description_p`, `date_debut`, `date_fin`, `Id_priorite`, `statut_p`, `categori_p`, `note_p`, `id_ut`, `date_creation`) VALUES ('"+ nouveauProjet.titre + "','"+ nouveauProjet.description + "','"+ nouveauProjet.dateDebut.FormatString("yyyy-mm-dd") + "','"+ nouveauProjet.dateFin.FormatString("yyyy-mm-dd") + "',"+ IntToStr(nouveauProjet.prioriteId) + ",'en_cours','"+ nouveauProjet.categorie + "','"+ nouveauProjet.note + "',"+ IntToStr(nouveauProjet.IdUser) + ",'"+ dateCreation.FormatString("yyyy-mm-dd") + "')";
        }
    }else{
        sql = "INSERT INTO projet(`titre_p`, `description_p`, `date_debut`, `date_fin`, `Id_priorite`, `statut_p`, `categori_p`, `note_p`, `id_ut`, `date_creation`) VALUES ('"+ nouveauProjet.titre + "','"+ nouveauProjet.description + "','"+ nouveauProjet.dateDebut.FormatString("yyyy-mm-dd") + "', NULL ,"+ IntToStr(nouveauProjet.prioriteId) + ",'en_cours','"+ nouveauProjet.categorie + "','"+ nouveauProjet.note + "',"+ IntToStr(nouveauProjet.IdUser) + ",'"+ dateCreation.FormatString("yyyy-mm-dd") + "')";
    }

    Database->QueryCUD->Close();
    Database->QueryCUD->SQL->Clear();
    Database->QueryCUD->SQL->Add(sql);
    try {
        Database->QueryCUD->ExecSQL();
        ShowMessage("Projet ajouté avec succès !");
        //ChargerProjets();
        //AfficherTousProjets();
        TimerRefresh->Enabled = true;

    }
    catch (Exception &e) {
        ShowMessage("Erreur : " + e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainform::ResetClick(TObject *Sender)
{
    titreProjet->Text = "";
    Description->Text = "";
    DateDebut->Date = Date();
    DateFin->Date = Date();
    DateFin->Checked = false;
    NoteAdditionnelle->Text = "";
    Categorie->Text = "";
    RadioNormal->Checked = true;
    RadioNormal->Color = (TColor) 0x0081B910;
    RadioImportant->Color = (TColor) 0x00f0e8e2;
    RadioUrgent->Color =  (TColor) 0x00f0e8e2;
}
//---------------------------------------------------------------------------

void __fastcall TMainform::TimerRefreshTimer(TObject *Sender)
{
        TimerRefresh->Enabled = false;
        titreProjet->Text = "";
        Description->Text = "";
        DateDebut->Date = Date();
        NoteAdditionnelle->Text = "";
        Categorie->Text = "";
        RadioNormal->Checked = true;
        RadioNormal->Color = (TColor) 0x0081B910;
        RadioImportant->Color = (TColor) 0x00f0e8e2;
        RadioUrgent->Color =  (TColor) 0x00f0e8e2;

        DateDebut->Date = Date();
        DateFin->Date = Date();
        DateFin->Checked = false;

        if(!Formulaire->Visible){
                Formulaire->Visible = true;
                DetailProjet->Visible = false;
        }
        Reset->Visible = true;
        Ajouter->Visible = true;
        Valider->Visible = false;
        Annuler->Visible = false;

        Dashboard->cartesStat();
        Dashboard->creerGraphiqueLigne();
        
        ChargerProjets();
        AfficherTousProjets(2);
}
//---------------------------------------------------------------------------



void __fastcall TMainform::ValiderClick(TObject *Sender)
{
    //Projet editProjet;

    editProjet.titre = titreProjet->Text.Trim();
    editProjet.description = Description->Text.Trim();
    editProjet.dateDebut = DateDebut->Date;
    editProjet.note = NoteAdditionnelle->Text.Trim();
    editProjet.categorie = Categorie->Text;

    if (RadioNormal->Checked)
        editProjet.prioriteId = 1;
    else if (RadioImportant->Checked)
        editProjet.prioriteId = 2;
    else if (RadioUrgent->Checked)
        editProjet.prioriteId = 3;

    if(DateFin->Checked)
    {
        if(DateFin->Date < DateDebut->Date)
        {
            ShowMessage("La date de fin doit être postérieure à la date de début");
            DateFin->SetFocus();
            return;
        }
        else
        {
            editProjet.dateFin = DateFin->Date;
            sql = "UPDATE projet SET titre_p = '"+ editProjet.titre + "', description_p = '"+ editProjet.description + "', date_debut = '"+ editProjet.dateDebut.FormatString("yyyy-mm-dd") + "', date_fin = '"+ editProjet.dateFin.FormatString("yyyy-mm-dd") + "', Id_priorite = "+ IntToStr(editProjet.prioriteId) + ", categori_p = '"+ editProjet.categorie + "', note_p = '"+ editProjet.note + "' WHERE id_p = " + IntToStr(editProjet.id);
        }
    }else{
        sql = "UPDATE projet SET titre_p = '"+ editProjet.titre + "', description_p = '"+ editProjet.description + "', date_debut = '"+ editProjet.dateDebut.FormatString("yyyy-mm-dd") + "', date_fin = NULL, Id_priorite = "+ IntToStr(editProjet.prioriteId) + ", categori_p = '"+ editProjet.categorie + "', note_p = '"+ editProjet.note + "' WHERE id_p = " + IntToStr(editProjet.id);
    }

    if (editProjet.titre.IsEmpty() || editProjet.description.IsEmpty() || editProjet.categorie.IsEmpty())
    {
        ShowMessage("Veuillez remplir les champs avec (*) !");
        return;
    }

    Database->QueryCUD->Close();
    Database->QueryCUD->SQL->Clear();
    Database->QueryCUD->SQL->Add(sql);
    try {
        Database->QueryCUD->ExecSQL();
        ShowMessage("Projet modifié avec succès !");

        //ChargerProjets();
        //AfficherTousProjets();
        TimerRefresh->Enabled = true;
        Recherche->TimerRefresh->Enabled = true;

        Libelle->Caption = "Commencer un nouveau Projet";

    }
    catch (Exception &e) {
        ShowMessage("Erreur : " + e.Message);
    }

}
//---------------------------------------------------------------------------

void __fastcall TMainform::AnnulerClick(TObject *Sender)
{
        if(!Recherche->searchPage){
                Libelle->Caption = "Commencer un nouveau Projet";
                TimerRefresh->Enabled = true;
        }
        else{
                Recherche->searchPage = false;
                Recherche->Show();
                this->Hide();
                Libelle->Caption = "Commencer un nouveau Projet";
                TimerRefresh->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainform::DetailProjetMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = true;
        login->HoverEffect(Retour, btnPosition);
}
//---------------------------------------------------------------------------


void __fastcall TMainform::userMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        ShowMessage("Boujour " + login->nom + " !");        
}
//---------------------------------------------------------------------------

void __fastcall TMainform::sidebarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = false;
        login->HoverEffect(logout, logoutPosition);        
}
//---------------------------------------------------------------------------

void __fastcall TMainform::logoutMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = true;
        login->HoverEffect(logout, logoutPosition);
}
//---------------------------------------------------------------------------

void __fastcall TMainform::rechercheClick(TObject *Sender)
{
        sql = "SELECT * FROM projet JOIN priorite ON projet.Id_priorite = priorite.Code_p WHERE id_ut = " + IntToStr(login->IdUser) + " " + "ORDER BY CASE WHEN statut_p = 'en_cours' THEN 1 WHEN statut_p = 'termine' THEN 2 END, Id_p DESC";
        Recherche->ChargerProjets(sql);
        Recherche->AfficherTousProjets(3);
        Recherche->Show();
        this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMainform::dashboardClick(TObject *Sender)
{
        Dashboard->Show();
        this->Hide();        
}
//---------------------------------------------------------------------------

