#pragma once

#include "LineSDK.generated.h"

#pragma region Line SDK Settings

UCLASS(config = Engine)
class ULineSDKSettings : public UObject
{
	GENERATED_BODY()

public:
	ULineSDKSettings(const FObjectInitializer& ObjectInitializer);

	/// <summary>
	/// The channel ID for your app.
	/// </summary>
	UPROPERTY(Config, EditAnywhere, Category = "Line SDK", meta = (DisplayName = "Channel ID"))
	FString ChannelID;

	UPROPERTY(Config, EditAnywhere, Category = "Line SDK", meta = (DisplayName = "Universal Link URL"))
	FString UniversalLinkURL;
};

#pragma endregion


class LINESDK_API FLineSDK
{
public:
	static void SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL);
	static void Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier);
	static void Logout(const FString& Identifier);
	static void RefreshAccessToken(const FString& Identifier);
	static void RevokeAccessToken(const FString& Identifier);
	static void VerifyAccessToken(const FString& Identifier);
	static void GetProfile(const FString&  Identifier);
	static void GetBotFriendshipStatus(const FString& Identifier);
	static FString GetCurrentAccessToken();
};