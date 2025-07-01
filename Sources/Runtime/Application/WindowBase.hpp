#ifndef GUARD_WINDOWCONTEXT_HPP
#define GUARD_WINDOWCONTEXT_HPP

#include "Definition/SandboxHeader.hpp"
#include "Definition/SandboxTypes.hpp"

#include "Application/WindowMessage.hpp"

/**
 * @brief 프로젝트 내 생성되는 윈도우를 제어하는 컨텍스트를 정의합니다.
 */
class WindowBase
{
public:
    /**
     * @brief 생성자.
     *
     * @param window_ 윈도우 핸들.
     * @param captionName_ 윈도우 캡션 이름.
     * @param windowWidth_ 윈도우 너비.
     * @param windowHeight_ 윈도우 높이.
     */
    WindowBase(
        HWND window_,
        std::wstring_view captionName_,
        uint32 windowWidth_,
        uint32 windowHeight_
    );

    /**
     * @brief 생성자.
     *
     * @param window_ 윈도우 핸들.
     * @param captionName_ 윈도우 캡션 이름.
     * @param windowWidth_ 윈도우 너비.
     * @param windowHeight_ 윈도우 높이.
     * @param screenWidth_ 스크린 너비.
     * @param screenHeight_ 스크린 높이.
     */
    WindowBase(
        HWND window_,
        std::wstring_view captionName_,
        uint32 windowWidth_,
        uint32 windowHeight_,
        uint32 screenWidth_,
        uint32 screenHeight_
    );

    /**
     * @brief 소멸자.
     */
    virtual ~WindowBase();

public:
    /**
     * @brief 해당 컨텍스트의 윈도우 핸들을 반환합니다.
     *
     * @return HWND 해당 컨텍스트의 윈도우 핸들.
     */
    const HWND& GetWindow() const;

    /**
     * @brief 해당 컨텍스트의 캡션을 반환합니다.
     *
     * @return std::wstring_view 해당 컨텍스트의 캡션.
     */
    std::wstring_view GetCaption() const;

    /**
     * @brief 해당 컨텍스트의 캡션을 지정한 캡션으로 설정합니다.
     *
     * @param caption_ 지정할 캡션.
     */
    void SetCaption(std::wstring_view caption_);

    /**
     * @brief 현재 컨텍스트의 윈도우 너비를 반환합니다.
     *
     * @return uint32 현재 컨텍스트의 윈도우 너비.
     */
    const uint32& GetWindowWidth() const;

    /**
     * @brief 현재 컨텍스트의 윈도우 너비를 지정한 값으로 설정합니다.
     *
     * @param width_ 지정할 값.
     */
    void SetWindowWidth(const uint32& width_);

    /**
     * @brief 현재 컨텍스트의 윈도우 높이를 반환합니다.
     *
     * @return uint32 현재 컨텍스트의 윈도우 높이.
     */
    const uint32& GetWindowHeight() const;

    /**
     * @brief 현재 컨텍스트의 윈도우 높이를 지정한 값으로 설정합니다.
     *
     * @param height_ 지정할 값.
     */
    void SetWindowHeight(const uint32& height_);

    /**
     * @brief 해당 컨텍스트의 화면 너비를 반환합니다.
     *
     * @return uint32 해당 컨텍스트의 화면 너비.
     */
    const uint32& GetScreenWidth() const;

    /**
     * @brief 해당 컨텍스트의 화면 너비를 지정한 값으로 설정합니다.
     *
     * @param width_ 지정할 값.
     */
    void SetScreenWidth(const uint32& width_);

    /**
     * @brief 해당 컨텍스트의 화면 높이를 반환합니다.
     *
     * @return uint32 해당 컨텍스트의 화면 높이.
     */
    const uint32& GetScreenHeight() const;

    /**
     * @brief 해당 컨텍스트의 스크린 높이를 지정한 값으로 설정합니다.
     *
     * @param height_ 지정할 값.
     */
    void SetScreenHeight(const uint32& height_);

    /**
     * @brief 해당 컨텍스트를 초기화합니다.
     */
    virtual void Initialize();

    /**
     * @brief 해당 컨텍스트를 기동합니다.
     */
    virtual void Run();

    /**
     * @brief 해당 컨텍스트 내 발생하는 윈도우 메시지를 처리합니다.
     *
     * @param message_ 호출된 윈도우 메시지.
     *
     * @return LRESULT 메시지 처리 결과.
     */
    virtual LRESULT CALLBACK HandleMessage(const WindowMessage& message_) = 0;

private:
    /**
     * @brief 발생한 윈도우 메시지를 해당 컨텍스트에 전달합니다.
     *
     * @param window_ 전달할 윈도우 컨텍스트.
     * @param message_ 호출된 윈도우 메시지.
     * @param wParam_ 추가 메시지 정보. (WPARAM)
     * @param lParam_ 추가 메시지 정보. (LPARAM)
     *
     * @return LRESULT 메시지 처리 결과.
     */
    static LRESULT CALLBACK mProceedMessage(
        HWND window_,
        UINT message_,
        WPARAM wParam_,
        LPARAM lParam_
    );

    /**
     * @brief 윈도우 핸들.
     */
    HWND mWindow;

    /**
     * @brief 윈도우 캡션.
     */
    std::wstring mCaption;

    /**
     * @brief 윈도우 너비.
     */
    uint32 mWindowWidth;

    /**
     * @brief 윈도우 높이.
     */
    uint32 mWindowHeight;

    /**
     * @brief 스크린 너비.
     */
    uint32 mScreenWidth;

    /**
     * @brief 스크린 높이.
     */
    uint32 mScreenHeight;

};

#endif // !GUARD_WINDOWCONTEXT_HPP
