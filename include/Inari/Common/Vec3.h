#pragma once

#include "Vec2.h"

#include <cmath>

namespace inari {
    template <typename T>
    struct Vec3 {
        T x;
        T y;
        T z;

        constexpr Vec3();
        constexpr Vec3(T scalar);
        constexpr Vec3(T x, T y, T z);
        constexpr Vec3(T x, const Vec2<T>& v);
        constexpr Vec3(const Vec2<T>& v, T z);

        template <typename X>
        constexpr Vec3(const Vec3<X>& rhs);

        static Vec3 Zero();

        constexpr Vec3 normal() const;

        constexpr T& at(std::size_t idx);
        constexpr const T& at(std::size_t idx) const;

        constexpr T& operator[](std::size_t idx);
        constexpr const T& operator[](std::size_t idx) const;

        constexpr Vec3 operator+(const Vec3& rhs) const;
        constexpr Vec3 operator-(const Vec3& rhs) const;
        constexpr Vec3 operator*(const Vec3& rhs) const;
        constexpr Vec3 operator/(const Vec3& rhs) const;
        constexpr Vec3 operator*(T rhs) const;

        constexpr Vec3& operator+=(const Vec3& rhs);
        constexpr Vec3& operator-=(const Vec3& rhs);
        constexpr Vec3& operator*=(const Vec3& rhs);
        constexpr Vec3& operator/=(const Vec3& rhs);
        constexpr Vec3& operator*=(T rhs);

        constexpr bool operator==(const Vec3& rhs) const;
        constexpr bool operator!=(const Vec3& rhs) const;
    };

    template <typename T>
    constexpr Vec3<T>::Vec3()
        : x(static_cast<T>(0i))
        , y(static_cast<T>(0i))
        , z(static_cast<T>(0i))
    {
    }

    template <typename T>
    constexpr Vec3<T>::Vec3(T scalar)
        : x(scalar)
        , y(scalar)
        , z(scalar)
    {
    }

    template <typename T>
    constexpr Vec3<T>::Vec3(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    template <typename T>
    constexpr Vec3<T>::Vec3(T x, const Vec2<T>& v)
        : x(x)
        , y(v.x)
        , z(v.y)
    {
    }

    template <typename T>
    constexpr Vec3<T>::Vec3(const Vec2<T>& v, T z)
        : x(v.x)
        , y(v.y)
        , z(z)
    {
    }

    template <typename T>
    template <typename X>
    constexpr Vec3<T>::Vec3(const Vec3<X>& rhs)
        : x(static_cast<T>(rhs.x))
        , y(static_cast<T>(rhs.y))
        , z(static_cast<T>(rhs.z))
    {
    }

    template <typename T>
    Vec3<T> Vec3<T>::Zero()
    {
        return { static_cast<T>(0i) };
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::normal() const
    {
        const auto len = std::sqrt(x * x + y * y + z * z);
        if (len <= 0) {
            return Zero();
        }
        return { x / len, y / len, z / len };
    }

    template <typename T>
    constexpr T& Vec3<T>::at(std::size_t idx)
    {
        assert(idx >= 0 && idx < 3);
        if (idx == 0) {
            return x;
        }
        if (idx == 1) {
            return y;
        }
        return z;
    }
    template <typename T>
    constexpr const T& Vec3<T>::at(std::size_t idx) const
    {
        assert(idx >= 0 && idx < 3);
        if (idx == 0) {
            return x;
        }
        if (idx == 1) {
            return y;
        }
        return z;
    }

    template <typename T>
    constexpr T& Vec3<T>::operator[](std::size_t idx)
    {
        return at(idx);
    }

    template <typename T>
    constexpr const T& Vec3<T>::operator[](std::size_t idx) const
    {
        return at(idx);
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::operator+(const Vec3& rhs) const
    {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::operator-(const Vec3& rhs) const
    {
        return { x - rhs.x, y - rhs.y, z - rhs.z };
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::operator*(const Vec3& rhs) const
    {
        return { x * rhs.x, y * rhs.y, z * rhs.z };
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::operator/(const Vec3& rhs) const
    {
        return { x / rhs.x, y / rhs.y, z / rhs.z };
    }

    template <typename T>
    constexpr Vec3<T> Vec3<T>::operator*(T rhs) const
    {
        return { x * rhs, y * rhs, z * rhs };
    }

    template <typename T>
    constexpr Vec3<T>& Vec3<T>::operator+=(const Vec3& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    template <typename T>
    constexpr Vec3<T>& Vec3<T>::operator-=(const Vec3& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    template <typename T>
    constexpr Vec3<T>& Vec3<T>::operator*=(const Vec3& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    template <typename T>
    constexpr Vec3<T>& Vec3<T>::operator/=(const Vec3& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    template <typename T>
    constexpr Vec3<T>& Vec3<T>::operator*=(T rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    template <typename T>
    constexpr bool Vec3<T>::operator==(const Vec3& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    template <typename T>
    constexpr bool Vec3<T>::operator!=(const Vec3& rhs) const
    {
        return x != rhs.x && y != rhs.y && z != rhs.z;
    }
}