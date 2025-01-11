#pragma once

#pragma region Model Headers
#include "Model/AccessToken.h"
#include "Model/AccessTokenVerifyResult.h"
#include "Model/BotFriendshipStatus.h"
#include "Model/Error.h"
#include "Model/LoginOption.h"
#include "Model/LoginResult.h"
#include "Model/StoredAccessToken.h"
#include "Model/UserProfile.h"
#pragma endregion

#include "Utils/Result.h"
#include "LineSDK.generated.h"

#pragma region Line SDK Settings

UCLASS(config = Engine)
class ULineSDKSettings : public UObject
{
	GENERATED_BODY()

public:
	ULineSDKSettings(const FObjectInitializer& ObjectInitializer);

	/**
	 * The channel ID for your app.
	 */
	UPROPERTY(Config, EditAnywhere, Category = "Line SDK", meta = (DisplayName = "Channel ID"))
	FString ChannelID;

	/**
	 * 
	 */
	UPROPERTY(Config, EditAnywhere, Category = "Line SDK", meta = (DisplayName = "Universal Link URL"))
	FString UniversalLinkURL;
};

#pragma endregion

/**
 * Represents a login and token related manager for LINE SDK Login features.
 */
class LINESDK_API FLineSDK
{
public:
	/** @cond HIDDEN_SYMBOLS */
	static void Logger(const FString& Message);
	/** @endcond */

	/**
	 * Logs in to the LINE Platform with the specified scopes.
	 * @param Scopes The set of permissions requested by your app. If empty, the "profile" scope is used.
	 * @param Function The callback function to be invoked when the login process finishes.
	 */
	static void Login(const TArray<FString>& Scopes, const TFunction<void(const UResult*)>& Function);

	/**
	 * Logs in to the LINE Platform with the specified scopes and an option.
	 * @param Scopes The set of permissions requested by your app. If empty, the "profile" scope is used.
	 * @param Option The options used during the login process.
	 * @param Function The callback function to be invoked when the login process finishes.
	 */
	static void Login(const TArray<FString>& Scopes, const ULoginOption* Option, const TFunction<void(const UResult*)>& Function);

	/**
	 * Logs out the current user by revoking the access token.
	 * @param Function The callback function to be invoked when the logout process finishes.
	 */
	static void Logout(const TFunction<void(const UResult*)>& Function);

	/**
	 * Refreshes the current access token.
	 * @param Function The callback function to be invoked after this operation.
	 */
	static void RefreshAccessToken(const TFunction<void(const UResult*)>& Function);
	
	/**
	 * Revokes the current access token.
	 * @param Function The callback function to be invoked after this operation.
	 *
	 * @note After the access token is revoked, you cannot use it again to access the LINE Platform.
	 * The user must authorize your app again to issue a new access token before accessing the LINE Platform.
	 */
	static void RevokeAccessToken(const TFunction<void(const UResult*)>& Function);

	/**
	 * Verifies the current access token.
	 * @param Function The callback function to be invoked after this operation.
	 */
	static void VerifyAccessToken(const TFunction<void(const UResult*)>& Function);

	/**
	 * Gets the user’s profile.
	 * @param Function The callback function to be invoked after this operation.
	 *
	 * @note The "profile" scope is required to perform this operation.
	 */
	static void GetProfile(const TFunction<void(const UResult*)>& Function);

	/**
	 * Gets the friendship status of the user and the LINE Official Account linked to your LINE Login channel.
	 * @param Function The callback function to be invoked after this operation.
	 *
	 * @note The "profile" scope is required to perform this operation.
	 */
	static void GetBotFriendshipStatus(const TFunction<void(const UResult*)>& Function);

	/**
	 * Gets the current access token in use.
	 * @return A `UStoredAccessToken` object which contains the access token value currently in use.
	 */
	static UStoredAccessToken* GetCurrentAccessToken();
};