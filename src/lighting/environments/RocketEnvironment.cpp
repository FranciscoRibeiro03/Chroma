

#include "lighting/environments/RocketEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT RocketEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 8 },
        {2, 17 },
        {3, 9 },
        {4, 6 },
        {5, 18 },
        {6, 16 },
        {7, 15 },
        {8, 13 },
        {9, 10 },
        {10, 7 },
        {11, 14 },
        {12, 12 },
        {13, 11 },
    }},
    {2, {
        {1, 5 },
        {2, 8 },
        {3, 9 },
        {4, 4 },
    }},
    {3, {
        {1, 6 },
        {2, 2 },
        {3, 4 },
        {4, 3 },
        {5, 8 },
        {6, 7 },
        {7, 5 },
    }},
    {4, {
        {1, 6 },
        {2, 3 },
        {3, 4 },
        {4, 2 },
        {5, 8 },
        {6, 7 },
        {7, 5 },
    }},
    {5, {
        {1, 10 },
        {2, 14 },
        {3, 17 },
        {4, 4 },
        {5, 2 },
        {6, 6 },
        {7, 8 },
    }},
}
    );
}

ChromaInstallEnvironment(RocketEnvironment)
