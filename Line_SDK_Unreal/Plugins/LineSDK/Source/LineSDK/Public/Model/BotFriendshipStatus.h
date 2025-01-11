#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "BotFriendshipStatus.generated.h"

/**
 * Represents a response to a request for getting the friendship status of the user
 * and the LINE Official Account linked to your LINE Login channel.
 */
UCLASS()
class LINESDK_API UBotFriendshipStatus : public UResponse
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UBotFriendshipStatus` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UBotFriendshipStatus` object.
	 */
	static UBotFriendshipStatus* FromJson(const FString& Json);

	/**
	 * Converts the `UBotFriendshipStatus` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UBotFriendshipStatus` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Bot Friendship Status")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;

private:
	UPROPERTY()
	bool FriendFlag;

public:
	/**
	 * Gets the friendship status of the user and the LINE Official Account linked to your LINE Login channel.
	 * @return `true` if the user has added the LINE Official Account as a friend and has not blocked the LINE Official Account; `false` otherwise.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Bot Friendship Status")
	UPARAM(DisplayName = "Is Friend")
	/** @endcond */
	bool IsFriend() const;
};
