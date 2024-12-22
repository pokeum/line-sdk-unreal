#pragma once

#include "Interface/LineSDKInterface.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

class FLineSDKInterfaceAndroid final : public FLineSDKInterface
{
public:
	FLineSDKInterfaceAndroid();
	
	virtual ~FLineSDKInterfaceAndroid() override;

	virtual void Login(
		const FString& Identifier,
		const FString& Scope,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce
	) override;
	
	virtual void Logout(const FString& Identifier) override;

	virtual void RefreshAccessToken(const FString& Identifier) override;

	virtual void RevokeAccessToken(const FString& Identifier) override;

	virtual void VerifyAccessToken(const FString& Identifier) override;

	virtual void GetProfile(const FString&  Identifier) override;

	virtual void GetBotFriendshipStatus(const FString& Identifier) override;

	virtual FString GetCurrentAccessToken() override;

private:
	static void GameActivityCallMethod_OneParam_String(const ANSICHAR* MethodName, const FString& Param);
	
	static FString GameActivityCallMethod_Return_String(const ANSICHAR* MethodName);
};
