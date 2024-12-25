#pragma once

#include "CoreMinimal.h"

class LINE_SDK_UNREAL_API UserInterfaceUtils
{
public:
	static void FromGameThread(const TFunction<void()>& Function);
};
