#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoredAccessToken.generated.h"

UCLASS()
class LINESDK_API UStoredAccessToken : public UObject
{
	GENERATED_BODY()

public:
	static UStoredAccessToken* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Json") FString ToJson() const;

private:
	UPROPERTY()
	FString AccessToken;

	UPROPERTY()
	int64 ExpiresIn;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Value") FString GetValue() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Expires In") int64 GetExpiresIn() const;
};
