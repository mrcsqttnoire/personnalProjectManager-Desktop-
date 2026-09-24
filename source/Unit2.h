//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDatabase : public TDataModule
{
__published:	// Composants gérés par l'EDI
        TADOConnection *ADOConnection1;
        TADOQuery *Query;
        TDataSource *tousprojets;
        TADOQuery *QueryCUD;
        TADOQuery *QueryCard1;
        TADOQuery *QueryCard2;
        TADOQuery *QueryCard3;
private:	// Déclarations de l'utilisateur
public:		// Déclarations de l'utilisateur
        __fastcall TDatabase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDatabase *Database;
//---------------------------------------------------------------------------
#endif
