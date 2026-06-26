#pragma once
#include "afxdialogex.h"


// CSubConstDlg 대화 상자

class CSubConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubConstDlg)

public:
	CSubConstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSubConstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUB_CONST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nSubConst;
	virtual BOOL OnInitDialog();
};
