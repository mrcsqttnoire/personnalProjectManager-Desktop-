//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TDashboard : public TForm
{
__published:	// Composants gérés par l'EDI
        TPanel *sidebar;
        TLabel *Label1;
        TImage *dashboard;
        TImage *recherche;
        TImage *user;
        TImage *logout;
        TImage *projet;
        TPanel *Panel2;
        TImage *Image1;
        TLabel *enCours;
        TImage *Image2;
        TLabel *Termines;
        TImage *Image3;
        TLabel *Total;
        TChart *ChartLine;
        TLabel *Label2;
        TLabel *Libelle;
        TLabel *Label3;
        TImage *logo;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall logoutClick(TObject *Sender);
        void __fastcall logoutMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall projetClick(TObject *Sender);
        void __fastcall rechercheClick(TObject *Sender);
        void __fastcall userMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// Déclarations de l'utilisateur
        int logoutPosition;
        String sql;

public:		// Déclarations de l'utilisateur
        __fastcall TDashboard(TComponent* Owner);
        void __fastcall cartesStat();
        void __fastcall TDashboard::creerGraphiqueLigne();
};
//---------------------------------------------------------------------------
extern PACKAGE TDashboard *Dashboard;
//---------------------------------------------------------------------------
#endif
