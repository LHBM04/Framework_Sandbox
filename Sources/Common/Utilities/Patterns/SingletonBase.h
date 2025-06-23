#ifndef GUARD_SINGLETONBASE_H
#define GUARD_SINGLETONBASE_H

/**
 * @brief Singleton 패턴을 정의합니다.
 *
 * @tparam TInstance 생성할 정적 인스턴스의 타입.
 */
template <typename TInstance>
class SingletonBase
{
public:
    /**
     * @brief 인스턴스를 가져옵니다.
     *
     * @return TInstance& 싱글턴 인스턴스 참조
     */
    static TInstance& GetInstance(void);

protected:
    /**
     * @brief 기본 생성자.
     */
    SingletonBase(void) = default;

    /**
     * @brief 소멸자.
     */
    virtual ~SingletonBase(void) = default;

private:
    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;
    SingletonBase(SingletonBase&&)noexcept = delete;
    SingletonBase& operator=(SingletonBase&&)noexcept = delete;

};

#include "SingletonBase.inl"

#endif // !GUARD_SINGLETONBASE_H
