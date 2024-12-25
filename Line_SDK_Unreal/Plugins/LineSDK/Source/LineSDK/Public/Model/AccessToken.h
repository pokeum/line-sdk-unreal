#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "AccessToken.generated.h"

UCLASS()
class LINESDK_API UAccessToken : public UResponse
{
	GENERATED_BODY()

public:
	static UAccessToken* FromJson(const FString& Json);
	
	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Json") FString ToJson() const;
	
private:
	UPROPERTY()
	FString AccessToken;

	UPROPERTY()
	int64 ExpiresIn;

	UPROPERTY()
	FString IdToken;

	UPROPERTY()
	FString RefreshToken;

	UPROPERTY()
	FString Scope;

	UPROPERTY()
	FString TokenType;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Access Token") FString GetAccessToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Expires In") int64 GetExpiresIn() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Id Token") FString GetIdToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Refresh Token") FString GetRefreshToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Scope") FString GetScope() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Token Type") FString GetTokenType() const;
};
