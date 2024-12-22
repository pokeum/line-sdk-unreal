#pragma once

#include "CoreMinimal.h"
#include "Result.h"
#include "Result_UserProfile.generated.h"

UCLASS()
class LINESDK_API UResult_UserProfile : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const UUserProfile*)>& OnMatched) const;

	void Match(
		const TFunction<void(const UUserProfile*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};
