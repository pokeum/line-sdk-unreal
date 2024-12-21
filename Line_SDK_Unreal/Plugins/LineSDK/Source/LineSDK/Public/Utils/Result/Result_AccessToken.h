#pragma once

#include "Result.h"
#include "Model/AccessToken.h"
#include "Model/Error.h"
#include "Result_AccessToken.generated.h"

UCLASS()
class LINESDK_API UResult_AccessToken : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const UAccessToken*)>& OnMatched) const;

	void Match(
		const TFunction<void(const UAccessToken*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};