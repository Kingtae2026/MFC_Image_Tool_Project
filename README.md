# MFC 기반 디지털 이미지 처리 프로그램

> Visual C++ MFC를 활용한 Windows 네이티브 디지털 영상 처리 도구 | 1인 개발

---

## 개요

MFC SDI(Single Document Interface) 구조 기반의 이미지 처리 프로그램입니다.  
BMP 이미지를 불러와 화소 단위 밝기·대비 조정, 반전, 히스토그램 분석, 공간 필터링 등 다양한 영상 처리를 실시간으로 수행합니다.

- **개발 기간**: 2025년 02학기
- **개발 인원**: 1인 (단독 개발)
- **개발 환경**: Visual Studio 2022, Windows 11, C++ / MFC

---

## 주요 구현 내용

### 1. MDI 문서/뷰 구조 설계

- `CImageToolDoc`(데이터 관리) · `CImageToolView`(렌더링)를 분리하여 Document/View 패턴 적용
- 다중 이미지 창 동시 관리 구현

### 2. 화소값 기반 밝기·대비 처리

- `AddConst` · `SubConst`(밝기 증감), `MultiConst` · `DivdConst`(대비 증감) 함수 개발
- `limit()` 함수로 0~255 범위 클램핑 처리

### 3. 이미지 반전

- `InverseImage` 함수로 각 픽셀에 `255 - pixel` 연산을 적용하는 그레이스케일 반전 처리

![영상 반전](docs/screenshots/image_inverse.png)

### 4. DIB ↔ ByteImage 변환 처리

- `CONVERT_DIB_TO_BYTEIMAGE` · `CONVERT_BYTEIMAGE_TO_DIB` 매크로 정의
- 렌더링용 DIB 객체와 처리용 ByteImage 간 일관된 변환 구조 설계

### 5. MFC 다이얼로그 및 DDX/DDV 연동

- 각 처리 기능에 대응하는 입력 다이얼로그 구현
- `DDX_Text` · `DDV_MinMaxInt`로 유효성 검사 자동화

### 6. 줌 기능 및 스크롤 뷰

- 1x ~ 4x 배율 확대 기능 구현
- 마우스 이동 시 상태바에 좌표·이미지 정보 실시간 표시

| 2배 확대 | 4배 확대 |
|----------|----------|
| ![2x](docs/screenshots/zoom_2x.png) | ![4x](docs/screenshots/zoom_4x.png) |

### 7. 파일 기반 보안 코드 검증 시스템

- `.sec` 파일에서 인코딩된 코드를 읽어 오프셋 역산 후 사용자 입력값과 비교하는 라이선스 검증 기능 개발

---

## 스크린샷

### 메인 화면
![메인 화면](docs/screenshots/main_screen.png)

### 영상처리 메뉴
![영상처리 메뉴](docs/screenshots/image_processing_menu.png)

### 보기 메뉴
![보기 메뉴](docs/screenshots/view_menu.png)

### 영상처리 기능 전체
![영상처리 기능들](docs/screenshots/image_processing_features.png)

---

## 프로젝트 구조

```
it_20201150_202502/
├── ImageTool.sln              # Visual Studio 솔루션 파일
├── ImageTool.vcxproj          # 프로젝트 파일
│
├── ImageTool.cpp / .h         # 애플리케이션 진입점
├── ImageToolDoc.cpp / .h      # Document 클래스 — BMP 데이터 관리
├── ImageToolView.cpp / .h     # View 클래스 — 화면 렌더링
├── MainFrm.cpp / .h           # 메인 프레임 (메뉴·툴바)
│
├── AddConst / SubConst        # 밝기 증감
├── MultiConst / DivdConst     # 대비 증감
├── InverseImage               # 영상 반전
├── GammaCorrection            # 감마 보정
├── GreyTransform              # 그레이스케일 변환
├── GetHistogram / GetStretching  # 히스토그램 분석·스트레칭
├── GetSmoothing               # 평활화 필터
├── GetEndin                   # 에지 검출
│
├── C*Dlg.cpp / .h             # 각 기능별 입력 다이얼로그 (DDX/DDV)
├── ImageToolSecChk.cpp / .h   # 보안 코드 검증
├── IppImage/                  # IPP 이미지 라이브러리
└── graybmp/                   # 테스트용 그레이스케일 BMP
```

---

## 빌드 방법

1. `it_20201150_202502/ImageTool.sln` 을 Visual Studio 2019 이상으로 열기
2. **빌드 → 솔루션 빌드** (Ctrl+Shift+B)
3. `Debug/ImageTool.exe` 실행

> **요구 사항**: Windows 10/11, Visual Studio 2019+, MFC 컴포넌트 설치 필요
