#pragma once

#include <map>
#include <string>
#include <vector>

#include "Inari/Common/Vec4.h"
#include "Inari/Common/VecTypes.h"

namespace inari {
    struct AnimationSprite {
        std::string currentTrack;
        size_t currentFrame = 0;

        bool isFramesLimited = false;
        float framesLimit = 0.0f;

        using FrameRect = Vec4f;
        using TrackFrames = std::vector<FrameRect>;
        std::map<std::string, TrackFrames> tracks;

        float lastUpdate = 0.0f;
    };
} // namespace inari