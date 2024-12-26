#pragma once

#include "Type/NullableString.h"

class FLineSDKInterface
{
public:
	virtual ~FLineSDKInterface() = default;

	virtual void Logger(const FString& Message) = 0;

	virtual void SetupSDK() = 0;
	
	virtual void Login(
		const FString& Identifier,
		const FString& Scope,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce
	) = 0;
	
	virtual void Logout(const FString& Identifier) = 0;

	virtual void RefreshAccessToken(const FString& Identifier) = 0;

	virtual void RevokeAccessToken(const FString& Identifier) = 0;

	virtual void VerifyAccessToken(const FString& Identifier) = 0;

	virtual void GetProfile(const FString&  Identifier) = 0;

	virtual void GetBotFriendshipStatus(const FString& Identifier) = 0;

	virtual FString GetCurrentAccessToken() = 0;
};
