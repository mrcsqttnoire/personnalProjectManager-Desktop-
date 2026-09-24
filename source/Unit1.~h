//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <vector>

struct Projet {
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
class TMainform : public TForm
{
__published:	// Composants gérés par l'EDI
        TPanel *sidebar;
        TPanel *Panel2;
        TImage *dashboard;
        TImage *projet;
        TImage *recherche;
        TImage *user;
        TImage *logout;
        TImage *logo;
        TScrollBox *ScrollBoxProjets;
        TLabel *Label1;
        TLabel *mesProjets;
        TPanel *Formulaire;
        TLabel *Libelle;
        TImage *background;
        TLabeledEdit *titreProjet;
        TDateTimePicker *DateDebut;
        TDateTimePicker *DateFin;
        TLabel *LabelDateDebut;
        TLabel *LabelDateFin;
        TComboBox *Categorie;
        TRadioGroup *RadioGroupePriorite;
        TRadioButton *RadioNormal;
        TRadioButton *RadioImportant;
        TRadioButton *RadioUrgent;
        TLabel *LabelCategorie;
        TLabel *LabelPriorite;
        TImage *Reset;
        TImage *Ajouter;
        TTimer *TimerRefresh;
        TImage *Valider;
        TImage *Annuler;
        TMemo *Description;
        TLabel *Label2;
        TMemo *NoteAdditionnelle;
        TLabel *LabelNote;
        TPanel *DetailProjet;
        TImage *bg;
        TLabel *LabelDateDuDebut;
        TLabel *LabelDateDeFin;
        TLabel *LabelCatego;
        TLabel *LabelStatut;
        TImage *Retour;
        TLabel *Labeldescription;
        TLabel *LabelNoteAdd;
        TMemo *DetailDescription;
        TMemo *DetailNote;
        TLabel *LabelDetailTitre;
        TLabel *DetailTitre;
        TLabel *DetailDateDebut;
        TLabel *DetailDateFin;
        TLabel *DetailCategorie;
        TLabel *DetailStatut;
        TLabel *Label3;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall logoutClick(TObject *Sender);
        void __fastcall RadioImportantEnter(TObject *Sender);
        void __fastcall RadioUrgentEnter(TObject *Sender);
        void __fastcall RadioNormalEnter(TObject *Sender);
        void __fastcall AjouterMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall backgroundMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall ResetMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall AjouterClick(TObject *Sender);
        void __fastcall ResetClick(TObject *Sender);
        void __fastcall TimerRefreshTimer(TObject *Sender);
        void __fastcall ValiderClick(TObject *Sender);
        void __fastcall AnnulerClick(TObject *Sender);
        void __fastcall DetailProjetMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall userMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall sidebarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall logoutMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall rechercheClick(TObject *Sender);
        void __fastcall dashboardClick(TObject *Sender);
private:	// Déclarations de l'utilisateur
    int btnPosition, logoutPosition;
    int priorite;
    String sql;

    std::vector<Projet> projets;
    
    //void __fastcall ChargerProjets();
    //void __fastcall AfficherTousProjets();
    void __fastcall ViderAffichage();
    void __fastcall CreerCarteProjet(Projet projet, int index, int Row);
    TColor __fastcall GetCouleurPriorite(String priorite);


    void __fastcall BtnDeleteClick(TObject *Sender);
    void __fastcall BtnEditClick(TObject *Sender);
    Projet editProjet;
    void __fastcall BtnViewClick(TObject *Sender);
    void __fastcall BtnCheckClick(TObject *Sender);
public:		// Déclarations de l'utilisateur
        __fastcall TMainform(TComponent* Owner);
    void __fastcall ChargerProjets();
    void __fastcall AfficherTousProjets(int PerRow);

};
//---------------------------------------------------------------------------
extern PACKAGE TMainform *Mainform;
//---------------------------------------------------------------------------
#endif
