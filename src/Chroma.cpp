#include "Chroma.hpp"

void Chroma::InstallHooks() {
    Hooks::BaseNoteVisuals();
    Hooks::BeatEffectSpawner();
    Hooks::BeatmapDataTransformHelper();
    Hooks::BeatmapObjectsAvoidance();
    Hooks::BeatmapObjectSpawnController();
    Hooks::BombNoteController();
    Hooks::ColorManager();
    Hooks::ColorNoteVisuals();
    Hooks::LightPairRotationEventEffect();
    Hooks::LightRotationEventEffect();
    Hooks::LightSwitchEventEffect();
    Hooks::LightWithIdManager();
    Hooks::NoteCutEffectSpawner();
    Hooks::MirroredNoteController();
    Hooks::MirroredObstacleController();
    Hooks::MissionLevelScenesTransitionSetupDataSO();
    Hooks::MultiplayerLevelScenesTransitionSetupDataSO();
    Hooks::ObstacleDissolve();
    Hooks::ObstacleController();
    Hooks::ObstacleSaberSparkleEffectManager();
    Hooks::ParametricBoxController();
    Hooks::ParticleSystemEventEffect();
    Hooks::SaberBurnMarkArea();
    Hooks::SaberBurnMarkSparkles();
    Hooks::SaberClashEffect();
    Hooks::SaberModelContainer();
    Hooks::SceneManager_Internal();
    Hooks::StandardLevelScenesTransitionSetupDataSO();
    Hooks::TrackLaneRing();
    Hooks::TrackLaneRingsManager();
    Hooks::TrackLaneRingsPositionStepEffectSpawner();
    Hooks::TrackLaneRingsRotationEffect();
    Hooks::TrackLaneRingsRotationEffectSpawner();
    Hooks::TutorialScenesTransitionSetupDataSO();
}