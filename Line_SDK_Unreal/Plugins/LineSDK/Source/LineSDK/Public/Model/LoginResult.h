#pragma once

#include "CoreMinimal.h"
#include "AccessToken.h"
#include "UserProfile.h"
#include "LoginResult.generated.h"

UCLASS()
class LINESDK_API ULoginResult : public UObject
{
	GENERATED_BODY()

public:
	static ULoginResult* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	FString ToJson() const;
	
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
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Login Result")
	UPARAM(DisplayName = "Access Token") UAccessToken* GetAccessToken() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Login Result")
	UPARAM(DisplayName = "Scope") FString GetScope() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Login Result")
	UPARAM(DisplayName = "User Profile") UUserProfile* GetUserProfile() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Login Result")
	UPARAM(DisplayName = "Friendship Status Changed") bool GetFriendshipStatusChanged() const;

	UFUNCTION(BlueprintCallable, Category = "Line SDK|Login Result")
	UPARAM(DisplayName = "ID Token Nonce") FString GetIDTokenNonce() const;
};
