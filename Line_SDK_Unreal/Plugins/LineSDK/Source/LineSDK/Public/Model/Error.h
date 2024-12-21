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
	
private:
	UPROPERTY()
	int32 Code;

	UPROPERTY()
	FString Message;

public:
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Error")
	UPARAM(DisplayName = "Code") int32 GetCode() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Error")
	UPARAM(DisplayName = "Message") FString GetMessage() const;
};
