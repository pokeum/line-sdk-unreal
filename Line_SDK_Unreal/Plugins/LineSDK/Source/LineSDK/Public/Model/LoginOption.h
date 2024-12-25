#pragma once

#include "CoreMinimal.h"
#include "Type/NullableString.h"
#include "LoginOption.generated.h"

UCLASS(Blueprintable)
class LINESDK_API ULoginOption : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Login Option", meta = (DisplayName = "Create Login Option"))
	static UPARAM(DisplayName = "Login Option") ULoginOption* Construct();

	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target") ULoginOption* SetOnlyWebLogin(const bool OnlyWebLogin);
	
	bool GetOnlyWebLogin() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target") ULoginOption* SetBotPrompt(const FString& BotPrompt);

	FNullableString GetBotPrompt() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target") ULoginOption* SetIDTokenNonce(const FString& IDTokenNonce);

	FNullableString GetIDTokenNonce() const;

private:
	UPROPERTY()
	bool bOnlyWebLogin = false;

	UPROPERTY()
	FNullableString StrBotPrompt;

	UPROPERTY()
	FNullableString StrIDTokenNonce;
};