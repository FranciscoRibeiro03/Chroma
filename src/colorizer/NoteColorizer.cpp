#include "Chroma.hpp"

#include "UnityEngine/SpriteRenderer.hpp"
#include "UnityEngine/MaterialPropertyBlock.hpp"
#include "UnityEngine/MeshRenderer.hpp"

#include "GlobalNamespace/GameNoteController.hpp"
#include "GlobalNamespace/MaterialPropertyBlockController.hpp"

#include "System/Action_2.hpp"

#include <unordered_map>
#include "colorizer/NoteColorizer.hpp"
#include "colorizer/SliderColorizer.hpp"
#include "colorizer/SaberColorizer.hpp"
#include "ChromaController.hpp"
#include "utils/ChromaUtils.hpp"
#include "ChromaObjectData.hpp"


using namespace CustomJSONData;
using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace Sombrero;
using namespace Chroma;

NoteColorizer::NoteColorizer(GlobalNamespace::NoteControllerBase *noteController)
:_noteController(noteController)
{

    auto colorNoteVisuals = _noteController->GetComponent<GlobalNamespace::ColorNoteVisuals*>();
    _colorNoteVisuals = colorNoteVisuals;
    CRASH_UNLESS(_noteController);
    CRASH_UNLESS(_colorNoteVisuals);

    _materialPropertyBlockControllers = colorNoteVisuals->materialPropertyBlockControllers;
}

NoteColorizer* NoteColorizer::New(GlobalNamespace::NoteControllerBase *noteControllerBase) {
    if (!ChromaController::DoColorizerSabers())
        return nullptr;

    return &Colorizers.try_emplace(noteControllerBase, noteControllerBase).first->second;
}

GlobalNamespace::ColorType NoteColorizer::getColorType() {
    auto noteData = _noteController->get_noteData();
    if (noteData)
    {
        return noteData->colorType;
    }

    return ColorType::ColorA;
}

std::optional<Sombrero::FastColor> NoteColorizer::GlobalColorGetter() {
    return GlobalColor[(int) getColorType()];
}

std::optional<Sombrero::FastColor> NoteColorizer::OriginalColorGetter() {
    return _colorNoteVisuals->colorManager->ColorForType(getColorType());
}

void NoteColorizer::GlobalColorize(std::optional<Sombrero::FastColor> const& color, GlobalNamespace::ColorType const& colorType) {
    GlobalColor[(int)colorType] = color;
    for (auto& [_, colorizer] : Colorizers)
    {
        colorizer.Refresh();
    }
    for (auto& [_, colorizer] : SliderColorizer::Colorizers) {
        colorizer.Refresh();
    }
}

void NoteColorizer::Reset() {
    GlobalColor[0] = std::nullopt;
    GlobalColor[1] = std::nullopt;
    Colorizers.clear();
    NoteColorChanged.clear();
}

void NoteColorizer::ColorizeSaber(GlobalNamespace::NoteController *noteController, const NoteCutInfo &noteCutInfo) {
    if (ChromaController::DoColorizerSabers())
    {
        auto noteData = noteController->noteData;
        SaberType saberType = noteCutInfo.saberType;
        if ((int)noteData->colorType == (int)saberType)
        {
            SaberColorizer::ColorizeSaber(saberType, GetNoteColorizer(noteController)->getColor());
        }
    }
}

void NoteColorizer::Refresh() {
    if (!_colorNoteVisuals->get_isActiveAndEnabled()) return;

    Sombrero::FastColor const& color = getColor().Alpha(_colorNoteVisuals->noteColor.a);
    if (color == Sombrero::FastColor(_colorNoteVisuals->noteColor))
    {
        return;
    }

    NoteColorChanged.invoke(_noteController, color, getColorType());
    if (NoteColorable) return;

    static auto ApplyChanges = FPtrWrapper<&GlobalNamespace::MaterialPropertyBlockController::ApplyChanges>::get();
    static auto SetColor = FPtrWrapper<static_cast<void (UnityEngine::MaterialPropertyBlock::*)(int, UnityEngine::Color)>(&UnityEngine::MaterialPropertyBlock::SetColor)>::get();

    _colorNoteVisuals->noteColor = color;
    for (auto materialPropertyBlockController : _materialPropertyBlockControllers)
    {
        if (!materialPropertyBlockController)
            continue;


        if (materialPropertyBlockController->materialPropertyBlock) {
            auto propertyBlock = materialPropertyBlockController->materialPropertyBlock;
            auto const& originalColor = propertyBlock->GetColor(_colorID());
            SetColor(propertyBlock, _colorID(), color.Alpha(originalColor.a));
        }

        ApplyChanges(materialPropertyBlockController);
    }
}

int NoteColorizer::_colorID() {
    static int colorID = UnityEngine::Shader::PropertyToID("_Color");

    return colorID;
}
