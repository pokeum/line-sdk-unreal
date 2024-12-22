#include "Utils/Result/Result_UserProfile.h"

#include "LineSDK.h"

void UResult_UserProfile::MatchOk(const TFunction<void(const UUserProfile*)>& OnMatched) const
{
	if (IsFailure()) return;
	
	if (OnMatched)
	{
		OnMatched(Cast<UUserProfile>(Value));
	}
	else
	{
		FLineSDK::Logger(TEXT("Match callback is null!"));
	}
}

void UResult_UserProfile::Match(
	const TFunction<void(const UUserProfile*)>& OnMatchedOk,
	const TFunction<void(const UError*)>& OnMatchedError
) const
{
	MatchOk(OnMatchedOk);
	MatchError(OnMatchedError);
}