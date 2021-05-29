#include "SaberAPI.hpp"

#include <utility>
#include "colorizer/SaberColorizer.hpp"

#include "conditional-dependencies/shared/main.hpp"
#include "shared/utils.hpp"

using namespace Chroma;
using namespace GlobalNamespace;
using namespace UnityEngine;



EXPOSE_API(getSaberColorSafe, int, int saberType) {
    CRASH_UNLESS(saberType >= SaberType::SaberA && saberType <= SaberType::SaberB);

    auto optional = SaberColorizer::SaberColorOverride[saberType];

    UnityEngine::Color color;

    if (optional) {

        color = optional.value();

        int rgba = Chroma::ColourManager::ColourToInt(color);

        return rgba;
    } else {
        return -1;
    }
}

EXPOSE_API(setSaberColorSafe, void, int saberType, UnityEngine::Color color) {
    CRASH_UNLESS(saberType >= SaberType::SaberA && saberType <= SaberType::SaberB);

    SaberColorizer::SetSaberColor(saberType, color);
}

EXPOSE_API(registerSaberCallbackSafe, void, const std::function<void()>& callback) {
    SaberColorizer::registerCallback(std::move(callback));
}