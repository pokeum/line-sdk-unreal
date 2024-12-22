#pragma once

#include "Model/LoginOption.h"
#include "Utils/Result/Result_AccessToken.h"
#include "Utils/Result/Result_LoginResult.h"
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
	static void Logger(const FString& Message);
	
	static void Login(const TArray<FString>& Scopes, const TFunction<void(const UResult_LoginResult*)>& Function);
	
	static void Login(const TArray<FString>& Scopes, const ULoginOption* Option, const TFunction<void(const UResult_LoginResult*)>& Function);
	
	static void Logout();

	static void RefreshAccessToken(const TFunction<void(const UResult_AccessToken*)>& Function);

	static void RevokeAccessToken();

	static void VerifyAccessToken();

	static void GetProfile();

	static void GetBotFriendshipStatus();

	static FString GetCurrentAccessToken();
};