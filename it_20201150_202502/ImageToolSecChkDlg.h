#pragma once


// CImageToolSecChkDlg 대화 상자입니다.

class CImageToolSecChkDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageToolSecChkDlg)

public:
	CImageToolSecChkDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CImageToolSecChkDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SEC_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nSecChk;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeSecChkEdit();
};
