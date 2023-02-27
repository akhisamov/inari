#pragma once

#include <array>

#include "Vec3.h"
#include "Vec4.h"
#include "VecTypes.h"

namespace inari {
    struct Mat4 {
        constexpr Mat4() noexcept;
        constexpr Mat4(float scalar) noexcept;

        constexpr auto& at(std::size_t idx) { return m_data[idx]; }
        constexpr const auto& at(std::size_t idx) const { return m_data[idx]; }
        constexpr auto& operator[](std::size_t idx);
        constexpr const auto& operator[](std::size_t idx) const;
        constexpr const float* data() const { return (const float*)m_data; }

        constexpr Mat4& translate(const Vec3f& v);
        constexpr Mat4& rotate(float radian, const Vec3f& v);
        constexpr Mat4& scale(const Vec3f& v);

        static constexpr Mat4 translate(const Mat4& m, const Vec3f& v);
        static constexpr Mat4 rotate(const Mat4& m, float radian, const Vec3f& v);
        static constexpr Mat4 scale(const Mat4& m, const Vec3f& v);

        static constexpr Mat4 Identity();
        static constexpr Mat4 Orthographic(float left, float right, float bottom, float top);
        static constexpr Mat4 Orthographic(float left, float right, float bottom, float top, float nearVal,
                                           float farVal);

    private:
        float m_data[4][4];
    };

    constexpr Mat4::Mat4() noexcept
        : m_data()
    {
    }

    constexpr Mat4::Mat4(float scalar) noexcept
        : m_data()
    {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m_data[i][j] = i == j ? scalar : 0.0f;
            }
        }
    }

    constexpr auto& Mat4::operator[](std::size_t idx) { return at(idx); }
    constexpr const auto& Mat4::operator[](std::size_t idx) const { return at(idx); }

    constexpr Mat4& Mat4::translate(const Vec3f& v)
    {
        for (int i = 0; i < 4; ++i) {
            m_data[3][i] = m_data[0][i] * v[0] + m_data[1][i] * v[1] + m_data[2][i] * v[2] + m_data[3][i];
        }
        return *this;
    }

    constexpr Mat4& Mat4::rotate(float radian, const Vec3<float>& v)
    {
        const float c = std::cosf(radian);
        const float s = std::sinf(radian);

        const Vec3f axis = v.normal();
        const Vec3f temp(axis * (1.0f - c));

        Mat4 rotate;

        rotate[0][0] = c + temp[0] * axis[0];
        rotate[0][1] = temp[0] * axis[1] + s * axis[2];
        rotate[0][2] = temp[0] * axis[2] - s * axis[1];

        rotate[1][0] = temp[1] * axis[0] - s * axis[2];
        rotate[1][1] = c + temp[1] * axis[1];
        rotate[1][2] = temp[1] * axis[2] + s * axis[0];

        rotate[2][0] = temp[2] * axis[0] + s * axis[1];
        rotate[2][1] = temp[2] * axis[1] - s * axis[0];
        rotate[2][2] = c + temp[2] * axis[2];

        Mat4 copy(*this);
        for (std::size_t i = 0; i < 3; ++i) {
            Vec4f result;
            for (std::size_t j = 0; j < 3; ++j) {
                result += Vec4f(copy[j]) * rotate[i][j];
            }
            for (std::size_t j = 0; j < 4; ++j) {
                at(i)[j] = result[j];
            }
        }
        return *this;
    }

    constexpr Mat4& Mat4::scale(const Vec3<float>& v)
    {
        for (std::size_t i = 0; i < 3; ++i) {
            Vec4f result(at(i));
            result *= v[i];
            for (std::size_t j = 0; j < 4; ++j) {
                at(i)[j] = result[j];
            }
        }
        return *this;
    }

    constexpr Mat4 Mat4::translate(const Mat4& m, const Vec3<float>& v)
    {
        Mat4 result = m;
        result.translate(v);
        return result;
    }

    constexpr Mat4 Mat4::rotate(const Mat4& m, float radian, const Vec3<float>& v)
    {
        Mat4 result = m;
        result.rotate(radian, v);
        return result;
    }

    constexpr Mat4 Mat4::scale(const Mat4& m, const Vec3<float>& v)
    {
        Mat4 result = m;
        result.scale(v);
        return result;
    }

    constexpr Mat4 Mat4::Identity() { return { 1.0f }; }
    constexpr Mat4 Mat4::Orthographic(float left, float right, float bottom, float top)
    {
        return Orthographic(left, right, bottom, top, -1, 1);
    }
    constexpr Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float nearVal, float farVal)
    {
        Mat4 m = Mat4::Identity();
        Vec3f t;
        t.x = -((right + left) / (right - left));
        t.y = -((top + bottom) / (top - bottom));
        t.z = -((farVal + nearVal) / (farVal - nearVal));
        m.translate(t);
        m[0][0] = 2 / (right - left);
        m[1][1] = 2 / (top - bottom);
        m[2][2] = (-2) / (farVal - nearVal);
        return m;
    }
}