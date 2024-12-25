#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "BotFriendshipStatus.generated.h"

UCLASS()
class LINESDK_API UBotFriendshipStatus : public UResponse
{
	GENERATED_BODY()

public:
	static UBotFriendshipStatus* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	UFUNCTION(BlueprintCallable, Category = "Line|Bot Friendship Status")
	UPARAM(DisplayName = "Json") FString ToJson() const;

private:
	UPROPERTY()
	bool FriendFlag;

public:
	UFUNCTION(BlueprintCallable, Category = "Line|Bot Friendship Status")
	UPARAM(DisplayName = "Friend Flag") bool GetFriendFlag() const;
};
