

#include "lighting/environments/InterscopeEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT InterscopeEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 1 },
        {2, 0 },
        {3, 7 },
    }},
    {2, {
        {1, 7 },
        {2, 6 },
        {3, 5 },
    }},
    {3, {
        {1, 1 },
        {2, 7 },
        {3, 0 },
    }},
    {4, {
        {1, 1 },
        {2, 7 },
        {3, 0 },
    }},
    {5, {
        {1, 4 },
        {2, 10 },
        {3, 3 },
    }},
    {6, {
        {1, 0 },
        {2, 1 },
        {3, 2 },
        {4, 3 },
        {5, 4 },
        {6, 5 },
        {7, 6 },
    }},
    {7, {
        {1, 0 },
        {2, 1 },
        {3, 2 },
        {4, 3 },
        {5, 4 },
        {6, 5 },
        {7, 6 },
    }},
}
    );
}

ChromaInstallEnvironment(InterscopeEnvironment)
