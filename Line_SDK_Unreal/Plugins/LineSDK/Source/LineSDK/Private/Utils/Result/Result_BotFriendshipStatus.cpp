#include "Utils/Result/Result_BotFriendshipStatus.h"

#include "LineSDK.h"

void UResult_BotFriendshipStatus::MatchOk(const TFunction<void(const UBotFriendshipStatus*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<UBotFriendshipStatus>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

void UResult_BotFriendshipStatus::Match(
	const TFunction<void(const UBotFriendshipStatus*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}