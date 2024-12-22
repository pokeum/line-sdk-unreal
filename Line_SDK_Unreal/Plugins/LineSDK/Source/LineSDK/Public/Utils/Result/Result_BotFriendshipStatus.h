#pragma once

#include "Result.h"
#include "Model/BotFriendshipStatus.h"
#include "Model/Error.h"
#include "Result_BotFriendshipStatus.generated.h"

UCLASS()
class LINESDK_API UResult_BotFriendshipStatus : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const UBotFriendshipStatus*)>& OnMatched) const;

	void Match(
		const TFunction<void(const UBotFriendshipStatus*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};