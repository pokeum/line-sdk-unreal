#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "AccessTokenVerifyResult.generated.h"

/**
 * Represents a response to the token verification API.
 */
UCLASS()
class LINESDK_API UAccessTokenVerifyResult : public UResponse
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UAccessTokenVerifyResult` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UAccessTokenVerifyResult` object.
	 */
	static UAccessTokenVerifyResult* FromJson(const FString& Json);

	/**
	 * Converts the `UAccessTokenVerifyResult` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UAccessTokenVerifyResult` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;

private:
	UPROPERTY()
	FString ClientId;
	
	UPROPERTY()
	FString Scope;
	
	UPROPERTY()
	int64 ExpiresIn;

public:
	/**
	 * Gets the channel ID bound to the access token.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Channel Id")
	/** @endcond */
	FString GetChannelId() const;

	/**
	 * Gets string specifying the access token's scope.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Scope")
	/** @endcond */
	FString GetScope() const;

	/**
	 * Gets number of seconds until the access token expires.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token Verify Result")
	UPARAM(DisplayName = "Expires In")
	/** @endcond */
	int64 GetExpiresIn() const;
};
