#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Error.generated.h"

UCLASS()
class LINESDK_API UError : public UObject
{
	GENERATED_BODY()

public:
	static UError* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Json") FString ToJson() const;
	
private:
	UPROPERTY()
	int32 Code;

	UPROPERTY()
	FString Message;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Code") int32 GetCode() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Message") FString GetMessage() const;
};
