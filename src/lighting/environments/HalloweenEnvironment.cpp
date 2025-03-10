

#include "lighting/environments/HalloweenEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT HalloweenEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 8 },
        {2, 7 },
        {3, 6 },
        {4, 3 },
    }},
    {2, {
        {1, 5 },
        {2, 6 },
        {3, 7 },
    }},
    {3, {
        {1, 1 },
        {2, 19 },
        {3, 18 },
        {4, 15 },
        {5, 10 },
        {6, 6 },
        {7, 8 },
        {8, 4 },
        {9, 7 },
        {10, 14 },
        {11, 16 },
        {12, 5 },
        {13, 17 },
        {14, 3 },
        {15, 13 },
        {16, 12 },
        {17, 11 },
        {18, 9 },
    }},
    {4, {
        {1, 1 },
        {2, 15 },
        {3, 16 },
        {4, 19 },
        {5, 12 },
        {6, 5 },
        {7, 9 },
        {8, 3 },
        {9, 7 },
        {10, 13 },
        {11, 17 },
        {12, 6 },
        {13, 18 },
        {14, 4 },
        {15, 14 },
        {16, 10 },
        {17, 11 },
        {18, 8 },
    }},
    {5, {
        {1, 3 },
        {2, 2 },
        {3, 6 },
    }},
}
    );
}

ChromaInstallEnvironment(HalloweenEnvironment)
