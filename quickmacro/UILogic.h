//---------------------------------------------------------------------------

#ifndef UILogicH
#define UILogicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <windows.h>
#include <map>
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TListBox *list_progress;
        TButton *btn_refreshProgress;
        TGroupBox *GroupBox2;
        TButton *Button1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit2;
        TLabel *Label5;
        TListBox *ListBox1;
        TLabel *Label6;
        TEdit *OpenFile_Text;
        TButton *Button2;
        TRadioButton *open_Radiobtn;
        TComboBox *mouseEventFilter;
        TRadioButton *close_Radiobtn;
        TLabel *Label7;
        TButton *Button3;
        void __fastcall btn_refreshProgressClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

private:
        void loadProgress();
        static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
        static std::map<void*,std::string> s_progressList;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 