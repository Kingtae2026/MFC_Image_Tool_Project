#pragma once
#include "afxdialogex.h"


// CMultiConstDlg 대화 상자

class CMultiConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMultiConstDlg)

public:
	CMultiConstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMultiConstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTI_CONST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_dMultiConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeMulticonstEdit();
};
