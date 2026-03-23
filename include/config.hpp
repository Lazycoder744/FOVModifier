#pragma once
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig) {
    CONFIG_VALUE(FOV, float, "FOV", 60.0f); // Default FOV value
};