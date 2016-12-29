
#ifndef USER_UM_TRAY
#define USER_UM_TRAY	(WM_USER+1321)
#endif

#ifndef ICE__TRAY_H__
#define ICE__TRAY_H__

class _declspec(dllexport) CIceTray
{
private:
   int m_nMessageID;
   HWND m_hWnd;

private:
   BOOL DoAddModify(char *strTitle, int nOperation);

public:
   CIceTray(HWND hwndParent=NULL, int nMessageID=0);
   virtual ~CIceTray();

public:
   BOOL Add(char *strTitle=NULL);

   BOOL Modify(char *strTitle=NULL);

   BOOL Delete();

   void SetNotifyWindow(HWND hwndNotifyWindow, int nMessageID);

};

#endif
