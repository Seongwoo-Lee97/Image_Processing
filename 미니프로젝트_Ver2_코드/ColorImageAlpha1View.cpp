﻿
// ColorImageAlpha1View.cpp: CColorImageAlpha1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ColorImageAlpha1.h"
#endif

#include "ColorImageAlpha1Doc.h"
#include "ColorImageAlpha1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorImageAlpha1View

IMPLEMENT_DYNCREATE(CColorImageAlpha1View, CView)

BEGIN_MESSAGE_MAP(CColorImageAlpha1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_EQUAL_IMAGE, &CColorImageAlpha1View::OnEqualImage)
	ON_COMMAND(IDM_GRAY_SCALE, &CColorImageAlpha1View::OnGrayScale)
	ON_COMMAND(IDM_CHANGE_SATUR, &CColorImageAlpha1View::OnChangeSatur)
	ON_COMMAND(IDM_PICK_ORANGE, &CColorImageAlpha1View::OnPickOrange)
	ON_COMMAND(IDM_EMBOSS, &CColorImageAlpha1View::OnEmboss)
	ON_COMMAND(IDM_EMBOSS_HSI, &CColorImageAlpha1View::OnEmbossHsi)
	ON_COMMAND(IDM_ADD_IMAGE, &CColorImageAlpha1View::OnAddImage)
	ON_COMMAND(IDM_REVERSE_IMAGE, &CColorImageAlpha1View::OnReverseImage)
	ON_COMMAND(IDM_DARK_IMAGE, &CColorImageAlpha1View::OnDarkImage)
	ON_COMMAND(IDM_BLACK_IMAGE, &CColorImageAlpha1View::OnBlackImage)
	ON_COMMAND(IDM_GAMMA_IMAGE, &CColorImageAlpha1View::OnGammaImage)
	ON_COMMAND(IDM_PARABOL_CAP, &CColorImageAlpha1View::OnParabolCap)
	ON_COMMAND(IDM_PARABOL_CUP, &CColorImageAlpha1View::OnParabolCup)
	ON_COMMAND(IDM_AND_IMAGE, &CColorImageAlpha1View::OnAndImage)
	ON_COMMAND(IDM_OR_IMAGE, &CColorImageAlpha1View::OnOrImage)
	ON_COMMAND(IDM_XOR_IMAGE, &CColorImageAlpha1View::OnXorImage)
	ON_COMMAND(IDM_ZOOM_OUT, &CColorImageAlpha1View::OnZoomOut)
	ON_COMMAND(IDM_ZOOM_IN, &CColorImageAlpha1View::OnZoomIn)
	ON_COMMAND(IDM_ZOOM_IN2, &CColorImageAlpha1View::OnZoomIn2)
	ON_COMMAND(IDM_ROTATE, &CColorImageAlpha1View::OnRotate)
	ON_COMMAND(IDM_ROTATE2, &CColorImageAlpha1View::OnRotate2)
	ON_COMMAND(IDM_HISTO_STRETCH, &CColorImageAlpha1View::OnHistoStretch)
	ON_COMMAND(IDM_END_IN, &CColorImageAlpha1View::OnEndIn)
	ON_COMMAND(IDM_HISTO_EQUAL, &CColorImageAlpha1View::OnHistoEqual)
	ON_COMMAND(IDM_BLUR, &CColorImageAlpha1View::OnBlur)
	ON_COMMAND(IDM_BLUR_HSI, &CColorImageAlpha1View::OnBlurHsi)
	ON_COMMAND(IDM_SHARP, &CColorImageAlpha1View::OnSharp)
	ON_COMMAND(IDM_SHARP_HSI, &CColorImageAlpha1View::OnSharpHsi)
	ON_COMMAND(IDM_EDGE1, &CColorImageAlpha1View::OnEdge1)
	ON_COMMAND(IDM_EDGE2, &CColorImageAlpha1View::OnEdge2)
	ON_COMMAND(IDM_EDGE_HSI, &CColorImageAlpha1View::OnEdgeHsi)
	ON_COMMAND(IDM_EDGE2_HSI, &CColorImageAlpha1View::OnEdge2Hsi)
	ON_COMMAND(IDM_LAPLACIAN1, &CColorImageAlpha1View::OnLaplacian1)
	ON_COMMAND(IDM_LAPLACIAN1_HSI, &CColorImageAlpha1View::OnLaplacian1Hsi)
	ON_COMMAND(IDM_LAPLACIAN2, &CColorImageAlpha1View::OnLaplacian2)
	ON_COMMAND(IDM_LAPLACIAN2_HSI, &CColorImageAlpha1View::OnLaplacian2Hsi)
	ON_COMMAND(IDM_LAPLACIAN3, &CColorImageAlpha1View::OnLaplacian3)
	ON_COMMAND(IDM_LAPLACIAN3_HSI, &CColorImageAlpha1View::OnLaplacian3Hsi)
	ON_COMMAND(IDM_GAUSIANS, &CColorImageAlpha1View::OnGausians)
	ON_COMMAND(IDM_GAUSIANS_HSI, &CColorImageAlpha1View::OnGausiansHsi)
	ON_COMMAND(IDM_PREWITT1, &CColorImageAlpha1View::OnPrewitt1)
	ON_COMMAND(IDM_PREWITT1_HSI, &CColorImageAlpha1View::OnPrewitt1Hsi)
	ON_COMMAND(IDM_PREWITT2, &CColorImageAlpha1View::OnPrewitt2)
	ON_COMMAND(IDM_PREWITT2_HSI, &CColorImageAlpha1View::OnPrewitt2Hsi)
	ON_COMMAND(IDM_SOBEL1, &CColorImageAlpha1View::OnSobel1)
	ON_COMMAND(IDM_SOBEL1_HSI, &CColorImageAlpha1View::OnSobel1Hsi)
	ON_COMMAND(IDM_SOBEL2, &CColorImageAlpha1View::OnSobel2)
	ON_COMMAND(IDM_SOBEL2_HSI, &CColorImageAlpha1View::OnSobel2Hsi)
END_MESSAGE_MAP()

// CColorImageAlpha1View 생성/소멸

CColorImageAlpha1View::CColorImageAlpha1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CColorImageAlpha1View::~CColorImageAlpha1View()
{
}

BOOL CColorImageAlpha1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CColorImageAlpha1View 그리기

void CColorImageAlpha1View::OnDraw(CDC* pDC)
{
	//CColorImageAlpha1Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	//// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//int R, G, B;
	//for (int i=0; i<pDoc->m_inH; i++)
	//	for (int k = 0; k < pDoc->m_inW; k++) {
	//		R = pDoc->m_inImageR[i][k];
	//		G = pDoc->m_inImageG[i][k];
	//		B = pDoc->m_inImageB[i][k];
	//		pDC->SetPixel(k + 5, i + 5, RGB(R, G, B));
	//	}

	//for (int i = 0; i < pDoc->m_outH; i++)
	//	for (int k = 0; k < pDoc->m_outW; k++) {
	//		R = pDoc->m_outImageR[i][k];
	//		G = pDoc->m_outImageG[i][k];
	//		B = pDoc->m_outImageB[i][k];
	//		pDC->SetPixel(pDoc->m_inW + k + 5 + 5, i + 5, RGB(R, G, B));
	//	}

		///////////////
		///////////////
		// 화면 크기 조절
		/////////////
		///////////////

		///////////////////
		/// ** 더블 버퍼링 **
		///////////////////
		CColorImageAlpha1Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		/////////////////////
		/// 성능 개선을 위한 더블 버퍼링 
		////////////////////
		int i, k;
		unsigned char R, G, B;
		// 메모리 DC 선언
		CDC memDC;
		CBitmap* pOldBitmap, bitmap;

		// 화면 DC와 호환되는 메모리 DC 객체를 생성
		memDC.CreateCompatibleDC(pDC);

		// 마찬가지로 화면 DC와 호환되는 Bitmap 생성
		bitmap.CreateCompatibleBitmap(pDC, pDoc->m_inW, pDoc->m_inH);

		pOldBitmap = memDC.SelectObject(&bitmap);
		memDC.PatBlt(0, 0, pDoc->m_inW, pDoc->m_inH, WHITENESS); // 흰색으로 초기화


		// 출력 영상의 크기를 자동 조절
		double MAXSIZE = 600;  // 필요시 실 모니터 또는 화면의 해상도에 따라서 변경 가능!
		int inH = pDoc->m_inH;
		int inW = pDoc->m_inW;
		double hop = 1.0; // 기본

		if (inH > MAXSIZE || inW > MAXSIZE) {
			// hop을 새로 계산.
			if (inW > inH)
				hop = (inW / MAXSIZE);
			else
				hop = (inH / MAXSIZE);

			inW = (int)(inW / hop);
			inH = (int)(inH / hop);
		}

		// 메모리 DC에 그리기
		for (i = 0; i < inH; i++) {
			for (k = 0; k < inW; k++) {
				R = pDoc->m_inImageR[(int)(i * hop)][(int)(k * hop)];
				G = pDoc->m_inImageG[(int)(i * hop)][(int)(k * hop)];
				B = pDoc->m_inImageB[(int)(i * hop)][(int)(k * hop)];
				memDC.SetPixel(k, i, RGB(R, G, B));
			}
		}

		// 메모리 DC를 화면 DC에 고속 복사
		pDC->BitBlt(5, 5, pDoc->m_inW, pDoc->m_inH, &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(pOldBitmap);
		memDC.DeleteDC();
		bitmap.DeleteObject();

		///////////////////

		// 화면 DC와 호환되는 메모리 DC 객체를 생성
		memDC.CreateCompatibleDC(pDC);

		// 마찬가지로 화면 DC와 호환되는 Bitmap 생성
		bitmap.CreateCompatibleBitmap(pDC, pDoc->m_outW, pDoc->m_outH);

		pOldBitmap = memDC.SelectObject(&bitmap);
		memDC.PatBlt(0, 0, pDoc->m_outW, pDoc->m_outH, WHITENESS); // 흰색으로 초기화

		int outH = pDoc->m_outH;
		int outW = pDoc->m_outW;
		hop = 1.0; // 기본

		if (outH > MAXSIZE || outW > MAXSIZE) {
			// hop을 새로 계산.
			if (outW > outH)
				hop = (outW / MAXSIZE);
			else
				hop = (outH / MAXSIZE);

			outW = (int)(outW / hop);
			outH = (int)(outH / hop);
		}

		// 메모리 DC에 그리기
		for (i = 0; i < outH; i++) {
			for (k = 0; k < outW; k++) {
				R = pDoc->m_outImageR[(int)(i * hop)][(int)(k * hop)];
				G = pDoc->m_outImageG[(int)(i * hop)][(int)(k * hop)];
				B = pDoc->m_outImageB[(int)(i * hop)][(int)(k * hop)];
				memDC.SetPixel(k, i, RGB(R, G, B));
			}
		}
		// 메모리 DC를 화면 DC에 고속 복사
		pDC->BitBlt(inW + 10, 5, pDoc->m_outW, pDoc->m_outH, &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(pOldBitmap);
		memDC.DeleteDC();
		bitmap.DeleteObject();
	}


// CColorImageAlpha1View 인쇄

BOOL CColorImageAlpha1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CColorImageAlpha1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CColorImageAlpha1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CColorImageAlpha1View 진단

#ifdef _DEBUG
void CColorImageAlpha1View::AssertValid() const
{
	CView::AssertValid();
}

void CColorImageAlpha1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorImageAlpha1Doc* CColorImageAlpha1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorImageAlpha1Doc)));
	return (CColorImageAlpha1Doc*)m_pDocument;
}
#endif //_DEBUG


// CColorImageAlpha1View 메시지 처리기



void CColorImageAlpha1View::OnEqualImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEqualImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnGrayScale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayScale();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnChangeSatur()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnChangeSatur();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnPickOrange()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPickOrange();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEmboss()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmboss();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEmbossHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossHsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnAddImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAddImage();
	Invalidate(TRUE);
}

void CColorImageAlpha1View::OnDarkImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDarkImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnReverseImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnReverseImage();
	Invalidate(TRUE);
}



void CColorImageAlpha1View::OnBlackImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlackImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnGammaImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnParabolCap()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnParabolCap();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnParabolCup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnParabolCup();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnAndImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnOrImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnXorImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnXorImage();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnZoomOut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomOut();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnZoomIn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomIn();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnZoomIn2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnZoomIn2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnRotate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnRotate2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEndIn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndIn();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnBlur()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlur();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnBlurHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurHsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharp();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSharpHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpHsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEdge1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdge1();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEdge2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdge2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEdgeHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdgeHsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnEdge2Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEdge2Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian1();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian1Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian1Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian2Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian2Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian3();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnLaplacian3Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian3Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnGausians()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGausians();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnGausiansHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGausiansHsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnPrewitt1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPrewitt1();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnPrewitt1Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPrewitt1Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnPrewitt2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPrewitt2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnPrewitt2Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnPrewitt2Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSobel1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSobel1();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSobel1Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSobel1Hsi();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSobel2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSobel2();
	Invalidate(TRUE);
}


void CColorImageAlpha1View::OnSobel2Hsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorImageAlpha1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSobel2Hsi();
	Invalidate(TRUE);
}
