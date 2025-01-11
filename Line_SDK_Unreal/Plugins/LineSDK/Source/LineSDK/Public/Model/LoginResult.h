#pragma once

#include "CoreMinimal.h"
#include "AccessToken.h"
#include "UserProfile.h"
#include "Utils/Response.h"
#include "LoginResult.generated.h"

/**
 * Represents a result of a successful login.
 */
UCLASS()
class LINESDK_API ULoginResult : public UResponse
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `ULoginResult` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `ULoginResult` object.
	 */
	static ULoginResult* FromJson(const FString& Json);

	/**
	 * Converts the `ULoginResult` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `ULoginResult` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Json")
	/** @endcond */
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
	/**
	 * @return The access token obtained by the login process.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Access Token")
	/** @endcond */
	UAccessToken* GetAccessToken() const;

	/**
	 * @return The scopes bound to the `UAccessToken` object by the authorization process.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Scopes")
	/** @endcond */
	TArray<FString> GetScopes() const;

	/**
	 * @return The user profile, which includes user ID, display name, and so on.
	 * @note The value exists only when the "profile" scope is set in the authorization request.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "User Profile")
	/** @endcond */
	UUserProfile* GetUserProfile() const;
	
	/**
	 * @return The friendship status between the user and the LINE Official Account, which may have changed during the login process.
	 * This value is always `false` if the `BotPrompt` is not specified as part of the option when the user logs in.
	 * For more information, see "Add a LINE Official Account as a friend when logged in (add friend option)"
	 * at https://developers.line.biz/en/docs/line-login/link-a-bot/
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Is Friendship Status Changed")
	/** @endcond */
	bool IsFriendshipStatusChanged() const;

	/**
	 * @return The `nonce` value when requesting an ID token during the login process.
	 * Use this value as a parameter when you verify the ID token against the LINE server.
	 * This value is always `false` if you don't have the `.openID` permission.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Result")
	UPARAM(DisplayName = "Id Token Nonce")
	/** @endcond */
	FString GetIdTokenNonce() const;
};
