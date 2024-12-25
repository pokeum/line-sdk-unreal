#pragma once

#include "Response.h"
#include "Model/Error.h"
#include "Result.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FLineSDKOnSuccessListener, const UResponse*, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLineSDKOnFailureListener, const UError*, Error);

UCLASS()
class LINESDK_API UResult : public UObject
{
	GENERATED_BODY()

public:
	static UResult* HandleOk(UResponse* Value);

	static UResult* HandleError(UError* Error);

	void MatchOk(const TFunction<void(const UResponse*)>& OnMatched) const;

	void MatchError(const TFunction<void(const UError*)>& OnMatched) const;

	void Match(const TFunction<void(const UResponse*)>& OnMatchedOk, const TFunction<void(const UError*)>& OnMatchedError) const;

private:
	UPROPERTY()
	UResponse* Value;
	
	UPROPERTY()
	UError* Error;

	UPROPERTY()
	bool bSuccess;
	
	bool IsSuccess() const;
	
	bool IsFailure() const;

protected:
	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match Ok"))
	void MatchOkBlueprint(const FLineSDKOnSuccessListener OnSuccess) const;

	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match Error"))
	void MatchErrorBlueprint(const FLineSDKOnFailureListener OnFailure) const;
	
	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match"))
	void MatchBlueprint(const FLineSDKOnSuccessListener OnSuccess, const FLineSDKOnFailureListener OnFailure) const;
};
