#include "Application/WindowBase.hpp"

WindowBase::WindowBase(
    HWND window_,
    std::wstring_view captionName_,
    uint32 windowWidth_,
    uint32 windowHeight_)
    : mWindow(window_)
    , mCaption(captionName_)
    , mWindowWidth(windowWidth_)
    , mWindowHeight(windowHeight_)
    , mScreenWidth(windowWidth_)
    , mScreenHeight(windowHeight_)
{
}

WindowBase::WindowBase(
    HWND window_,
    std::wstring_view captionName_,
    uint32 windowWidth_,
    uint32 windowHeight_,
    uint32 screenWidth_,
    uint32 screenHeight_)
    : mWindow(window_)
    , mCaption(captionName_)
    , mWindowWidth(windowWidth_)
    , mWindowHeight(windowHeight_)
    , mScreenWidth(screenWidth_)
    , mScreenHeight(screenHeight_)
{
}

WindowBase::~WindowBase()
{
}

const HWND& WindowBase::GetWindow() const
{
    return mWindow;
}

std::wstring_view WindowBase::GetCaption() const
{
    return mCaption;
}

void WindowBase::SetCaption(std::wstring_view caption_)
{
    mCaption = caption_;
    SetWindowText(mWindow, mCaption.c_str());
}

const uint32& WindowBase::GetWindowWidth() const
{
    return mWindowWidth;
}

void WindowBase::SetWindowWidth(const uint32& width_)
{
    mWindowWidth = width_;
    SetWindowPos(mWindow, nullptr, 0, 0, mWindowWidth, mWindowHeight, SWP_NOMOVE | SWP_NOZORDER);
}

const uint32& WindowBase::GetWindowHeight() const
{
    return mWindowHeight;
}

void WindowBase::SetWindowHeight(const uint32& height_)
{
    mWindowHeight = height_;
    SetWindowPos(mWindow, nullptr, 0, 0, mWindowWidth, mWindowHeight, SWP_NOMOVE | SWP_NOZORDER);
}

const uint32& WindowBase::GetScreenWidth() const
{
    return mScreenWidth;
}

void WindowBase::SetScreenWidth(const uint32& width_)
{
    mScreenWidth = width_;
    SetWindowPos(mWindow, nullptr, 0, 0, mScreenWidth, mScreenHeight, SWP_NOMOVE | SWP_NOZORDER);
}

const uint32& WindowBase::GetScreenHeight() const
{
    return mScreenHeight;
}

void WindowBase::SetScreenHeight(const uint32& height_)
{
    mScreenHeight = height_;
    SetWindowPos(mWindow, nullptr, 0, 0, mScreenWidth, mScreenHeight, SWP_NOMOVE | SWP_NOZORDER);
}

void WindowBase::Initialize()
{
    WNDCLASSEX windowClass = {};
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = mProceedMessage;
    windowClass.cbClsExtra = 0L;
    windowClass.cbWndExtra = 0L;
    windowClass.hInstance = GetModuleHandle(NULL);
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = L"WindowClass";
    windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassEx(&windowClass);

    mWindow = CreateWindowEx(
        0,
        windowClass.lpszClassName,
        mCaption.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        mWindowWidth,
        mWindowHeight,
        nullptr,
        nullptr,
        windowClass.hInstance,
        this
    );

    if (!mWindow) {
        DWORD error = GetLastError();

        MessageBox(
            nullptr,
            std::format(L"Failed to create window: {}", error).c_str(),
            L"Error",
            MB_ICONERROR | MB_OK
        );
    }
}

void WindowBase::Run()
{
    ShowWindow(mWindow, SW_SHOW);
    UpdateWindow(mWindow);

    MSG message;
    while (GetMessage(&message, nullptr, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

LRESULT WindowBase::mProceedMessage(
    HWND window_,
    UINT message_,
    WPARAM wParam_,
    LPARAM lParam_
)
{
    WindowBase* pThis = nullptr;

    if (message_ == WM_NCCREATE)
    {
        // CREATESTRUCT의 lpCreateParams에 this 포인터가 들어있음
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam_);
        pThis = static_cast<WindowBase*>(pCreate->lpCreateParams);

        // 윈도우 핸들과 클래스 포인터 연결
        SetWindowLongPtr(window_, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));

        pThis->mWindow = window_;
    }
    else
    {
        // GWLP_USERDATA에서 this 포인터 가져오기
        pThis = reinterpret_cast<WindowBase*>(GetWindowLongPtr(window_, GWLP_USERDATA));
    }

    if (pThis)
    {
        return pThis->HandleMessage(WindowMessage{ message_, wParam_, lParam_ });
    }
    else
    {
        return DefWindowProc(window_, message_, wParam_, lParam_);
    }
}
