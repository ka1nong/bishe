#include "MacroMgr.h"


CMacroMgr* CMacroMgr::GetInstance()
{
        static CMacroMgr mgr;
        return &mgr;
}

CMacroMgr::CMacroMgr()
        : m_status(IDLE)
        , m_hwnd(NULL)
        , m_hhook(NULL)

{

}

CMacroMgr::~CMacroMgr()
{

}

bool CMacroMgr::StartRecord(HWND hWnd)
{
        if (m_status != IDLE)
        {
                return false;
        }

        m_hwnd = hWnd;
        _clear();

        m_status = RECORD;
        m_hhook = ::SetWindowsHookEx(WH_JOURNALRECORD, (HOOKPROC)RecorderFunc,0,0);//todo：第三个参数可能有问题
        if (!m_hhook)
        {
                m_status = IDLE;
        }
        return true;
}

bool CMacroMgr::StopRecord(int nNotifyCode)
{
        if (m_hhook == NULL)
        {
                return false;
        }

	::UnhookWindowsHookEx(m_hhook);

	m_hhook = NULL;
        m_status = IDLE;
        return true;
}

bool	CMacroMgr::StartPlayBack(HWND hWnd, std::string fileName)
{
        if (m_status != IDLE)
        {
                return false;
        }

        _clear();

	m_hwnd = hWnd;

        m_hhook = SetWindowsHookEx(WH_JOURNALPLAYBACK,(HOOKPROC)PlaybackFunc, 0, 0);
        if (!m_hhook)
        {
                m_status = IDLE;
        }

        return true;
}

bool    CMacroMgr::StopPlayBack(int nNotifyCode)
{
        return true;
}

bool    CMacroMgr::AddFilter(IFilterExt* filter)
{
         m_filters.push_back(filter);
         return true;
}

void    CMacroMgr::DeleteFilter(IFilterExt* filter)
{
        for (std::vector<IFilterExt*>::iterator iter = m_filters.begin(); iter != m_filters.end(); iter++)
        {
                if (*iter == filter)
                {
                        m_filters.erase(iter);
                        break;
                }
        }
}

bool    CMacroMgr::ExportToFile(const std::string& fileName)
{
        return true;
}

bool    CMacroMgr::LoopPlayer(int deferSecond)
{
        return true;
}

bool    CMacroMgr::SetShortcutKey()
{
        return true;
}

void    CMacroMgr::_clear()
{
        m_hwnd = NULL;
}

void    CMacroMgr::_lockInseparable()
{

}

void    CMacroMgr::_unlockInseparable()
{


}

LRESULT  CALLBACK CMacroMgr::RecorderFunc(int nCode, WPARAM wParam, LPARAM lParam )
{
        if (!CMacroMgr::GetInstance()->m_hhook)
        {
                return CallNextHookEx(CMacroMgr::GetInstance()->m_hhook, nCode, wParam, lParam);
        }

        bool bSysModalOn = false;
	if ( nCode == HC_SYSMODALON )
        {
                bSysModalOn = true;
        }
	else if ( nCode == HC_SYSMODALOFF )
        {
                bSysModalOn = false;
        }

	if ( nCode == HC_ACTION && !bSysModalOn )
        {
                //todo：快捷键
                //return CallNextHookEx(m_hhook, nCode, wParam, lParam);
                LPEVENTMSG lpEvent= (LPEVENTMSG)lParam;
                EVENTMSG event;
                event.message = lpEvent->message;
		event.paramL  = lpEvent->paramL;
		event.paramH  = lpEvent->paramH;
		event.time = GetTickCount();
		event.hwnd = NULL;
                CMacroMgr::GetInstance()->m_eventVec.push_back(event);
		return 0;
	}

        return CallNextHookEx(CMacroMgr::GetInstance()->m_hhook, nCode, wParam, lParam);
}

LRESULT CALLBACK CMacroMgr::PlaybackFunc(int nCode, WPARAM wParam, LPARAM lParam )
{
        if (!CMacroMgr::GetInstance()->m_hhook)
        {
                return 0;
        }

        if (CMacroMgr::GetInstance()->m_fileName.empty())
        {
                return CallNextHookEx(CMacroMgr::GetInstance()->m_hhook, nCode, wParam, lParam);
        }

	return CallNextHookEx(CMacroMgr::GetInstance()->m_hhook, nCode, wParam, lParam);
}





