#pragma once
#include "custom-types/shared/macros.hpp"
#include "HMUI/ViewController.hpp"

DECLARE_CLASS_CODEGEN(FOVModifier, SettingsViewController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(float, fov)  // your FOV value

    DECLARE_OVERRIDE_METHOD(void, DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    DECLARE_INSTANCE_METHOD(float, get_fov)
    DECLARE_INSTANCE_METHOD(void, set_fov, float value)
)