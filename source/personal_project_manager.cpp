//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Mainform);
USEFORM("Unit2.cpp", Database); /* TDataModule: File Type */
USEFORM("Unit3.cpp", login);
USEFORM("Unit4.cpp", Inscription);
USEFORM("Unit5.cpp", Recherche);
USEFORM("Unit6.cpp", Dashboard);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Personnal Project Manager";
                 Application->HelpFile = "";
                 Application->CreateForm(__classid(TDatabase), &Database);
                 Application->CreateForm(__classid(Tlogin), &login);
                 Application->CreateForm(__classid(TMainform), &Mainform);
                 Application->CreateForm(__classid(TInscription), &Inscription);
                 Application->CreateForm(__classid(TRecherche), &Recherche);
                 Application->CreateForm(__classid(TDashboard), &Dashboard);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
