#pragma once

#include "Modules/ModuleInterface.h"

class FIosPListUpdaterModule final : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};