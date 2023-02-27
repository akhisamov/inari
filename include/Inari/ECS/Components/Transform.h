#pragma once

#include "Inari/Common/Vec2.h"
#include "Inari/Common/Vec4.h"

namespace inari {
    struct Transform {
        Vec2f position;
        Vec2f size;
        float radian = 0.0f;
        Vec2f origin;

        Vec2f getAbsolutePosition() const { return position - (size * origin); }
        Vec4f getRect() const { return { getAbsolutePosition(), size }; }
    };
} // namespace inari
