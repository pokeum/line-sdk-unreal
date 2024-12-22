#pragma once

#include "Result.h"
#include "Model/AccessTokenVerifyResult.h"
#include "Model/Error.h"
#include "Result_AccessTokenVerifyResult.generated.h"

UCLASS()
class LINESDK_API UResult_AccessTokenVerifyResult : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const UAccessTokenVerifyResult*)>& OnMatched) const;

	void Match(
		const TFunction<void(const UAccessTokenVerifyResult*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};