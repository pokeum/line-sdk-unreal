#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AccessTokenVerifyResult.generated.h"

UCLASS()
class LINESDK_API UAccessTokenVerifyResult : public UObject
{
	GENERATED_BODY()

public:
	static UAccessTokenVerifyResult* FromJson(const FString& Json);

private:
	UPROPERTY()
	FString ClientId;
	
	UPROPERTY()
	FString Scope;
	
	UPROPERTY()
	int64 ExpiresIn;

public:
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Access Token Verify Result")
	UPARAM(DisplayName = "Client Id") FString GetClientId() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Access Token Verify Result")
	UPARAM(DisplayName = "Scope") FString GetScope() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Access Token")
	UPARAM(DisplayName = "Expires In") int64 GetExpiresIn() const;
};
