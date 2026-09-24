//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TInscription : public TForm
{
__published:	// Composants gérés par l'EDI
        TPanel *creercompte;
        TLabel *Titre;
        TLabel *Acce;
        TImage *btnInscription;
        TLabeledEdit *email;
        TLabeledEdit *mdp;
        TPanel *Left_panel;
        TImage *Righpanel_bg;
        TLabel *RP_Text;
        TLabel *Bonretour;
        TImage *sctPage;
        TLabeledEdit *nomcomp;
        void __fastcall sctPageClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Righpanel_bgMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall sctPageMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall creercompteMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall btnInscriptionMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall btnInscriptionClick(TObject *Sender);
private:	// Déclarations de l'utilisateur
        int sctPagePosition, btnInscriptionPosition;
public:		// Déclarations de l'utilisateur
        __fastcall TInscription(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInscription *Inscription;
//---------------------------------------------------------------------------
#endif
