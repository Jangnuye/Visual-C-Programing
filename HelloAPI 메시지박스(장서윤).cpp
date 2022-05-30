#include <windows.h>

#define ID_OK_BTN	1000  
#define ID_HAKNYEON_BTN 2000 
#define ID_KWAMOK_BTN 3000
#define ID_CALL_BTN 4000



HINSTANCE g_hInst; //�������� ����	
LPCTSTR lpszClass = L"HelloAPI";//���� �����츦 ���� Ŭ���� �̸�	
LPCTSTR ChildClassName = L"ChildWin";//���ϵ� ������ Ŭ���� �̸�


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
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); ; //��� Ŀ�� 
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); ; //��� ������ 	
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass; //Ŭ���� �̸�	
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);     //���������� Ŭ���� ���	

	WndClass.lpfnWndProc = ChildWndProc;      //���ϵ� ������ ���ν���
	WndClass.lpszClassName = ChildClassName; //���ϵ� ������ Ŭ�����̸�
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass,			//������Ŭ���� �̸�
		L"Visual C++ ���α׷���",			    //������Ÿ��Ʋ
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,   //�����콺Ÿ��
		200, 200,		//�����찡 ���϶� X Y��ǥ
		600, 600,		//�������� ���� ����				
		(HWND)NULL,		//�θ������� �ڵ�
		(HMENU)NULL,		//�����찡 ������ �޴��ڵ�
		hInstance,		//�ν��Ͻ��ڵ�
		NULL);			//������ ������

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
	LPCTSTR text = L"202134-153597 �弭��";
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
			ChildClassName,     	// ���ϵ� ������ Ŭ���� �̸� 
			L"��������",            	// ������ Ÿ��Ʋ 
			WS_OVERLAPPEDWINDOW | WS_CHILD,  // ������  ��Ÿ�� 
			150,       		// ������ ���� �� x ��ǥ 
			150,       		// ������ ���� �� y ��ǥ 
			260,       		// ������ ��
			200,       		// ������ ����
			hWnd,         		// �θ� ������
			(HMENU)1000,        	// ���ϵ� ������ID 
			g_hInst,           	// �ν��Ͻ� �ڵ� 
			(LPVOID)NULL);      	// ������ ������			

		ShowWindow(hChildWnd, SW_SHOW);

		hChildWnd = CreateWindow(
			L"button",        	// ������ Ŭ���� �̸� 
			L"�г�",			// ������ Ÿ��Ʋ 
			WS_CHILD | WS_VISIBLE, 	// ������ ��Ÿ�� 
			70,       		// ������ ���� �� x ��ǥ 
			400,       		// ������ ���� �� y ��ǥ 
			100,       		// ������ ��
			30,       		// ������ ����
			hWnd,         		// �θ� ������
			(HMENU)ID_HAKNYEON_BTN, // ��Ʈ�� ID
			g_hInst,           	// �ν��Ͻ� �ڵ� 
			(LPVOID)NULL);      	// ������ ������

		hChildWnd = CreateWindow(
			L"button",        	// ������ Ŭ���� �̸� 
			L"����",			// ������ Ÿ��Ʋ 
			WS_CHILD | WS_VISIBLE, 	// ������ ��Ÿ�� 
			250,       		// ������ ���� �� x ��ǥ 
			400,       		// ������ ���� �� y ��ǥ 
			100,       		// ������ ��
			30,       		// ������ ����
			hWnd,         		// �θ� ������
			(HMENU)ID_KWAMOK_BTN,   	// ��Ʈ�� ID
			g_hInst,           	// �ν��Ͻ� �ڵ� 
			(LPVOID)NULL);      	// ������ ������

		if (!hChildWnd) 	return -1;
		return 0;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_HAKNYEON_BTN)
		{
			MessageBox(hWnd, L"2�г�", L"�г�", MB_OK);
		}

		if (LOWORD(wParam) == ID_KWAMOK_BTN)
		{
			MessageBox(hWnd, L"Visual C++", L"����", MB_OK);
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
	LPCTSTR text = L"������������";
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
			L"button",        	// ������ Ŭ���� �̸� 
			L"��ȭ",			// ������ Ÿ��Ʋ 
			WS_CHILD | WS_VISIBLE, 	// ������ ��Ÿ�� 
			50,       		// ������ ���� �� x ��ǥ		
			100,       		// ������ ���� �� y ��ǥ 
			100,       		// ������ ��
			30,       		// ������ ����
			hWnd,         		// �θ� ������
			(HMENU)ID_CALL_BTN,   	// ��Ʈ�� ID
			g_hInst,           	// �ν��Ͻ� �ڵ� 
			(LPVOID)NULL);      	// ������ ������

		if (!hChildWnd) 	return -1;
		return 0;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_CALL_BTN)
		{
			MessageBox(hWnd, L"02-8400-725", L"������������", MB_OK);
		}
		return 0;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
