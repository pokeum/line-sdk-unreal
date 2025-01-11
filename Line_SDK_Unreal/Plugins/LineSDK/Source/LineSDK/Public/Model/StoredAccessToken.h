#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoredAccessToken.generated.h"

/**
 * Represents the access token stored on the device.
 */
UCLASS()
class LINESDK_API UStoredAccessToken : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UStoredAccessToken` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UStoredAccessToken` object.
	 */
	static UStoredAccessToken* FromJson(const FString& Json);

	/**
	 * Converts the `UStoredAccessToken` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UStoredAccessToken` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;

private:
	UPROPERTY()
	FString AccessToken;

	UPROPERTY()
	int64 ExpiresIn;

public:
	/**
	 * Gets the value of the access token.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Value")
	/** @endcond */
	FString GetValue() const;

	/**
	 * Gets expiration time of the token in seconds **at the time the token was created**.
	 * 
	 * This value is never updated. To get the up-to-date `ExpiresIn` value for a token,
	 * call `FLineSDK::VerifyAccessToken`.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Stored Access Token")
	UPARAM(DisplayName = "Expires In")
	/** @endcond */
	int64 GetExpiresIn() const;
};
