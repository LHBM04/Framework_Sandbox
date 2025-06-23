#ifndef GUARD_VECTOR2_H
#define GUARD_VECTOR2_H

/**
 * @brief 2차원 벡터를 정의합니다.
 */
class Vector2
{
public:
    // 생성자 및 기본 연산
    Vector2(void);
    Vector2(float x, float y);
    Vector2(const Vector2& other) = default;
    Vector2(Vector2&& other) noexcept = default;
    ~Vector2(void) = default;

    Vector2& operator=(const Vector2& other) = default;
    Vector2& operator=(Vector2&& other) noexcept = default;

public:
    // Getter / Setter
    float GetX(void) const;
    float GetY(void) const;
    void SetX(float x);
    void SetY(float y);

    // 인덱스 접근
    float& operator[](std::size_t index);
    const float& operator[](std::size_t index) const;

    // 벡터 상수
    static const Vector2 Zero();
    static const Vector2 One();
    static const Vector2 Up();
    static const Vector2 Down();
    static const Vector2 Left();
    static const Vector2 Right();

    // 벡터 연산
    float Length(void) const;
    float LengthSquared(void) const;
    void Normalize(void);
    Vector2 Normalized(void) const;

    static float Dot(const Vector2& a, const Vector2& b);
    static float Angle(const Vector2& from, const Vector2& to);
    static float Distance(const Vector2& a, const Vector2& b);
    static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
    static Vector2 ClampMagnitude(const Vector2& vector, float maxLength);
    static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);

    // 연산자 오버로딩
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;
    Vector2 operator-() const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

private:
    float mX;
    float mY;

};

#endif // !GUARD_VECTOR2_H
