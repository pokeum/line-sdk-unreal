#pragma once

#include "Interface/LineSDKInterface.h"

class FLineSDKInterfaceAndroid final : public FLineSDKInterface
{
public:
	FLineSDKInterfaceAndroid();
	
	virtual ~FLineSDKInterfaceAndroid() override;
	
	virtual void Login(
		const FString& Scope,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce,
		const FString& Identifier
	) override;
	
	virtual void Logout(const FString& Identifier) override;

	virtual void RefreshAccessToken(const FString& Identifier) override;

	virtual void RevokeAccessToken(const FString& Identifier) override;

	virtual void VerifyAccessToken(const FString& Identifier) override;

	virtual void GetProfile(const FString&  Identifier) override;

	virtual void GetBotFriendshipStatus(const FString& Identifier) override;

	virtual FString GetCurrentAccessToken() override;
};
