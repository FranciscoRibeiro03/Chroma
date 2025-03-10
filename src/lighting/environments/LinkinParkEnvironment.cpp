

#include "lighting/environments/LinkinParkEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT LinkinParkEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {1, {
        {1, 1 },
        {2, 3 },
    }},
    {2, {
        {1, 6 },
        {2, 6 },
        {3, 8 },
        {4, 8 },
        {5, 2 },
        {6, 2 },
        {7, 1 },
        {8, 1 },
        {9, 3 },
        {10, 3 },
        {11, 7 },
        {12, 7 },
        {13, 5 },
        {14, 5 },
        {15, 4 },
        {16, 4 },
    }},
    {3, {
        {1, 1 },
        {2, 2 },
        {3, 3 },
        {4, 4 },
        {5, 5 },
        {6, 6 },
        {7, 7 },
        {8, 8 },
        {9, 9 },
        {10, 10 },
        {11, 11 },
        {12, 12 },
        {13, 13 },
        {14, 14 },
        {15, 15 },
        {16, 16 },
        {17, 17 },
        {18, 18 },
        {19, 20 },
        {20, 19 },
    }},
    {4, {
        {1, 1 },
        {2, 2 },
        {3, 3 },
        {4, 4 },
        {5, 5 },
        {6, 6 },
        {7, 7 },
        {8, 8 },
        {9, 9 },
        {10, 10 },
        {11, 11 },
        {12, 12 },
        {13, 13 },
        {14, 14 },
        {15, 15 },
        {16, 16 },
        {17, 17 },
        {18, 18 },
        {19, 20 },
        {20, 19 },
    }},
    {5, {
        {1, 4 },
    }},
}
    );
}

ChromaInstallEnvironment(LinkinParkEnvironment)
