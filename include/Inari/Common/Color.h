#pragma once

#include <string_view>

namespace inari {
    struct Color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        constexpr Color();
        constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = UINT8_MAX);
        constexpr explicit Color(int rgb);
        constexpr explicit Color(const std::string_view& hexString);

        struct Clamped {
            float r;
            float g;
            float b;
            float a;
        };
        constexpr Clamped getClampedColor() const;

        static constexpr Color Black();
        static constexpr Color White();
        static constexpr Color Red();
        static constexpr Color Green();
        static constexpr Color Blue();
        static constexpr Color Yellow();
        static constexpr Color Magenta();
        static constexpr Color Cyan();
    };

    constexpr Color::Color()
        : r(0)
        , g(0)
        , b(0)
        , a(0)
    {
    }
    constexpr Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }
    constexpr Color::Color(int rgb)
        : r(static_cast<uint8_t>((rgb & 0xFF0000) >> 16))
        , g(static_cast<uint8_t>((rgb & 0x00FF00) >> 8))
        , b(static_cast<uint8_t>(rgb & 0x0000FF))
        , a(UINT8_MAX)
    {
    }
    constexpr Color::Color(const std::string_view& hexString)
        : r(0)
        , g(0)
        , b(0)
        , a(UINT8_MAX)
    {
        assert(!hexString.empty() && "Color string is empty");
        int pos = 0;
        if (hexString.front() == '#') {
            pos = 1;
        } else if (hexString.at(0) == '0' && (hexString.at(1) == 'x' || hexString.at(1) == 'X')) {
            pos = 2;
        }
        constexpr auto hexValue = [](char n) {
            if (n >= '0' && n <= '9') {
                return n - '0';
            }
            if (n >= 'A' && n <= 'F') {
                return 10 + n - 'A';
            }
            if (n >= 'a' && n <= 'f') {
                return 10 + n - 'a';
            }
            return 0;
        };
        const std::string_view hex = hexString.substr(pos);
        if (hex.length() >= 6) {
            r = (hexValue(hex[0]) << 4) + hexValue(hex[1]);
            g = (hexValue(hex[2]) << 4) + hexValue(hex[3]);
            b = (hexValue(hex[4]) << 4) + hexValue(hex[5]);
        }
        if (hex.length() >= 8) {
            a = (hexValue(hex[6]) << 4) + hexValue(hex[7]);
        }
    }

    constexpr Color::Clamped Color::getClampedColor() const
    {
        return { static_cast<float>(r) / UINT8_MAX, static_cast<float>(g) / UINT8_MAX,
                 static_cast<float>(b) / UINT8_MAX, static_cast<float>(a) / UINT8_MAX };
    }

    constexpr Color Color::Black() { return { 0, 0, 0 }; }
    constexpr Color Color::White() { return { UINT8_MAX, UINT8_MAX, UINT8_MAX }; }
    constexpr Color Color::Red() { return { UINT8_MAX, 0, 0 }; }
    constexpr Color Color::Green() { return { 0, UINT8_MAX, 0 }; }
    constexpr Color Color::Blue() { return { 0, 0, UINT8_MAX }; }
    constexpr Color Color::Yellow() { return { UINT8_MAX, UINT8_MAX, 0 }; }
    constexpr Color Color::Magenta() { return { UINT8_MAX, 0, UINT8_MAX }; }
    constexpr Color Color::Cyan() { return { 0, UINT8_MAX, UINT8_MAX }; }
}