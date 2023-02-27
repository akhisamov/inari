#pragma once

#include <map>
#include <memory>
#include <vector>

#include "Inari/Common/Color.h"
#include "Inari/Common/Mat4.h"
#include "Inari/Common/Vec2.h"
#include "Inari/Common/Vec4.h"
#include "Inari/IService.h"

namespace inari {
    class Texture2D;
    class Shader;
    class Renderer;
    struct SpriteData;
    struct VertexLayout;

    enum class SpriteSortMode { DEFERRED, IMMEDIATE, TEXTURE };

    class SpriteBatch final : public IService {
        friend class BaseGame;

    public:
        void begin(const Mat4& transformMatrix = Mat4::Identity(), SpriteSortMode sortMode = SpriteSortMode::DEFERRED);

        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec4f& destRect);
        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec4f& destRect,
                  const Vec4f& sourceRect);
        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec4f& destRect,
                  const Vec4f& sourceRect, float rotationInRadian, const Vec2f& origin);

        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec2f& position);
        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec2f& position,
                  const Vec4f& sourceRect);
        void draw(const std::shared_ptr<Texture2D>& texture, const Color& color, const Vec2f& position,
                  const Vec4f& sourceRect, float rotationInRadian, const Vec2f& origin);

        void end();

        void toggleWireframeMode();

    protected:
        struct Token {
            std::weak_ptr<Renderer> weakRenderer;
        };
        static std::shared_ptr<SpriteBatch> create(const std::shared_ptr<Renderer>& renderer);

    public:
        explicit SpriteBatch(const Token& token);
        ~SpriteBatch() override;

        SpriteBatch() = delete;
        SpriteBatch(SpriteBatch&&) = delete;
        SpriteBatch(const SpriteBatch&) = delete;
        SpriteBatch& operator=(SpriteBatch&&) = delete;
        SpriteBatch& operator=(const SpriteBatch&) = delete;

    private:
        void flush();
        void flushData(const SpriteData& data);

        std::weak_ptr<Renderer> m_rendererPtr;

        bool m_isBegan;
        bool m_isWireframeMode;

        std::shared_ptr<Shader> m_shader;
        std::unique_ptr<VertexLayout> m_layout;

        Mat4 m_transformMatrix;
        SpriteSortMode m_sortMode;

        std::vector<SpriteData> m_spriteBuffer;
    };
} // namespace inari
