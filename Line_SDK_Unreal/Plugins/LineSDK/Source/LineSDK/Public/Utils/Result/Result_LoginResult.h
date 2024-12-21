#pragma once

#include "CoreMinimal.h"
#include "Result.h"
#include "Model/LoginResult.h"
#include "Result_LoginResult.generated.h"

UCLASS()
class LINESDK_API UResult_LoginResult : public UResult
{
	GENERATED_BODY()

public:
	void MatchOk(const TFunction<void(const ULoginResult*)>& OnMatched) const;

	void Match(
		const TFunction<void(const ULoginResult*)>& OnMatchedOk,
		const TFunction<void(const UError*)>& OnMatchedError
	) const;
};
