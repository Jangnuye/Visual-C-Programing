#include <windows.h>

#define ID_OK_BTN	1000  
#define ID_HAKNYEON_BTN 2000 
#define ID_KWAMOK_BTN 3000
#define ID_CALL_BTN 4000



HINSTANCE g_hInst; //전역변수 설정	
LPCTSTR lpszClass = L"HelloAPI";//메인 윈도우를 위한 클래스 이름	
LPCTSTR ChildClassName = L"ChildWin";//차일드 윈도우 클래스 이름


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; //extra class memory
	WndClass.cbWndExtra = 0; //extra window memory
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //배경
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); ; //사용 커서 
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); ; //사용 아이콘 	
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass; //클래스 이름	
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);     //메인윈도우 클래스 등록	

	WndClass.lpfnWndProc = ChildWndProc;      //차일드 윈도우 프로시저
	WndClass.lpszClassName = ChildClassName; //차일드 윈도우 클래스이름
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass,			//윈도우클래스 이름
		L"Visual C++ 프로그래밍",			    //윈도우타이틀
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,   //윈도우스타일
		200, 200,		//윈도우가 보일때 X Y좌표
		600, 600,		//윈도우의 폭과 높이				
		(HWND)NULL,		//부모윈도우 핸들
		(HMENU)NULL,		//윈도우가 가지는 메뉴핸들
		hInstance,		//인스턴스핸들
		NULL);			//여분의 데이터

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	LPCTSTR text = L"202134-153597 장서윤";
	switch (iMessage) {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, text, lstrlen(text));
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_CREATE:
	{
		HWND hChildWnd = CreateWindow(
			ChildClassName,     	// 차일드 윈도우 클래스 이름 
			L"지역대학",            	// 윈도우 타이틀 
			WS_OVERLAPPEDWINDOW | WS_CHILD,  // 윈도우  스타일 
			150,       		// 윈도우 보일 때 x 좌표 
			150,       		// 윈도우 보일 때 y 좌표 
			260,       		// 윈도우 폭
			200,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)1000,        	// 차일드 윈도우ID 
			g_hInst,           	// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터			

		ShowWindow(hChildWnd, SW_SHOW);

		hChildWnd = CreateWindow(
			L"button",        	// 윈도우 클래스 이름 
			L"학년",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			70,       		// 윈도우 보일 때 x 좌표 
			400,       		// 윈도우 보일 때 y 좌표 
			100,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_HAKNYEON_BTN, // 컨트롤 ID
			g_hInst,           	// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		hChildWnd = CreateWindow(
			L"button",        	// 윈도우 클래스 이름 
			L"과목",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			250,       		// 윈도우 보일 때 x 좌표 
			400,       		// 윈도우 보일 때 y 좌표 
			100,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_KWAMOK_BTN,   	// 컨트롤 ID
			g_hInst,           	// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd) 	return -1;
		return 0;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_HAKNYEON_BTN)
		{
			MessageBox(hWnd, L"2학년", L"학년", MB_OK);
		}

		if (LOWORD(wParam) == ID_KWAMOK_BTN)
		{
			MessageBox(hWnd, L"Visual C++", L"과목", MB_OK);
		}

		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LPCTSTR text = L"서울지역대학";
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, text, lstrlen(text));
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_CREATE:
	{
		HWND hChildWnd = CreateWindow(
			L"button",        	// 윈도우 클래스 이름 
			L"전화",			// 윈도우 타이틀 
			WS_CHILD | WS_VISIBLE, 	// 윈도우 스타일 
			50,       		// 윈도우 보일 때 x 좌표		
			100,       		// 윈도우 보일 때 y 좌표 
			100,       		// 윈도우 폭
			30,       		// 윈도우 높이
			hWnd,         		// 부모 윈도우
			(HMENU)ID_CALL_BTN,   	// 컨트롤 ID
			g_hInst,           	// 인스턴스 핸들 
			(LPVOID)NULL);      	// 여분의 데이터

		if (!hChildWnd) 	return -1;
		return 0;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_CALL_BTN)
		{
			MessageBox(hWnd, L"02-8400-725", L"서울지역대학", MB_OK);
		}
		return 0;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
