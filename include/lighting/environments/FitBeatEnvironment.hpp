
#pragma once

#include "lighting/LightIDTableManager.hpp"


namespace Chroma {
    class FitBeatEnvironment : public EnvironmentData {
    public:
        EnvironmentLightDataT getEnvironmentLights() override;
    };
}
