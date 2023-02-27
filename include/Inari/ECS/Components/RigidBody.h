#pragma once

#include "Inari/Common/Vec2.h"
#include "Inari/Common/VecTypes.h"

namespace inari {
    struct RigidBody {
        Vec2f velocity;
        float speed = 0.0f;
    };
} // namespace inari