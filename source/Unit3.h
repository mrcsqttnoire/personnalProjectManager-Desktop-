//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Mask.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class Tlogin : public TForm
{
__published:	// Composants gérés par l'EDI
        TImage *Righpanel_bg;
        TLabel *Bienvenue;
        TPanel *Righ_panel;
        TLabel *RP_Text;
        TImage *Inscrire;
        TPanel *seconnercter;
        TLabel *seconnecter;
        TLabel *Acce;
        TImage *btnseconnecter;
        TLabeledEdit *email;
        TLabeledEdit *mdp;
        void __fastcall InscrireMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall Righpanel_bgMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall seconnercterMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall btnseconnecterMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall InscrireClick(TObject *Sender);
        void __fastcall btnseconnecterClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// Déclarations de l'utilisateur
        int InscrirePosition, btnsctPosition;

public:		// Déclarations de l'utilisateur 
        __fastcall Tlogin(TComponent* Owner); 
        void __fastcall RendreTransparent(TImage* image);
        void __fastcall HoverEffect(TImage* btn, int btnPosition);
        bool mouse_stat;
        int IdUser;
        String nom;
};
//---------------------------------------------------------------------------
extern PACKAGE Tlogin *login;
//---------------------------------------------------------------------------
#endif
