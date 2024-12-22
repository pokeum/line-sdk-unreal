#include "Model/LoginOption.h"

ULoginOption* ULoginOption::Construct()
{
	return NewObject<ULoginOption>(GetTransientPackage(), StaticClass());
}

ULoginOption* ULoginOption::SetOnlyWebLogin(const bool OnlyWebLogin)
{
	bOnlyWebLogin = OnlyWebLogin;
	return this;
}
	
bool ULoginOption::GetOnlyWebLogin() const
{
	return bOnlyWebLogin;
}

ULoginOption* ULoginOption::SetBotPrompt(const FString& BotPrompt)
{
	StrBotPrompt = BotPrompt;
	return this;
}

FNullableString ULoginOption::GetBotPrompt() const
{
	return StrBotPrompt;
}

ULoginOption* ULoginOption::SetIDTokenNonce(const FString& IDTokenNonce)
{
	StrIDTokenNonce = IDTokenNonce;
	return this;
}

FNullableString ULoginOption::GetIDTokenNonce() const
{
	return StrIDTokenNonce;
}