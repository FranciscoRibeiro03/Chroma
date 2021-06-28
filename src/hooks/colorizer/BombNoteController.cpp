#include "Chroma.hpp"
#include "ChromaController.hpp"

#include "colorizer/BombColorizer.hpp"
#include "custom-json-data/shared/CustomBeatmapData.h"
#include "GlobalNamespace/BombNoteController.hpp"
#include "utils/ChromaUtils.hpp"

#include "ChromaObjectData.hpp"

using namespace CustomJSONData;
using namespace GlobalNamespace;
using namespace Chroma;
using namespace ChromaUtils;

MAKE_HOOK_OFFSETLESS(
    BombNoteController_Init,
    void,
    BombNoteController* self,
    CustomNoteData* noteData,
    float worldRotation,
    UnityEngine::Vector3 moveStartPos,
    UnityEngine::Vector3 moveEndPos,
    UnityEngine::Vector3 jumpEndPos,
    float moveDuration,
    float jumpDuration,
    float jumpGravity
) {
    BombNoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity);
    // Do nothing if Chroma shouldn't run
    if (!ChromaController::DoChromaHooks()) {
        return;
    }

    auto chromaData = ChromaObjectDataManager::ChromaObjectDatas.find(noteData);
    if (chromaData != ChromaObjectDataManager::ChromaObjectDatas.end()) {
        auto color = chromaData->second->Color;

        BombColorizer::ColorizeBomb(self, color);
    }
}

void Chroma::Hooks::BombNoteController() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), BombNoteController_Init, il2cpp_utils::FindMethodUnsafe("", "BombNoteController", "Init", 8));
}