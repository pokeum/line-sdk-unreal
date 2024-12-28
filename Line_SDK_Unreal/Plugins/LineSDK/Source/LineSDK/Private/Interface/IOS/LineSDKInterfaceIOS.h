#pragma once

#include "Interface/LineSDKInterface.h"

class FLineSDKInterfaceIOS final : public FLineSDKInterface
{
public:
	FLineSDKInterfaceIOS();
	
	virtual ~FLineSDKInterfaceIOS() override;

	virtual void Logger(const FString& Message) override;

	virtual void SetupSDK() override;
	
	virtual void Login(
		const FString& Identifier,
		const FString& Scopes,
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
};
