//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h" 
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInscription *Inscription;
//---------------------------------------------------------------------------
__fastcall TInscription::TInscription(TComponent* Owner)
        : TForm(Owner)
{
        login->RendreTransparent(sctPage);
        login->RendreTransparent(btnInscription);
        sctPagePosition = sctPage->Top;
        btnInscriptionPosition = btnInscription->Top;
}
//---------------------------------------------------------------------------
void __fastcall TInscription::sctPageClick(TObject *Sender)
{               
        login->Show();
        nomcomp->Text = "";
        mdp->Text = "";
        email->Text = "";
        Inscription->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TInscription::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TInscription::Righpanel_bgMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = false;
        login->HoverEffect(sctPage, sctPagePosition);
}
//---------------------------------------------------------------------------

void __fastcall TInscription::sctPageMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{  
        login->mouse_stat = true;
        login->HoverEffect(sctPage, sctPagePosition);
}
//---------------------------------------------------------------------------

void __fastcall TInscription::creercompteMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = false;
        login->HoverEffect(btnInscription, btnInscriptionPosition);
}
//---------------------------------------------------------------------------

void __fastcall TInscription::btnInscriptionMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        login->mouse_stat = true;
        login->HoverEffect(btnInscription, btnInscriptionPosition);
}
//---------------------------------------------------------------------------


void __fastcall TInscription::btnInscriptionClick(TObject *Sender)
{
    String nomcomp = Inscription->nomcomp->Text.Trim();
    String email = Inscription->email->Text.Trim();
    String motDePasse = Inscription->mdp->Text;

    if (nomcomp.IsEmpty() || email.IsEmpty() || motDePasse.IsEmpty())
    {
        ShowMessage("Veuillez remplir tous les champs !");
        return;
    }

    if (email.Pos("@") == 0 || email.Pos(".") == 0)
    {
        ShowMessage("Adresse email invalide !");
        return;
    }
    
    try
    {
        // CORRECT avec ADOQuery
        Database->Query->Close();
        Database->Query->SQL->Clear();
        Database->Query->SQL->Add("SELECT * FROM utilisateur WHERE email_ut = '" + email + "'");
        Database->Query->Open();
        
        if (!Database->Query->Eof)
        {
            ShowMessage("Cette adresse email est déjà utilisée !");
            Database->Query->Close();
            return;
        }

        Database->Query->Close();
        Database->Query->SQL->Clear();
        String sql = "INSERT INTO utilisateur (nom_ut, email_ut, password_ut) VALUES ('" +
                 nomcomp + "', '" + email + "', '" + motDePasse + "')";
    
        Database->Query->SQL->Text = sql;
        Database->Query->ExecSQL();

        ShowMessage("Inscription réussie ! Vous pouvez maintenant vous connecter.");
        
        login->Show();
        this->Hide();

        Inscription->nomcomp->Text = "";
        Inscription->mdp->Text = "";
        Inscription->email->Text = "";
    }
    catch (Exception &e)
    {
        ShowMessage("Erreur lors de l'inscription : " + e.Message);
    }
}
//---------------------------------------------------------------------------

