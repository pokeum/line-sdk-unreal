#pragma once

#include "Type/NullableString.h"

class FLineSDKInterface
{
public:
	virtual ~FLineSDKInterface() = default;
	
	virtual void Login(
		const FString& Scope,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce,
		const FString& Identifier
	) = 0;
	
	virtual void Logout(const FString& Identifier) = 0;

	virtual void RefreshAccessToken(const FString& Identifier) = 0;

	virtual void RevokeAccessToken(const FString& Identifier) = 0;

	virtual void VerifyAccessToken(const FString& Identifier) = 0;

	virtual void GetProfile(const FString&  Identifier) = 0;

	virtual void GetBotFriendshipStatus(const FString& Identifier) = 0;

	virtual FString GetCurrentAccessToken() = 0;
};
