#pragma once

#include "Interface/LineSDKInterface.h"

class FLineSDKInterfacePlaceholder final : public FLineSDKInterface
{
public:
	virtual void Login(
		const FString& Identifier,
		const FString& Scope,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce
	) override
	{
		
	}
	
	virtual void Logout(const FString& Identifier) override
	{
		
	}

	virtual void RefreshAccessToken(const FString& Identifier) override
	{
		
	}

	virtual void RevokeAccessToken(const FString& Identifier) override
	{
		
	}

	virtual void VerifyAccessToken(const FString& Identifier) override
	{
		
	}

	virtual void GetProfile(const FString&  Identifier) override
	{
		
	}

	virtual void GetBotFriendshipStatus(const FString& Identifier) override
	{
		
	}
	
	virtual FString GetCurrentAccessToken() override
	{
		return FString();
	}
};
