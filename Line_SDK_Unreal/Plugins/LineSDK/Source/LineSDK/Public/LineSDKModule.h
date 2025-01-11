#pragma once

#include "Interface/LineSDKInterface.h"

typedef TSharedPtr<FLineSDKInterface, ESPMode::ThreadSafe> FLineSDKInterfacePointer;

/** @cond HIDDEN_SYMBOLS */
class FLineSDKModule final : public IModuleInterface
{
public:
	static FLineSDKModule* Get()
	{
		return FModuleManager::LoadModulePtr<FLineSDKModule>("LineSDK");
	}
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FLineSDKInterfacePointer NativeInterface() const
	{
		return NativeInterfacePointer;
	}

protected:
	FLineSDKInterfacePointer NativeInterfacePointer;
};
/** @endcond */