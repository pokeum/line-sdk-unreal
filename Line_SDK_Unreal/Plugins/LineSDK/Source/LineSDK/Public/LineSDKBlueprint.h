#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LineSDKBlueprint.generated.h"

UCLASS()
class ULineSDKBlueprint : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "LineSDK sample test testing"), Category = "LineSDKTesting")
	static float LineSDKSampleFunction(float Param);
};