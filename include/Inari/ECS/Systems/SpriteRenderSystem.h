#pragma once

#include "Inari/Common/Mat4.h"

#include "ISystem.h"

namespace inari {
    class SpriteBatch;
    enum class SpriteSortMode;

    class SpriteRenderSystem : public ISystem {
    public:
        void begin();
        void begin(const Mat4& transform);
        void begin(const Mat4& transform, SpriteSortMode sortMode);
        void end();

    protected:
        void update(const GameTime& gameTime, const EntityRegPtr& entityRegistry, const EntityPtr& entity) override;
    };
} // namespace inari
