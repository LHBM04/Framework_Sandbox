#ifndef GUARD_WINDOWMESSAGE_HPP
#define GUARD_WINDOWMESSAGE_HPP

struct WindowMessage
{
    /**
     * @brief 윈도우 메시지 종류.
     */
    UINT Message;

    /**
     * @brief 추가 메시지 정보 (WPARAM).
     */
    WPARAM WParam;

    /**
     * @brief 추가 메시지 정보 (LPARAM).
     */
    LPARAM LParam;

    /**
     * @brief 생성자.
     */
    // WindowMessage(UINT message_, WPARAM wParam_, LPARAM lParam_)
    //     : Message(message_), WParam(wParam_), LParam(lParam_), Result(0)
    // {
    // }
};

#endif // !GUARD_WINDOWMESSAGE_HPP
