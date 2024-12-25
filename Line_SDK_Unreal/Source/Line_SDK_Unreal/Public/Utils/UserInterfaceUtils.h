#pragma once

#include "CoreMinimal.h"
#include "UserInterfaceUtils.generated.h"

DECLARE_DYNAMIC_DELEGATE(FGameThreadRunner);

UCLASS()
class LINE_SDK_UNREAL_API UUserInterfaceUtils : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
public:
	static void FromGameThread(const TFunction<void()>& Function);

protected:
	UFUNCTION(BlueprintCallable, Category = "User Interface Utils")
	static void RunFromGameThread(const FGameThreadRunner Runner);
};
