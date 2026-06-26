#pragma once
#include "afxdialogex.h"


// CDivdConstDlg 대화 상자

class CDivdConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDivdConstDlg)

public:
	CDivdConstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDivdConstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIVD_CONST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_dDivdConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeDivdconstEdit();
};
