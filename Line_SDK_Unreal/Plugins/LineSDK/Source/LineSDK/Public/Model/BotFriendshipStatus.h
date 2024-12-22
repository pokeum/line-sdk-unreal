#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BotFriendshipStatus.generated.h"

UCLASS()
class LINESDK_API UBotFriendshipStatus : public UObject
{
	GENERATED_BODY()

public:
	static UBotFriendshipStatus* FromJson(const FString& Json);

	TSharedPtr<FJsonObject> ToJsonObject() const;

	FString ToJson() const;

private:
	UPROPERTY()
	bool FriendFlag;

public:
	UFUNCTION(BlueprintCallable, Category = "Line SDK|Bot Friendship Status")
	UPARAM(DisplayName = "Friend Flag") bool GetFriendFlag() const;
};
