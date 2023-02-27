#include "Inari/ECS/Systems/SpriteRenderSystem.h"

#include <cassert>

#include "Inari/ECS/Components/Sprite.h"
#include "Inari/ECS/Components/Transform.h"
#include "Inari/ECS/EntityRegistry.h"

#include "Inari/Graphics/SpriteBatch.h"

#include "Inari/GameServices.h"

namespace inari {
    void SpriteRenderSystem::begin() { begin(Mat4::Identity(), SpriteSortMode::DEFERRED); }

    void SpriteRenderSystem::begin(const Mat4& transform) { begin(transform, SpriteSortMode::DEFERRED); }

    void SpriteRenderSystem::begin(const Mat4& transform, SpriteSortMode sortMode)
    {
        GameServices::get<SpriteBatch>()->begin(transform, sortMode);
    }

    void SpriteRenderSystem::end() { GameServices::get<SpriteBatch>()->end(); }

    void SpriteRenderSystem::update(const GameTime& gameTime, const EntityRegPtr& entityRegistry,
                                    const EntityPtr& entity)
    {
        assert(entityRegistry != nullptr && "Entity registry is empty");

        const auto* sprite = entityRegistry->getComponent<Sprite>(entity);
        const auto* transform = entityRegistry->getComponent<Transform>(entity);
        if (sprite == nullptr || transform == nullptr) {
            return;
        }

        if (transform->size != Vec2f::Zero()) {
            GameServices::get<SpriteBatch>()->draw(sprite->texture, sprite->color,
                                                   Vec4f(transform->position, transform->size), sprite->sourceRect,
                                                   transform->radian, transform->origin);
        } else {
            GameServices::get<SpriteBatch>()->draw(sprite->texture, sprite->color, transform->position,
                                                   sprite->sourceRect, transform->radian, transform->origin);
        }
    }
} // namespace inari
