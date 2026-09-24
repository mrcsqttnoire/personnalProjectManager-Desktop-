//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <vector>

struct ProjetRecherche {
    int id;
    String titre;
    String categorie;
    String description;
    String priorite;
    int prioriteId;
    int IdUser;
    String statut;
    String note;
    TDateTime dateDebut;
    TDateTime dateFin;
};

//---------------------------------------------------------------------------
class TRecherche : public TForm
{
__published:	// Composants gérés par l'EDI
        TPanel *Panel2;
        TPanel *sidebar;
        TLabel *Label1;
        TImage *dashboard;
        TImage *recherche;
        TImage *user;
        TImage *logout;
        TImage *logo;
        TImage *projet;
        TTimer *TimerRefresh;
        TScrollBox *ScrollBoxProjets;
        TEdit *ChampRecherche;
        TImage *btnRecherche;
        TComboBox *Type;
        TImage *bgChamp;
        TPanel *Panel1;
        TDateTimePicker *dateDebutRecherche;
        TDateTimePicker *dateFinRecherche;
        TLabel *De;
        TLabel *Label2;
        TImage *Refresh;
        TImage *Search_date;
        TLabel *Label3;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall projetClick(TObject *Sender);
        void __fastcall logoutMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall logoutClick(TObject *Sender);
        void __fastcall sidebarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall userMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall btnRechercheClick(TObject *Sender);
        void __fastcall EreshTimer(TObject *Sender);
        void __fastcall Search_dateClick(TObject *Sender);
        void __fastcall RefreshClick(TObject *Sender);
        void __fastcall RefreshMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall Panel2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Search_dateMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall dashboardClick(TObject *Sender);
private:	// Déclarations de l'utilisateur
    int logoutPosition, btnPosition;
    String sql, sqlSearch;

    void __fastcall ViderAffichage();
    void __fastcall CreerCarteProjet(ProjetRecherche projet, int index, int Row);
    TColor __fastcall GetCouleurPriorite(String priorite);
    std::vector<ProjetRecherche> projetsRecherche; 

    void __fastcall BtnDeleteClick(TObject *Sender);
    void __fastcall BtnEditClick(TObject *Sender);
    ProjetRecherche editProjet;
    void __fastcall BtnViewClick(TObject *Sender);
    void __fastcall BtnCheckClick(TObject *Sender);
public:		// Déclarations de l'utilisateur
        __fastcall TRecherche(TComponent* Owner);
    void __fastcall ChargerProjets(String sql);
    void __fastcall AfficherTousProjets(int PerRow);
    bool searchPage;
};
//---------------------------------------------------------------------------
extern PACKAGE TRecherche *Recherche;
//---------------------------------------------------------------------------
#endif
