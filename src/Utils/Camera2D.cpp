#include "Inari/Utils/Camera2D.h"

namespace inari {
    Camera2D::Camera2D(const Vec2i& windowSize)
        : m_isDirty(true)
        , m_transformMatrix(1.0f)
        , m_windowSize(windowSize)
        , m_position(0.0f)
        , m_scale(1.0f)
    {
    }

    Camera2D::Camera2D(const Vec2i& windowSize, float scale)
        : m_isDirty(true)
        , m_transformMatrix(1.0f)
        , m_windowSize(windowSize)
        , m_position(0.0f)
        , m_scale(scale)
    {
    }

    void Camera2D::setWindowSize(const Vec2f& windowSize)
    {
        m_windowSize = windowSize;
        m_isDirty = true;
    }

    void Camera2D::setPosition(const Vec2f& position)
    {
        m_position = position;
        m_isDirty = true;
    }

    void Camera2D::move(const Vec2f& shift)
    {
        m_position = m_position + shift;
        m_isDirty = true;
    }

    void Camera2D::setScale(const Vec2f& scale)
    {
        m_scale = scale;
        m_isDirty = true;
    }

    const Mat4& Camera2D::getTransform()
    {
        if (m_isDirty) {
            m_transformMatrix = Mat4::Orthographic(m_position.x, (m_windowSize.x * m_scale.x) + m_position.x,
                                                   (m_windowSize.y * m_scale.y) + m_position.y, m_position.y);
        }

        return m_transformMatrix;
    }
} // namespace inari
