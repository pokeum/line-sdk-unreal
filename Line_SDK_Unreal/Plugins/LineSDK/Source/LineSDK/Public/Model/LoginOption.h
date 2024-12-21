#pragma once

#include "CoreMinimal.h"
#include "Type/NullableString.h"
#include "LoginOption.generated.h"

UCLASS()
class LINESDK_API ULoginOption : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool OnlyWebLogin = false;

	UPROPERTY()
	FNullableString BotPrompt;

	UPROPERTY()
	FNullableString IDTokenNonce;
};