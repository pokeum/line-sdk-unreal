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
	
	static void Login(const TArray<FString>& Scopes, const TFunction<void(const UResult*)>& Function);
	
	static void Login(const TArray<FString>& Scopes, const ULoginOption* Option, const TFunction<void(const UResult*)>& Function);
	
	static void Logout(const TFunction<void(const UResult*)>& Function);

	static void RefreshAccessToken(const TFunction<void(const UResult*)>& Function);

	static void RevokeAccessToken(const TFunction<void(const UResult*)>& Function);

	static void VerifyAccessToken(const TFunction<void(const UResult*)>& Function);

	static void GetProfile(const TFunction<void(const UResult*)>& Function);

	static void GetBotFriendshipStatus(const TFunction<void(const UResult*)>& Function);

	static UStoredAccessToken* GetCurrentAccessToken();
};