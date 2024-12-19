#pragma once

#include "Interface/LineSDKInterface.h"

typedef TSharedPtr<LineSDKInterface, ESPMode::ThreadSafe> LineSDKInterfacePointer;

class FLineSDKModule : public IModuleInterface
{
public:
	static FLineSDKModule* Get()
	{
		return FModuleManager::LoadModulePtr<FLineSDKModule>("LineSDK");
	}
	
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	LineSDKInterfacePointer GetLineSDK() const
	{
		return Pointer;
	}

protected:
	LineSDKInterfacePointer Pointer;
};