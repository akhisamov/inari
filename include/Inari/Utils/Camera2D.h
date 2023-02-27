#pragma once

#include "Inari/Common/Mat4.h"
#include "Inari/Common/Vec2.h"

namespace inari {
    class Camera2D {
    public:
        explicit Camera2D(const Vec2i& windowSize);
        Camera2D(const Vec2i& windowSize, float scale);
        ~Camera2D() = default;

        Camera2D() = delete;
        Camera2D(Camera2D&&) = delete;
        Camera2D(const Camera2D&) = delete;

        const Vec2f& getWindowSize() const { return m_windowSize; }
        void setWindowSize(const Vec2f& windowSize);

        const Vec2f& getPosition() const { return m_position; }
        void setPosition(const Vec2f& position);
        void move(const Vec2f& shift);

        const Vec2f& getScale() const { return m_scale; }
        void setScale(const Vec2f& scale);

        const Mat4& getTransform();

    private:
        bool m_isDirty;

        Mat4 m_transformMatrix;

        Vec2f m_windowSize;
        Vec2f m_position;
        Vec2f m_scale;
    };
} // namespace inari
