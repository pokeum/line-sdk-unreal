#pragma once

class LineSDKInterface
{
public:
	virtual ~LineSDKInterface() = default;
	
	virtual void SetupSDK(const FString& ChannelId, const FString& UniversalLinkURL) = 0;
	virtual void Login(const FString& Scope, bool OnlyWebLogin, const FString& BotPrompt, const FString& TokenNonce, const FString& Identifier) = 0;
	virtual void Logout(const FString& Identifier) = 0;
	virtual void RefreshAccessToken(const FString& Identifier) = 0;
	virtual void RevokeAccessToken(const FString& Identifier) = 0;
	virtual void VerifyAccessToken(const FString& Identifier) = 0;
	virtual void GetProfile(const FString&  Identifier) = 0;
	virtual void GetBotFriendshipStatus(const FString& Identifier) = 0;
	virtual FString GetCurrentAccessToken() = 0;
};