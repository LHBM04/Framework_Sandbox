#include "Definition/SandboxHeader.hpp"

#include "Application/WindowMessage.hpp"
#include "Application/WindowBase.hpp"

class TestWindow
    : public WindowBase
{
public:
    TestWindow();

    LRESULT CALLBACK HandleMessage(const WindowMessage& message_) override
    {
        switch (message_.Message)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            // Handle paint message here if needed.
            return 0;
        default:
            return DefWindowProc(GetWindow(), message_.Message, message_.WParam, message_.LParam);
        }
    }

    virtual ~TestWindow() override = default;
};

INT wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow
)
{
    TestWindow testWindow;
    testWindow.Initialize();
    testWindow.Run();
}

TestWindow::TestWindow()
    : WindowBase(
        nullptr,
        L"Test Window",
        800,
        600
    )
{
}
