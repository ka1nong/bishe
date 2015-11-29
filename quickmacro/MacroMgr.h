#ifndef _HOOK_MANAGER_H_
#define _HOOK_MANAGER_H_

#include <string>
#include "IFilterExt.h"
#include <vector>
#include <Windows.h>

class CMacroMgr
{
public:  //因为系统回调函数不能传递多余参数，所以这个类用单例模式
        static CMacroMgr* GetInstance();
        ~CMacroMgr();
private:
	CMacroMgr();

public:
	bool	StartRecord(HWND hWnd);
	bool	StopRecord(int nNotifyCode = 0);
	bool	StartPlayBack(HWND hWnd, std::string fileName);
	bool    StopPlayBack(int nNotifyCode = 0);
        bool    AddFilter(IFilterExt* filter);
        void    DeleteFilter(IFilterExt* filter);
        bool    ExportToFile(const std::string& fileName);
        bool    LoopPlayer(int deferSecond);
        bool    SetShortcutKey();
private:
	void    _clear();
        void    _lockInseparable();
        void    _unlockInseparable();

private:
        enum MACROSTATUS
        {
                IDLE            = 0,
                RECORD          = 1,
                PLAY_BACK       = 2
        };

private:
       static LRESULT CALLBACK RecorderFunc(int nCode, WPARAM wParam, LPARAM lParam );
       static LRESULT CALLBACK PlaybackFunc(int nCode, WPARAM wParam, LPARAM lParam );

private:
        HHOOK                           m_hhook;
        std::vector<EVENTMSG>           m_eventVec;
        std::string                     m_fileName;
        HWND                            m_hwnd;
        std::vector<IFilterExt*>        m_filters;
        MACROSTATUS                     m_status;

};

#endif  //_HOOK_MANAGER_H

