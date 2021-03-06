﻿
// msgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "msg.h"
#include "msgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HHOOK hHook;

LRESULT __stdcall CBTHookProc(long nCode, WPARAM wParam, LPARAM  lParam)
{
    if (nCode == HCBT_ACTIVATE)
    {
        SetDlgItemText((HWND)wParam, IDOK, L"确定英文");
        SetDlgItemText((HWND)wParam, IDCANCEL, L"取消英文");
        UnhookWindowsHookEx(hHook);
    }
    return 0;
}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmsgDlg dialog



CmsgDlg::CmsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MSG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_CBN_SELCHANGE(IDC_COMBO1, &CmsgDlg::OnCbnSelchangeCombo1)
    ON_BN_CLICKED(IDC_BUTTON2, &CmsgDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &CmsgDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CmsgDlg message handlers

BOOL CmsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CmsgDlg::PreTranslateMessage(MSG* pMsg)
{
    // TODO: Add your specialized code here and/or call the base class
    //if (HIWORD(pMsg->wParam)== CBN_SELCHANGE )
    //{
    //    CBN_SELCHANGE;
    //    CWnd::FromHandle(pMsg->hwnd);
    //    CString str;
    //    GetClassName(pMsg->hwnd, str.GetBuffer(256), 256);
    //    if (str == _T("CCombox"))
    //    {
    //        int a = 10;
    //    }
    //    CPoint point(LOWORD(pMsg->lParam), HIWORD(pMsg->lParam));
    //    OnMouseMove(0, point);
    //}
    return CDialog::PreTranslateMessage(pMsg);
}


void CmsgDlg::OnCbnSelchangeCombo1()
{
 
  
}

  
LRESULT CmsgDlg::WindowProc(UINT message, WPARAM  wParam, LPARAM  lParam)
{

    MSG* msg = (MSG*)lParam;
    msg->message == WM_COMMAND;
    //msg->hwnd == HWND of dialog
    if (HIWORD(wParam) == CBN_SELCHANGE)
    {
        int id = LOWORD(wParam);
        
        CWnd *w = GetDlgItem(id);
        CString str;
        GetClassName(w->GetSafeHwnd(), str.GetBuffer(256), 256);
        if (_T("ComboBox") == str)
        {
            CComboBox *box = (CComboBox*)GetDlgItem(id);
            box->ResetContent();
            box->AddString(_T("yes I do"));
        }
         int a = 0;
     }
   
    return CDialogEx::WindowProc(message, wParam, lParam);

}

void CmsgDlg::OnBnClickedButton2()
{
    MessageBoxEx(NULL, L"This is an English MessageBox!", L"Alert", MB_OKCANCEL, MAKELANGID(LANG_ENGLISH, SUBLANG_BENGALI_INDIA));
}


void CmsgDlg::OnBnClickedButton1()
{
    //hHook = SetWindowsHookEx(WH_CBT, (HOOKPROC)CBTHookProc, NULL, GetCurrentThreadId());
    MessageBoxEx(NULL, L"This is an English MessageBox!", L"Alert", MB_OKCANCEL, MAKELANGID(LANG_FRENCH, SUBLANG_FRENCH_BELGIAN));
    CString src_path = _T("D:/Git/MFC/Dump");
    CString dest_path = _T("D:/Git/MFC/msg");
    
    //CopyDirectory(src_path, dest_path);

    SHFILEOPSTRUCT   sfo;

 
}

BOOL CmsgDlg::CopyDirectory(CString strSrcPath,CString strDestPath)
 {
     CFileFind m_sFileFind;
     if (strSrcPath.IsEmpty())
     {
         OutputDebugString(_T("源文件名为空，无法进行拷贝!"));
         return FALSE;
     }
     if (!m_sFileFind.FindFile(strDestPath))
     {
         CreateDirectory(strDestPath, NULL);//创建目标文件夹
     }
     CFileFind finder;
     CString path;
     path.Format(_T("%s/*.*"), strSrcPath);
     //AfxMessageBox(path);
     BOOL bWorking = finder.FindFile(path);
     while (bWorking)
     {
         bWorking = finder.FindNextFile();
         //AfxMessageBox(finder.GetFileName());
         if (finder.IsDirectory() && !finder.IsDots())//是文件夹 而且 名称不含 . 或 ..  
         {
             CopyDirectory(finder.GetFilePath(), strDestPath + "/" + finder.GetFileName());//递归创建文件夹+"/"+finder.GetFileName()  
         }
         else
         {//是文件，则直接复制
          //AfxMessageBox("复制文件"+finder.GetFilePath());//+finder.GetFileName()  
             CopyFile(finder.GetFilePath(), strDestPath + "/" + finder.GetFileName(), FALSE);
         }
     }

     return TRUE;
 }
 


