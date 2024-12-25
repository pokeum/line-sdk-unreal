#pragma once

#include "CoreMinimal.h"
#include "AccessToken.h"
#include "UserProfile.h"
#include "Utils/Response.h"
#include "LoginResult.generated.h"

UCLASS()
class LINESDK_API ULoginResult : public UResponse
{
	GENERATED_BODY()

public:
	static ULoginResult* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Json") FString ToJson() const;
	
private:
	UPROPERTY()
	UAccessToken* AccessToken;
	
	UPROPERTY()
	FString Scope;

	UPROPERTY()
	UUserProfile* UserProfile;

	UPROPERTY()
	bool FriendshipStatusChanged;

	UPROPERTY()
	FString IDTokenNonce;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Access Token") UAccessToken* GetAccessToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Scopes") TArray<FString> GetScopes() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "User Profile") UUserProfile* GetUserProfile() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Is Friendship Status Changed") bool IsFriendshipStatusChanged() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Id Token Nonce") FString GetIdTokenNonce() const;
};
