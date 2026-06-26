#pragma once
#include "afxdialogex.h"


// CGetEndinDlg 대화 상자

class CGetEndinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetEndinDlg)

public:
	CGetEndinDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGetEndinDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GET_ENDIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_dHigh;
	int m_dLow;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeGetendinHigh();
	afx_msg void OnEnChangeGetendinLow();
};
