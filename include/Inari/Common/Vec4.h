#pragma once

#include "Vec2.h"
#include "Vec3.h"

#include <cmath>

namespace inari {
    template <typename T>
    struct Vec4 {
        T x;
        T y;
        T z;
        T w;

        constexpr Vec4();
        constexpr Vec4(T scalar);
        constexpr Vec4(T x, T y, T z, T w);
        constexpr Vec4(T x, T y, const Vec2<T>& v);
        constexpr Vec4(const Vec2<T>& v, T z, T w);
        constexpr Vec4(T x, const Vec2<T>& v, T w);
        constexpr Vec4(const Vec2<T>& a, const Vec2<T>& b);
        constexpr Vec4(const Vec3<T>& v, T w);
        constexpr Vec4(T x, const Vec3<T>& v);
        constexpr Vec4(const T* array);

        template <typename X>
        constexpr Vec4(const Vec4<X>& rhs);

        static Vec4 Zero();

        constexpr Vec4 normal() const;

        constexpr T& at(std::size_t idx);
        constexpr const T& at(std::size_t idx) const;

        constexpr T& operator[](std::size_t idx);
        constexpr const T& operator[](std::size_t idx) const;

        constexpr Vec4 operator+(const Vec4& rhs) const;
        constexpr Vec4 operator-(const Vec4& rhs) const;
        constexpr Vec4 operator*(const Vec4& rhs) const;
        constexpr Vec4 operator/(const Vec4& rhs) const;
        constexpr Vec4 operator*(T rhs) const;

        constexpr Vec4& operator+=(const Vec4& rhs);
        constexpr Vec4& operator-=(const Vec4& rhs);
        constexpr Vec4& operator*=(const Vec4& rhs);
        constexpr Vec4& operator/=(const Vec4& rhs);
        constexpr Vec4& operator*=(T rhs);

        constexpr bool operator==(const Vec4& rhs) const;
        constexpr bool operator!=(const Vec4& rhs) const;
    };

    template <typename T>
    constexpr Vec4<T>::Vec4()
        : x(static_cast<T>(0i))
        , y(static_cast<T>(0i))
        , z(static_cast<T>(0i))
        , w(static_cast<T>(0i))
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(T scalar)
        : x(scalar)
        , y(scalar)
        , z(scalar)
        , w(scalar)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(T x, T y, T z, T w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(T x, T y, const Vec2<T>& v)
        : x(x)
        , y(y)
        , z(v.x)
        , w(v.y)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(const Vec2<T>& v, T z, T w)
        : x(v.x)
        , y(v.y)
        , z(z)
        , w(w)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(T x, const Vec2<T>& v, T w)
        : x(x)
        , y(v.x)
        , z(v.y)
        , w(w)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(const Vec2<T>& a, const Vec2<T>& b)
        : x(a.x)
        , y(a.y)
        , z(b.x)
        , w(b.y)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(const Vec3<T>& v, T w)
        : x(v.x)
        , y(v.y)
        , z(v.z)
        , w(w)
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(T x, const Vec3<T>& v)
        : x(x)
        , y(v.x)
        , z(v.y)
        , w(v.z)
    {
    }

    template <typename T>
    template <typename X>
    constexpr Vec4<T>::Vec4(const Vec4<X>& rhs)
        : x(static_cast<T>(rhs.x))
        , y(static_cast<T>(rhs.y))
        , z(static_cast<T>(rhs.z))
        , w(static_cast<T>(rhs.w))
    {
    }

    template <typename T>
    constexpr Vec4<T>::Vec4(const T* array)
        : x(array[0])
        , y(array[1])
        , z(array[2])
        , w(array[3])
    {
    }

    template <typename T>
    Vec4<T> Vec4<T>::Zero()
    {
        return { static_cast<T>(0i) };
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::normal() const
    {
        const auto len = std::sqrt(x * x + y * y + z * z + w * w);
        if (len <= 0) {
            return Zero();
        }
        return { x / len, y / len, z / len, w / len };
    }

    template <typename T>
    constexpr T& Vec4<T>::at(std::size_t idx)
    {
        assert(idx >= 0 && idx < 4);
        if (idx == 0) {
            return x;
        }
        if (idx == 1) {
            return y;
        }
        if (idx == 2) {
            return z;
        }
        return w;
    }

    template <typename T>
    constexpr const T& Vec4<T>::at(std::size_t idx) const
    {
        assert(idx >= 0 && idx < 4);
        if (idx == 0) {
            return x;
        }
        if (idx == 1) {
            return y;
        }
        if (idx == 2) {
            return z;
        }
        return w;
    }

    template <typename T>
    constexpr T& Vec4<T>::operator[](std::size_t idx)
    {
        return at(idx);
    }

    template <typename T>
    constexpr const T& Vec4<T>::operator[](std::size_t idx) const
    {
        return at(idx);
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::operator+(const Vec4& rhs) const
    {
        return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::operator-(const Vec4& rhs) const
    {
        return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::operator*(const Vec4& rhs) const
    {
        return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w };
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::operator/(const Vec4& rhs) const
    {
        return { x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w };
    }

    template <typename T>
    constexpr Vec4<T> Vec4<T>::operator*(T rhs) const
    {
        return { x * rhs, y * rhs, z * rhs, w * rhs };
    }

    template <typename T>
    constexpr Vec4<T>& Vec4<T>::operator+=(const Vec4& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    template <typename T>
    constexpr Vec4<T>& Vec4<T>::operator-=(const Vec4& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    template <typename T>
    constexpr Vec4<T>& Vec4<T>::operator*=(const Vec4& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        w *= rhs.w;
        return *this;
    }

    template <typename T>
    constexpr Vec4<T>& Vec4<T>::operator/=(const Vec4& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        w /= rhs.w;
        return *this;
    }

    template <typename T>
    constexpr Vec4<T>& Vec4<T>::operator*=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }

    template <typename T>
    constexpr bool Vec4<T>::operator==(const Vec4& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
    }

    template <typename T>
    constexpr bool Vec4<T>::operator!=(const Vec4& rhs) const
    {
        return x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w;
    }
}