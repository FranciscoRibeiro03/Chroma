

#include "lighting/environments/BillieEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT BillieEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {0, {
        {1, 9 },
        {2, 5 },
        {3, 10 },
        {4, 16 },
    }},
    {1, {
        {1, 9 },
        {2, 5 },
        {3, 10 },
        {4, 16 },
    }},
    {2, {
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
    }},
    {3, {
        {1, 0 },
        {2, 1 },
        {3, 2 },
        {4, 3 },
        {5, 4 },
        {6, 5 },
        {7, 6 },
        {8, 7 },
        {9, 8 },
        {10, 9 },
        {11, 10 },
    }},
    {4, {
        {1, 4 },
        {2, 13 },
        {3, 19 },
        {4, 8 },
        {5, 12 },
    }},
    {5, {
    }},
    {6, {
        {1, 9 },
        {2, 5 },
        {3, 10 },
        {4, 16 },
    }},
    {7, {
        {1, 9 },
        {2, 5 },
        {3, 10 },
        {4, 16 },
    }},
    {8, {
    }},
    {9, {
    }},
    {10, {
        {1, 0 },
        {2, 8 },
        {3, 5 },
        {4, 2 },
        {5, 3 },
        {6, 9 },
        {7, 6 },
        {8, 4 },
        {9, 7 },
    }},
    {11, {
        {1, 8 },
        {2, 2 },
        {3, 6 },
        {4, 5 },
        {5, 4 },
        {6, 3 },
        {7, 0 },
        {8, 7 },
        {9, 1 },
    }},
}
    );
}

ChromaInstallEnvironment(BillieEnvironment)
