#include "LineSDKModule.h"
#include "ISettingsModule.h"
#include "LineSDK.h"

#if PLATFORM_ANDROID
#include "Interface/Android/LineSDKInterfaceAndroid.h"
#elif PLATFORM_IOS
#include "Interface/IOS/LineSDKInterfaceIOS.h"
#else
#include "Interface/LineSDKInterfacePlaceholder.h"
#endif

#define LOCTEXT_NAMESPACE "FLineSDKModule"

void FLineSDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory;
	// the exact timing is specified in the .uplugin file per-module

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(
			"Project", "Plugins", "LineSDKSettings",
			LOCTEXT("RuntimeSettingsName", "Line SDK"),
			LOCTEXT("RuntimeSettingsDescription", "Line SDK Settings"),
			GetMutableDefault<ULineSDKSettings>()
		);
	}

#if PLATFORM_ANDROID
	NativeInterfacePointer = MakeShareable(new FLineSDKInterfaceAndroid());
#elif PLATFORM_IOS
	NativeInterfacePointer = MakeShareable(new FLineSDKInterfaceIOS());
#else
	NativeInterfacePointer = MakeShareable(new FLineSDKInterfacePlaceholder());
#endif
}

void FLineSDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module. For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "LineSDKSettings");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLineSDKModule, LineSDK)