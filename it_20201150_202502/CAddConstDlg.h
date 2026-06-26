#pragma once
#include "afxdialogex.h"


// CAddConstDlg 대화 상자

class CAddConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddConstDlg)

public:
	CAddConstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAddConstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nAddConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeAddconstEdit();
	afx_msg void OnEnChangeSubconstEdit();
};
