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
TDashboard *Dashboard;
//---------------------------------------------------------------------------
__fastcall TDashboard::TDashboard(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDashboard::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        Application->Terminate();        
}
//---------------------------------------------------------------------------
void __fastcall TDashboard::FormCreate(TObject *Sender)
{
        login->RendreTransparent(dashboard);
        login->RendreTransparent(projet);
        login->RendreTransparent(logout);
        login->RendreTransparent(recherche);
        login->RendreTransparent(user);
        login->RendreTransparent(logo);
        logoutPosition = logout->Top;

        //cartesStat();
        //creerGraphiqueLigne();
}
//---------------------------------------------------------------------------
void __fastcall TDashboard::projetClick(TObject *Sender)
{
        Mainform->Show();
        this->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TDashboard::logoutMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = true;
        login->HoverEffect(logout, logoutPosition);        
}
//---------------------------------------------------------------------------
void __fastcall TDashboard::logoutClick(TObject *Sender)
{
        String message = "Êtes-vous sûr de vous déconnecter";
        if(MessageDlg(message, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes){
                login->IdUser = 0;
                this->Hide();
                login->Show();
        }        
}
//---------------------------------------------------------------------------


void __fastcall TDashboard::rechercheClick(TObject *Sender)
{
        sql = "SELECT * FROM projet JOIN priorite ON projet.Id_priorite = priorite.Code_p WHERE id_ut = " + IntToStr(login->IdUser) + " " + "ORDER BY CASE WHEN statut_p = 'en_cours' THEN 1 WHEN statut_p = 'termine' THEN 2 END, Id_p DESC";
        Recherche->ChargerProjets(sql);
        Recherche->AfficherTousProjets(3);
        Recherche->Show();
        this->Hide();        
}
//---------------------------------------------------------------------------


void __fastcall TDashboard::cartesStat()
{
        Database->QueryCard1->Close();
        Database->QueryCard1->SQL->Clear();
        Database->QueryCard1->SQL->Add("SELECT COUNT(*) AS encours FROM projet WHERE Id_ut = " + IntToStr(login->IdUser) + " AND statut_p = 'en_cours'");
        Database->QueryCard1->Open();
        enCours->Caption = Database->QueryCard1->FieldByName("encours")->AsString;

        Database->QueryCard2->Close();
        Database->QueryCard2->SQL->Clear();
        Database->QueryCard2->SQL->Add("SELECT COUNT(*) AS termine FROM projet WHERE Id_ut = " + IntToStr(login->IdUser) + " AND statut_p = 'termine'");
        Database->QueryCard2->Open();
        Termines->Caption = Database->QueryCard2->FieldByName("termine")->AsString;

        Database->QueryCard3->Close();
        Database->QueryCard3->SQL->Clear();
        Database->QueryCard3->SQL->Add("SELECT COUNT(*) AS total FROM projet WHERE Id_ut = " + IntToStr(login->IdUser));
        Database->QueryCard3->Open();
        Total->Caption = Database->QueryCard3->FieldByName("total")->AsString;
}

void __fastcall TDashboard::creerGraphiqueLigne()
{
    ChartLine->SeriesList->Clear();

    TLineSeries *series = new TLineSeries(ChartLine);
    ChartLine->AddSeries(series);
    series->Title = "Projets créés";
    series->LinePen->Width = 2;

    try {
        Database->Query->Close();
        Database->Query->SQL->Clear();
        Database->Query->SQL->Add("SELECT DATE_FORMAT(date_creation, '%Y-%m') as mois, COUNT(*) as nb FROM projet WHERE Id_ut = " + IntToStr(login->IdUser) + " GROUP BY DATE_FORMAT(date_creation, '%Y-%m') ORDER BY mois");
        Database->Query->Open();
        
        if(Database->Query->IsEmpty()) {
            ShowMessage("Dashboard info : \"Aucune donnée pour le graphique\"");
            return;
        }
        
        Database->Query->First();
        int index = 0;
        while(!Database->Query->Eof)
        {
            String mois = Database->Query->FieldByName("mois")->AsString;
            int nb = Database->Query->FieldByName("nb")->AsInteger;

            series->AddXY(index, nb, mois, (TColor)0x4444ef);
            
            index++;
            Database->Query->Next();
        }
        
        Database->Query->Close();
    }
    catch(Exception &e) {
        ShowMessage("Erreur graphique ligne: " + e.Message);
    }
}
void __fastcall TDashboard::userMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        ShowMessage("Boujour " + login->nom + " !");
}
//---------------------------------------------------------------------------


