//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tlogin *login;

void __fastcall Tlogin::RendreTransparent(TImage* image)
{
    image->Transparent = true;
    image->Picture->Bitmap->TransparentColor = clFuchsia;
    image->Picture->Bitmap->Transparent = true;
}
//---------------------------------------------------------------------------
__fastcall Tlogin::Tlogin(TComponent* Owner)
        : TForm(Owner)
{
        RendreTransparent(Inscrire);
        InscrirePosition = Inscrire->Top;
        btnsctPosition = btnseconnecter->Top;
}
//---------------------------------------------------------------------------

void __fastcall Tlogin::HoverEffect(TImage *btn, int btnPosition)
{
    if(mouse_stat)
     {
        btn->Top = btnPosition - 2;
     }else{
        btn->Top = btnPosition;
     }
}

void __fastcall Tlogin::InscrireMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
     mouse_stat = true;
     HoverEffect(Inscrire, InscrirePosition);
}
//---------------------------------------------------------------------------


void __fastcall Tlogin::Righpanel_bgMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
     mouse_stat = false;
     HoverEffect(Inscrire, InscrirePosition);
}
//---------------------------------------------------------------------------



void __fastcall Tlogin::seconnercterMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        mouse_stat = false;
        HoverEffect(btnseconnecter, btnsctPosition);
}
//---------------------------------------------------------------------------

void __fastcall Tlogin::btnseconnecterMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        mouse_stat = true;
        HoverEffect(btnseconnecter, btnsctPosition);        
}
//---------------------------------------------------------------------------

void __fastcall Tlogin::InscrireClick(TObject *Sender)
{
        Inscription->Show();
        mdp->Text = "";
        email->Text = "";
        login->Hide();
}
//---------------------------------------------------------------------------

void __fastcall Tlogin::btnseconnecterClick(TObject *Sender)
{
        String email = login->email->Text.Trim();
        String motDePasse = login->mdp->Text;
if (email.IsEmpty() || motDePasse.IsEmpty())
{
    ShowMessage("Veuillez remplir tous les champs !");
    return;
}

try
{
    Database->Query->Close();
    Database->Query->SQL->Clear();

    Database->Query->SQL->Text = "SELECT * FROM utilisateur WHERE email_ut = '" + email + "'";
    Database->Query->Prepared = true;
    Database->Query->Open();

    if (!Database->Query->Eof)
    {
        String mdpStock = Database->Query->FieldByName("password_ut")->AsString;
        
        if (motDePasse == mdpStock)
        {
            nom = Database->Query->FieldByName("nom_ut")->AsString;
            IdUser = Database->Query->FieldByName("Id_ut")->AsInteger;
            //ShowMessage("Connexion réussie! Bienvenue " + nom);
            
            Mainform->ChargerProjets();
            Mainform->AfficherTousProjets(2);

            Dashboard->cartesStat();
            Dashboard->creerGraphiqueLigne();

            login->mdp->Text = "";
            login->email->Text = "";
            Dashboard->Show();
            this->Hide();
        }
        else
        {
            ShowMessage("Mot de passe incorrect");
        }
    }
    else
    {
        ShowMessage("Utilisateur n'existe pas");
    }
}
catch (Exception &e)
{
    ShowMessage("Erreur: " + e.Message);
}
}
//---------------------------------------------------------------------------


void __fastcall Tlogin::FormCreate(TObject *Sender)
{
        ShowMessage("Pour garantir la bonne visibilité, merci de ne pas déplacer les fenêtres.");        
}
//---------------------------------------------------------------------------

