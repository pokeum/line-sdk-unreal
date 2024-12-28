#pragma once

#include "Interface/LineSDKInterface.h"
#include "Utils/Helpers.h"

class FLineSDKInterfacePlaceholder final : public FLineSDKInterface
{
public:
	virtual void Logger(const FString& Message) override
	{
		FColor Color(153, 153, 0, 255);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, Color, FString::Printf(TEXT("[LineSDK] %s"), *Message));
	}

	virtual void SetupSDK() override
	{
	}
	
	virtual void Login(
		const FString& Identifier,
		const FString& Scopes,
		bool OnlyWebLogin,
		const FNullableString& BotPrompt,
		const FNullableString& TokenNonce
	) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}
	
	virtual void Logout(const FString& Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}

	virtual void RefreshAccessToken(const FString& Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}

	virtual void RevokeAccessToken(const FString& Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}

	virtual void VerifyAccessToken(const FString& Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}

	virtual void GetProfile(const FString&  Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}

	virtual void GetBotFriendshipStatus(const FString& Identifier) override
	{
		Helpers::IsInvalidRuntime(Identifier);
	}
	
	virtual FString GetCurrentAccessToken() override
	{
		return FString();
	}
};
