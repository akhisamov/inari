#pragma once

#include <cmath>

namespace inari {
    template <typename T>
    struct Vec2 {
        T x;
        T y;

        constexpr Vec2();
        constexpr Vec2(T scalar);
        constexpr Vec2(T x, T y);

        template <typename X>
        constexpr Vec2(const Vec2<X>& rhs);

        static Vec2 Zero();

        constexpr Vec2 normal() const;

        constexpr T& at(std::size_t idx);
        constexpr const T& at(std::size_t idx) const;

        constexpr T& operator[](std::size_t idx);
        constexpr const T& operator[](std::size_t idx) const;

        constexpr Vec2 operator+(const Vec2& rhs) const;
        constexpr Vec2 operator-(const Vec2& rhs) const;
        constexpr Vec2 operator*(const Vec2& rhs) const;
        constexpr Vec2 operator/(const Vec2& rhs) const;
        constexpr Vec2 operator*(T rhs) const;

        constexpr Vec2& operator+=(const Vec2& rhs);
        constexpr Vec2& operator-=(const Vec2& rhs);
        constexpr Vec2& operator*=(const Vec2& rhs);
        constexpr Vec2& operator/=(const Vec2& rhs);
        constexpr Vec2& operator*=(T rhs);

        constexpr bool operator==(const Vec2& rhs) const;
        constexpr bool operator!=(const Vec2& rhs) const;
    };

    template <typename T>
    constexpr Vec2<T>::Vec2()
        : x(static_cast<T>(0i))
        , y(static_cast<T>(0i))
    {
    }

    template <typename T>
    constexpr Vec2<T>::Vec2(T scalar)
        : x(scalar)
        , y(scalar)
    {
    }

    template <typename T>
    constexpr Vec2<T>::Vec2(T x, T y)
        : x(x)
        , y(y)
    {
    }

    template <typename T>
    template <typename X>
    constexpr Vec2<T>::Vec2(const Vec2<X>& rhs)
        : x(static_cast<T>(rhs.x))
        , y(static_cast<T>(rhs.y))
    {
    }

    template <typename T>
    Vec2<T> Vec2<T>::Zero()
    {
        return { static_cast<T>(0i) };
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::normal() const
    {
        const auto len = std::sqrt(x * x + y * y);
        if (len <= 0) {
            return Zero();
        }
        return { x / len, y / len };
    }


    template <typename T>
    constexpr T& Vec2<T>::at(std::size_t idx)
    {
        assert(idx == 0 || idx == 1);
        if (idx == 0) {
            return x;
        }
        return y;
    }
    template <typename T>
    constexpr const T& Vec2<T>::at(std::size_t idx) const
    {
        assert(idx == 0 || idx == 1);
        if (idx == 0) {
            return x;
        }
        return y;
    }

    template <typename T>
    constexpr T& Vec2<T>::operator[](std::size_t idx)
    {
        return at(idx);
    }

    template <typename T>
    constexpr const T& Vec2<T>::operator[](std::size_t idx) const
    {
        return at(idx);
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::operator+(const Vec2& rhs) const
    {
        return { x + rhs.x, y + rhs.y };
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::operator-(const Vec2& rhs) const
    {
        return { x - rhs.x, y - rhs.y };
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::operator*(const Vec2& rhs) const
    {
        return { x * rhs.x, y * rhs.y };
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::operator/(const Vec2& rhs) const
    {
        return { x / rhs.x, y / rhs.y };
    }

    template <typename T>
    constexpr Vec2<T> Vec2<T>::operator*(T rhs) const
    {
        return { x * rhs, y * rhs };
    }

    template <typename T>
    constexpr Vec2<T>& Vec2<T>::operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    template <typename T>
    constexpr Vec2<T>& Vec2<T>::operator-=(const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    template <typename T>
    constexpr Vec2<T>& Vec2<T>::operator*=(const Vec2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }

    template <typename T>
    constexpr Vec2<T>& Vec2<T>::operator/=(const Vec2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    template <typename T>
    constexpr Vec2<T>& Vec2<T>::operator*=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    template <typename T>
    constexpr bool Vec2<T>::operator==(const Vec2& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    template <typename T>
    constexpr bool Vec2<T>::operator!=(const Vec2& rhs) const
    {
        return x != rhs.x && y != rhs.y;
    }
}
