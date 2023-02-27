#pragma once

#include <memory>

#include "Inari/Common/Color.h"
#include "Inari/Common/Vec4.h"

namespace inari {
    class Texture2D;

    struct Sprite {
        std::shared_ptr<inari::Texture2D> texture;
        Vec4f sourceRect;
        Color color = Color::White();
    };
} // namespace inari