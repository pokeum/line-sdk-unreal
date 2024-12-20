#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CallbackPayload.generated.h"

/**
 * 
 */
UCLASS()
class LINESDK_API UCallbackPayload : public UObject
{
	GENERATED_BODY()

public:
	static UCallbackPayload* FromJson(const FString& Json);

	UCallbackPayload() = default;
	UCallbackPayload(const FString& Identifier, const FString& Value);
	
	FString ToJson() const;

	static FString WrapValue(const FString& Identifier, const FString& Value);

private:
	UPROPERTY()
	FString Identifier;

	UPROPERTY()
	FString Value;

public:
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Callback Payload")
	UPARAM(DisplayName = "Identifier") FString GetIdentifier() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Callback Payload")
	UPARAM(DisplayName = "Value") FString GetValue() const;
};