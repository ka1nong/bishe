//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UILogic.h"
#include <windows.h>
#include <tchar.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

        loadProgress();

}
//---------------------------------------------------------------------------
void TForm1::loadProgress()
{
        Form1->list_progress->Clear();
        EnumWindows((WNDENUMPROC)TForm1::EnumWindowsProc, NULL);
        if (!s_progressList.empty())
        {
                for (std::map<void*,std::string>::iterator iter = s_progressList.begin();
                iter != s_progressList.end(); iter++)
                {
                        Form1->list_progress->AddItem(iter->second.c_str(), Form1->list_progress);
                }
        }
        Form1->open_Radiobtn->Checked = true;
        Form1->mouseEventFilter->AddItem("ȫ��", Form1->mouseEventFilter);
        Form1->mouseEventFilter->AddItem("�Ҽ�����", Form1->mouseEventFilter);
        Form1->mouseEventFilter->AddItem("�Ҽ�˫��", Form1->mouseEventFilter);
        Form1->mouseEventFilter->AddItem("�������", Form1->mouseEventFilter);
        Form1->mouseEventFilter->AddItem("���˫��", Form1->mouseEventFilter);
        Form1->mouseEventFilter->AddItem("����ƶ�", Form1->mouseEventFilter);
        Form1->mouseEventFilter->SelText = "ȫ��";
}

std::map<void*,std::string>   TForm1::s_progressList;
BOOL CALLBACK TForm1::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    static TCHAR windowsTitle[80];
    GetWindowText(hwnd, windowsTitle, sizeof(windowsTitle));
    int len = _tcslen(windowsTitle);
    if (len != 0)
    {
        s_progressList[hwnd] = std::string(windowsTitle);
    }
    return TRUE;

}

void __fastcall TForm1::btn_refreshProgressClick(TObject *Sender)
{
        loadProgress();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        OPENFILENAME ofn;
        static char szFile[256];
        static char szFileTitle[256];
        memset(&ofn,0,sizeof(ofn));
        ofn.lStructSize=sizeof(ofn);
        ofn.hwndOwner=Form1->Handle;
        ofn.lpstrFilter="Picture File(*.ini)\0*.ini;\0\0";
        ofn.nFilterIndex=1;
        ofn.lpstrFile=szFile;
        ofn.nMaxFile=sizeof(szFile);
        ofn.lpstrFileTitle=szFileTitle;
        ofn.nMaxFileTitle=sizeof(szFileTitle);
        ofn.Flags=OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_EXPLORER;
        if(GetOpenFileName(&ofn))
        {
                Form1->OpenFile_Text->SetTextBuf(szFile);
        }
}
//---------------------------------------------------------------------------

