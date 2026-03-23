#include "main.hpp"
#include "config.hpp"
#include "ui/SettingsViewController.hpp"

#include "scotland2/shared/modloader.h"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "custom-types/shared/register.hpp"
#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Camera.hpp"

// Mod info
static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

// Config getter
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Hook for camera FOV
MAKE_HOOK_MATCH(Camera_set_fieldOfView, &UnityEngine::Camera::set_fieldOfView, void, UnityEngine::Camera* self, float value) {
    // Attach thread if needed
    il2cpp_functions::thread_attach(il2cpp_domain_get());
    Camera_set_fieldOfView(self, getConfig().FOV.GetValue());
}

// Setup function called by modloader
MOD_EXTERN_FUNC void setup(CModInfo* info) noexcept {
    *info = modInfo.to_c();
    getConfig().Init(modInfo);
    Paper::Logger::RegisterFileContextId(PaperLogger.tag);
    PaperLogger.info("Completed setup!");
}

// Late load function: called after game has loaded
MOD_EXTERN_FUNC void late_load() noexcept {
    il2cpp_functions::Init();                // Initialize il2cpp functions
    custom_types::Register::AutoRegister();  // Register all custom types
    BSML::Register::RegisterSettingsMenu<FOVModifier::SettingsViewController*>("FOV Modifier"); // Register settings menu

    INSTALL_HOOK(PaperLogger, Camera_set_fieldOfView); // Install FOV hook with logger
    PaperLogger.info("Installed all hooks!");
}