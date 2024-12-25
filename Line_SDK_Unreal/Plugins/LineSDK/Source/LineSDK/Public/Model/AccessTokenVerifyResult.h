#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "AccessTokenVerifyResult.generated.h"

UCLASS()
class LINESDK_API UAccessTokenVerifyResult : public UResponse
{
	GENERATED_BODY()

public:
	static UAccessTokenVerifyResult* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Json") FString ToJson() const;

private:
	UPROPERTY()
	FString ClientId;
	
	UPROPERTY()
	FString Scope;
	
	UPROPERTY()
	int64 ExpiresIn;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Channel Id") FString GetChannelId() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Scope") FString GetScope() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Expires In") int64 GetExpiresIn() const;
};
