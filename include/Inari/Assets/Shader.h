#pragma once

#include "Inari/Assets/IAsset.h"
#include "Inari/Common/Color.h"
#include "Inari/Common/Mat4.h"
#include "Inari/Common/Vec2.h"
#include "Inari/Common/Vec3.h"
#include "Inari/Common/Vec4.h"

#include <string_view>

namespace inari {
    class Shader final : public IAsset {
        friend class ShaderMaker;

    public:
        void use() const;

        void set(const std::string_view& name, int value) const;
        void set(const std::string_view& name, bool value) const;
        void set(const std::string_view& name, float value) const;
        void set(const std::string_view& name, const Vec2f& value) const;
        void set(const std::string_view& name, const Vec3f& value) const;
        void set(const std::string_view& name, const Vec4f& value) const;
        void set(const std::string_view& name, const Color& value) const;
        void set(const std::string_view& name, const Mat4& matrix) const;

        int32_t getAttributePosition(const std::string_view& name) const;

    protected:
        struct Data {
            uint32_t id = 0;
        };

    public:
        explicit Shader(const Data& data);
        ~Shader() override;

        Shader() = delete;
        Shader(Shader&&) = delete;
        Shader(const Shader&) = delete;
        Shader& operator=(Shader&&) = delete;
        Shader& operator=(const Shader&) = delete;

    private:
        uint32_t m_id;
    };
}
