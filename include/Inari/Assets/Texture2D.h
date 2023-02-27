#pragma once

#include <memory>

#include "Inari/Assets/IAsset.h"
#include "Inari/Common/Vec2.h"
#include "Inari/Common/VecTypes.h"

namespace inari {
    class Texture2D final : public IAsset {
        friend class Texture2DMaker;

    public:
        void bind() const;

        [[nodiscard]] uint32_t getId() const { return m_id; }
        [[nodiscard]] const Vec2f& getSize() const { return m_size; }

        static uint32_t getId(const std::shared_ptr<Texture2D>& texture);

    protected:
        struct Data {
            uint32_t id = 0;
            Vec2i size;
            int channels = 0;
        };

    public:
        explicit Texture2D(const Data& data);
        ~Texture2D() override;

        Texture2D() = delete;
        Texture2D(Texture2D&&) = delete;
        Texture2D(const Texture2D&) = delete;
        Texture2D& operator=(Texture2D&&) = delete;
        Texture2D& operator=(const Texture2D&) = delete;

    private:
        uint32_t m_id;
        Vec2f m_size;
    };
}
