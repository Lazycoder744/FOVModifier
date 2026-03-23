#include "ui/SettingsViewController.hpp"
#include "custom-types/shared/register.hpp"

DEFINE_TYPE(FOVModifier, SettingsViewController);

namespace FOVModifier {

    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {
            // Setup UI elements here
        }
    }

    float SettingsViewController::get_fov() {
        return fov;
    }

    void SettingsViewController::set_fov(float value) {
        fov = value;
    }

} // namespace FOVModifier