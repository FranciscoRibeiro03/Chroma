#include "main.hpp"
#include "NoteAPI.hpp"
#include "colorizer/NoteColorizer.hpp"

#include "conditional-dependencies/shared/main.hpp"
#include "shared/utils.hpp"

using namespace Chroma;
using namespace GlobalNamespace;
using namespace UnityEngine;


// TODO: unsure of this
EXPOSE_API(getNoteColorSafe, OptColor, int colorType) {
    CRASH_UNLESS(colorType >= ColorType::ColorA && colorType <= ColorType::ColorB);
    auto optional = NoteColorizer::getNoteColorOverride(colorType);

    UnityEngine::Color color;

    if (optional) {

        color = optional.value();

        return OptColorFromColor(color);
    } else {
        return OptColor();
    }
}

EXPOSE_API(getNoteControllerColorSafe, OptColor, NoteController* noteController, int colorType) {
    CRASH_UNLESS(colorType >= ColorType::ColorA && colorType <= ColorType::ColorB);

    auto cnv = NoteColorizer::CNVColorManager::GetCNVColorManager(noteController);

    if (!cnv) return OptColor();

    auto color = cnv->ColorForCNVManager();

    return OptColorFromColor(color);
}

EXPOSE_API(setNoteColorSafe, void, NoteController* nc, std::optional<UnityEngine::Color> color0, std::optional<UnityEngine::Color> color1) {
    NoteColorizer::SetNoteColors(nc, color0, color1);
}