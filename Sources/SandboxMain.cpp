#include <windows.h>
#include <GL/gl.h>

// WinAPI 윈도우 핸들
HWND hWnd;
HDC hDC;
HGLRC hRC;

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

// OpenGL 초기화
void InitOpenGL()
{
    hDC = GetDC(hWnd);

    // 픽셀 포맷 설정
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);

    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);
}

// OpenGL로 삼각형 그리기
void Render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    SwapBuffers(hDC);
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPWSTR, int nCmdShow)
{
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "OpenGLWindowClass"; // 수정: 문자열을 멀티바이트 문자열로 변경

    RegisterClassEx(&wc);

    hWnd = CreateWindowEx(
        0,
        "OpenGLWindowClass", // 수정: 문자열을 멀티바이트 문자열로 변경
        "WinAPI OpenGL Triangle", // 수정: 문자열을 멀티바이트 문자열로 변경
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    InitOpenGL();

    // 메시지 루프
    MSG msg = {};
    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Render();
        }
    }

    // OpenGL context 제거
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hWnd, hDC);

    return 0;
}
