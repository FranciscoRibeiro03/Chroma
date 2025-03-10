
#pragma once

#include "lighting/LightIDTableManager.hpp"


namespace Chroma {
    class KDAEnvironment : public EnvironmentData {
    public:
        EnvironmentLightDataT getEnvironmentLights() override;
    };
}
