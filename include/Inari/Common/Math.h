#pragma once

namespace inari::math {
    inline constexpr float pi = 3.14159265358979323846264338327950288;
    inline constexpr float tau = pi * 2;

    inline constexpr float radians(float degrees) { return degrees * (tau / 360.0f); }
    inline constexpr float degrees(float radians) { return radians * (360.0f / tau); }
}