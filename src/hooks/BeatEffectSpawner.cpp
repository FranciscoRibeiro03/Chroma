#include "Chroma.hpp"

#include "hooks/colorizer/Note/ColorManager.hpp"

#include "ChromaController.hpp"
#include "ChromaObjectData.hpp"
#include "utils/ChromaUtils.hpp"

#include "colorizer/BombColorizer.hpp"
#include "colorizer/NoteColorizer.hpp"

#include "GlobalNamespace/ColorExtensions.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/BeatEffectSpawner_InitData.hpp"
#include "GlobalNamespace/MemoryPoolContainer_1.hpp"
#include "GlobalNamespace/LazyCopyHashSet_1.hpp"

#include "GlobalNamespace/AudioTimeSyncController.hpp"

#include "custom-json-data/shared/CustomBeatmapData.h"

using namespace Chroma;
using namespace GlobalNamespace;

inline bool BeatEffectForce(bool hideNoteSpawnEffect, NoteController* noteController)
{
    auto it = ChromaObjectDataManager::ChromaObjectDatas.find(noteController->noteData);

    if (it != ChromaObjectDataManager::ChromaObjectDatas.end()) {
        auto const& chromaData = it->second;
        std::optional<bool> disable = chromaData.DisableSpawnEffect;

        if (disable) {
            return !disable.value();
        }
    }

    return hideNoteSpawnEffect;
}

MAKE_HOOK_MATCH(BeatEffectSpawner_HandleNoteDidStartJump, &BeatEffectSpawner::HandleNoteDidStartJump, void, BeatEffectSpawner* self, NoteController* noteController) {
    // Do nothing if Chroma shouldn't run
    if (!ChromaController::DoChromaHooks()) {
        BeatEffectSpawner_HandleNoteDidStartJump(self, noteController);
        return;
    }

/// TRANSPILE HERE
//    if (self->initData->hideNoteSpawnEffect)
    if (BeatEffectForce(self->initData->hideNoteSpawnEffect, noteController))
    {
        return;
    }
    if (noteController->hidden)
    {
        return;
    }
    if (noteController->noteData->time + 0.1f < self->audioTimeSyncController->songTime)
    {
        return;
    }
    ColorType colorType = noteController->noteData->colorType;
    Sombrero::FastColor a = (colorType != ColorType::None) ? self->colorManager->ColorForType(colorType) : self->bombColorEffect;
    auto beatEffect = self->beatEffectPoolContainer->Spawn();
    beatEffect->didFinishEvent->Add(self->i_IBeatEffectDidFinishEvent());
    beatEffect->get_transform()->SetPositionAndRotation(noteController->get_worldRotation() * noteController->get_jumpStartPos() - Sombrero::FastVector3(0.f, 0.15f, 0.f), Sombrero::FastQuaternion::identity());
    beatEffect->Init(a * 1.f, self->effectDuration, noteController->get_worldRotation());
}

void BeatEffectSpawnerHook(Logger& logger) {
    // TODO: DO TODO ABOVE
    INSTALL_HOOK_ORIG(logger, BeatEffectSpawner_HandleNoteDidStartJump);
}

ChromaInstallHooks(BeatEffectSpawnerHook)