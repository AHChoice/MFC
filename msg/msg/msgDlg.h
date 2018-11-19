
// msgDlg.h : header file
//

#pragma once


// CmsgDlg dialog
class CmsgDlg : public CDialogEx
{
// Construction
public:
	CmsgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MSG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    LRESULT WindowProc(UINT message, WPARAM  wParam, LPARAM  lParam);
	DECLARE_MESSAGE_MAP()
    afx_msg void OnCbnSelchangeCombo1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton1();
};
