#pragma once

#include "Interface/LineSDKInterface.h"

class LineSDKInterfaceAndroid : public LineSDKInterface
{
public:
	LineSDKInterfaceAndroid();
	virtual ~LineSDKInterfaceAndroid() override;
	
	virtual void SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL) override;
	virtual void Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier) override;
	virtual void Logout(const FString& Identifier) override;
	virtual void RefreshAccessToken(const FString& Identifier) override;
	virtual void RevokeAccessToken(const FString& Identifier) override;
	virtual void VerifyAccessToken(const FString& Identifier) override;
	virtual void GetProfile(const FString&  Identifier) override;
	virtual void GetBotFriendshipStatus(const FString& Identifier) override;
	virtual FString GetCurrentAccessToken() override;
};