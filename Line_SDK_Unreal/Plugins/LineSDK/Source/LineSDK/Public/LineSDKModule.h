#pragma once

#include "Interface/LineSDKInterface.h"

typedef TSharedPtr<FLineSDKInterface, ESPMode::ThreadSafe> FLineSDKInterfacePointer;

class FLineSDKModule final : public IModuleInterface
{
public:
	static FLineSDKModule* Get()
	{
		return FModuleManager::LoadModulePtr<FLineSDKModule>("LineSDK");
	}
	
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FLineSDKInterfacePointer NativeInterface() const
	{
		return NativeInterfacePointer;
	}

protected:
	FLineSDKInterfacePointer NativeInterfacePointer;
};