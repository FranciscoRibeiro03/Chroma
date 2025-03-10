

#include "lighting/environments/GlassDesertEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT GlassDesertEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 8 },
        {2, 5 },
        {3, 3 },
        {4, 7 },
        {5, 4 },
        {6, 6 },
    }},
    {2, {
        {1, 7 },
        {2, 3 },
        {3, 10 },
        {4, 4 },
        {5, 9 },
        {6, 8 },
        {7, 5 },
        {8, 6 },
    }},
    {3, {
        {1, 1 },
        {2, 9 },
        {3, 3 },
        {4, 11 },
        {5, 6 },
        {6, 10 },
        {7, 4 },
        {8, 5 },
        {9, 7 },
        {10, 8 },
    }},
    {4, {
        {1, 1 },
        {2, 11 },
        {3, 5 },
        {4, 9 },
        {5, 6 },
        {6, 10 },
        {7, 3 },
        {8, 4 },
        {9, 7 },
        {10, 8 },
    }},
}
    );
}

ChromaInstallEnvironment(GlassDesertEnvironment)
