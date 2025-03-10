

#include "lighting/environments/CrabRaveEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT CrabRaveEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 4 },
        {2, 6 },
        {3, 12 },
        {4, 10 },
        {5, 13 },
        {6, 9 },
        {7, 11 },
        {8, 5 },
    }},
    {2, {
        {1, 4 },
        {2, 12 },
        {3, 9 },
        {4, 11 },
        {5, 7 },
        {6, 5 },
        {7, 10 },
    }},
    {3, {
        {1, 4 },
        {2, 2 },
        {3, 3 },
        {4, 5 },
        {5, 6 },
    }},
    {4, {
        {1, 6 },
        {2, 5 },
        {3, 3 },
        {4, 2 },
        {5, 4 },
    }},
    {5, {
        {1, 17 },
        {2, 19 },
        {3, 11 },
        {4, 10 },
        {5, 1 },
        {6, 12 },
        {7, 8 },
        {8, 0 },
        {9, 14 },
        {10, 20 },
        {11, 21 },
        {12, 18 },
        {13, 6 },
        {14, 4 },
    }},
}
    );
}

ChromaInstallEnvironment(CrabRaveEnvironment)
