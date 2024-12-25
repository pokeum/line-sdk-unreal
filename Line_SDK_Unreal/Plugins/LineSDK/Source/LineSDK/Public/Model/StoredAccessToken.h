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

	FString ToJson() const;

private:
	UPROPERTY()
	FString AccessToken;

	UPROPERTY()
	int64 ExpiresIn;

public:
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Stored Access Token")
	UPARAM(DisplayName = "Access Token") FString GetAccessToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Stored Access Token")
	UPARAM(DisplayName = "Expires In") int64 GetExpiresIn() const;
};
