#include "VBSpecs.h"

unsigned int VBSpecs::GetSpacing()const
{
    return spacing;
}

std::vector<VBConfig> VBSpecs::GetConfigs()const
{
    return configs;
}