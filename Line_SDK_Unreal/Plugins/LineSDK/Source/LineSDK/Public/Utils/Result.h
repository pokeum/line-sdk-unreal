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
	/**
	 * Creates a new success result with an input value.
	 * @param Value The value represents a successful result.
	 * @return A pointer to a newly initialized `UResult` with the provided success value.
	 */
	static UResult* HandleOk(UResponse* Value);

	/**
	 * Creates a new failure result with an input error.
	 * @param Error The error represents a failed result.
	 * @return A pointer to a newly initialized `UResult` with an error.
	 */
	static UResult* HandleError(UError* Error);
	
	/**
	 * Matches when the result represents a success value.
	 * @param OnMatched The function to be called if `this` is a success value.
	 */
	void MatchOk(const TFunction<void(const UResponse*)>& OnMatched) const;

	/**
	 * Matches when the result represents a failure value.
	 * @param OnMatched The function to be called if `this` is a failure value.
	 */
	void MatchError(const TFunction<void(const UError*)>& OnMatched) const;

	/**
	 * Matches either when the result represents a success value or a failure value.
	 * @param OnMatchedOk The function to be called if `this` is a success value.
	 * @param OnMatchedError The function to be called if `this` is a failure value.
	 */
	void Match(const TFunction<void(const UResponse*)>& OnMatchedOk, const TFunction<void(const UError*)>& OnMatchedError) const;

private:
	UPROPERTY()
	UResponse* Value;
	
	UPROPERTY()
	UError* Error;

	UPROPERTY()
	bool bSuccess;

public:
	/**
	 * @return Whether this result represents a success value or not.
	 */
	bool IsSuccess() const;

	/**
	 * @return Whether this result represents a failure value or not.
	 */
	bool IsFailure() const;

	/** @cond HIDDEN_SYMBOLS */
protected:
	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match Ok"))
	void MatchOkBlueprint(const FLineSDKOnSuccessListener OnSuccess) const;

	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match Error"))
	void MatchErrorBlueprint(const FLineSDKOnFailureListener OnFailure) const;

	UFUNCTION(BlueprintCallable, Category = "Line|Result", meta = (DisplayName = "Match"))
	void MatchBlueprint(const FLineSDKOnSuccessListener OnSuccess, const FLineSDKOnFailureListener OnFailure) const;
	/** @endcond */
};
