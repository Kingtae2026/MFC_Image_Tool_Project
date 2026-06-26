
// ImageToolDoc.cpp : CImageToolDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageTool.h"
#endif

#include "GetEndin.h"
#include "GetSmoothing.h"
#include "CGetEndinDlg.h"
#include "GetStretching.h"
#include "CGammaCorrectionDlg.h"	
#include "Gammacorrection.h"
#include "CGreyTransformDig.h"
#include "GreyTransform.h"
#include "CDivdConstDlg.h"
#include "DivdConst.h"	
#include "CMultiConstDlg.h"
#include "MultiConst.h"
#include "CSubConstDlg.h"
#include "SubConst.h"
#include "CAddConstDlg.h"
#include "AddConst.h"
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "InverseImage.h"
#include "CHistogramDlg.h"
#include "GetHistogram.h"

#define CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)  \
	IppByteImage img;  \
	IppDibToImage(m_Dib, img);

#define CONVERT_BYTEIMAGE_TO_DIB(img, dib)  \
	IppDib dib; \
	IppImageToDib(img, dib);

#include "ImageToolDoc.h"
#include "FileNewDlg.h"
#include "ImageToolSecChk.h"
#include "ImageToolSecChkDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_SEC_CHK, &CImageToolDoc::OnSecChk)
	ON_COMMAND(ID_INVERSE_IMAGE, &CImageToolDoc::OnInverseImage)
	ON_UPDATE_COMMAND_UI(ID_INVERSE_IMAGE, &CImageToolDoc::OnUpdateInverseImage)
	ON_COMMAND(ID_ADD_CONST, &CImageToolDoc::OnAddConst)
	ON_UPDATE_COMMAND_UI(ID_ADD_CONST, &CImageToolDoc::OnUpdateAddConst)
	ON_COMMAND(ID_SUB_CONST, &CImageToolDoc::OnSubConst)
	ON_UPDATE_COMMAND_UI(ID_SUB_CONST, &CImageToolDoc::OnUpdateSubConst)
	ON_COMMAND(ID_MULTI_CONST, &CImageToolDoc::OnMultiConst)
	ON_UPDATE_COMMAND_UI(ID_MULTI_CONST, &CImageToolDoc::OnUpdateMultiConst)
	ON_COMMAND(ID_DIVD_CONST, &CImageToolDoc::OnDivdConst)
	ON_UPDATE_COMMAND_UI(ID_DIVD_CONST, &CImageToolDoc::OnUpdateDivdConst)
	ON_COMMAND(ID_GREY_TRANSFORM, &CImageToolDoc::OnGreyTransform)
	ON_UPDATE_COMMAND_UI(ID_GREY_TRANSFORM, &CImageToolDoc::OnUpdateGreyTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageToolDoc::OnGammaCorrection)
	ON_UPDATE_COMMAND_UI(ID_GAMMA_CORRECTION, &CImageToolDoc::OnUpdateGammaCorrection)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnUpdateViewHistogram)
	ON_COMMAND(IDD_GET_STRETCHING, &CImageToolDoc::OnGetStretching)
	ON_UPDATE_COMMAND_UI(IDD_GET_STRETCHING, &CImageToolDoc::OnUpdateGetStretching)
	ON_COMMAND(ID_GET_ENDIN, &CImageToolDoc::OnGetEndin)
	ON_UPDATE_COMMAND_UI(ID_GET_ENDIN, &CImageToolDoc::OnUpdateGetEndin)
	ON_COMMAND(ID_GET_SMOOTHING, &CImageToolDoc::OnGetSmoothing)
	ON_UPDATE_COMMAND_UI(ID_GET_SMOOTHING, &CImageToolDoc::OnUpdateGetSmoothing)
END_MESSAGE_MAP()


// CImageToolDoc 생성/소멸

CImageToolDoc::CImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL ret = TRUE;

	if (theApp.m_pNewDib == NULL)
	{
		CFileNewDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			if (dlg.m_nType == 0) // 그레이스케일 비트맵
				ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
			else // 트루컬러 비트맵
				ret = m_Dib.CreateRgbBitmap(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		m_Dib = *(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return ret;
}




// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageToolDoc 진단

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc 명령


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	BOOL res = m_Dib.Load(CT2A(lpszPathName));
	if (res)
		AfxPrintInfo(_T("[파일 열기] 파일 경로: %s, 가로 크기: %d픽셀, 세로 크기: %d픽셀, 색상수: %d"),
			lpszPathName, m_Dib.GetWidth(), m_Dib.GetHeight(), 0x01 << m_Dib.GetBitCount());

	return res;
}


BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return m_Dib.Save(CT2A(lpszPathName));
}


void CImageToolDoc::OnWindowDuplicate()
{
	AfxNewBitmap(m_Dib);
}


void CImageToolDoc::OnEditCopy()
{
	if (m_Dib.IsValid())
		m_Dib.CopyToClipboard();
}


void CImageToolDoc::OnSecChk()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageToolSecChkDlg dlg;
	int result = 0;
	if (dlg.DoModal() == IDOK)
	{
		result = ImageToolSecChk(dlg.m_nSecChk);
	}

	if (result == 0)
		AfxMessageBox(_T("실패(x): 보안코드 불일치"), MB_ICONERROR);
	else
		AfxMessageBox(_T("성공(o): 보안코드 일치"), MB_ICONINFORMATION);
}


void CImageToolDoc::OnInverseImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		InverseImage(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[반전] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnUpdateInverseImage(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnAddConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CAddConstDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		AddConst(img, dlg.m_nAddConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 증가] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_nAddConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateAddConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnSubConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSubConstDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		SubConst(img, dlg.m_nSubConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 감소] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_nSubConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateSubConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnMultiConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMultiConstDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		MultiConst(img, dlg.m_dMultiConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[영상 대비 증가] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_dMultiConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateMultiConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnDivdConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDivdConstDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		DivdConst(img, dlg.m_dDivdConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[영상 대비 감소] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_dDivdConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateDivdConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGreyTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGreyTransformDig dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		GreyTransform(img, dlg.m_dCoefA, dlg.m_dCoefB);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[선형 영상 변환] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_dCoefA, dlg.m_dCoefB);
		AfxNewBitmap(dib);
	}

}


void CImageToolDoc::OnUpdateGreyTransform(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGammaCorrectionDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		GammaCorrection(img, dlg.m_dGammaCorr);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[감마 보정] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_dGammaCorr);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateGammaCorrection(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	dlg.m_nMin = GetMinGrayValue(img);
	dlg.m_nMax = GetMaxGrayValue(img);
	dlg.m_fAvgValue = GetAvgValue(img);
	dlg.m_fStdValue = GetStdValue(img, dlg.m_fAvgValue);

	AfxPrintInfo(_T("[히스토그램] 입력 영상 : %s, 최소값: %d, 최대값: %d, 평균값: %.1f, 표준편차: %.1f"), GetTitle(),dlg.m_nMin, dlg.m_nMax, dlg.m_fAvgValue, dlg.m_fStdValue);
	dlg.DoModal();
}


void CImageToolDoc::OnUpdateViewHistogram(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGetStretching()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	dlg.m_nMin = GetMin(img);
	dlg.m_nMax = GetMax(img);
	GetStretching(img, dlg.m_nMax, dlg.m_nMin);

	CONVERT_BYTEIMAGE_TO_DIB(img, dib);
	
	
	AfxNewBitmap(dib);
	AfxPrintInfo(_T("[스트레칭] 입력 영상: %s "), GetTitle());
	
}


void CImageToolDoc::OnUpdateGetStretching(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGetEndin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGetEndinDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		GetEndin(img, dlg.m_dHigh, dlg.m_dLow);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[앤드 - 인 탐색] 입력 영상: %s, High: %d, Low: %d"), GetTitle(), dlg.m_dHigh, dlg.m_dLow);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateGetEndin(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGetSmoothing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double histo[256] = { 0,0 };
	double sum[256] = { 0,0 };
	double smooth[256] = { 0,0 };
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	GetHisto(img, histo);
	GetSum(histo, sum);
	GetSmooth(img, sum, smooth);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib);
	

	AfxPrintInfo(_T("[히스토그램 평활화] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnUpdateGetSmoothing(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}
