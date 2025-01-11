#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Utils/Response.h"
#include "AccessToken.generated.h"

/**
 * Represents an access token which is used to access the LINE Platform. Most API calls
 * to the LINE Platform require an access token as evidence of successful authorization.
 * A valid access token is issued after the user grants your app the permissions that
 * your app requests. An access token is bound to permissions (scopes) that define the
 * API endpoints that you can access. Choose the permissions for your channel in the
 * LINE Developers site and set them in the login method used in your app.
 *
 * An access token expires after a certain period. `ExpiresIn` specifies the time until
 * which this access token expires.
 *
 * By default, the LINE SDK stores access tokens in a secure place on the device running
 * your app and obtains authorization when you access the LINE Platform through the
 * framework request methods.
 *
 * Don't try to create an access token yourself. You can get the stored access token with
 * fewer properties with `FLineSDK::GetCurrentAccessToken()`.
 */
UCLASS()
class LINESDK_API UAccessToken : public UResponse
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UAccessToken` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UAccessToken` object.
	 */
	static UAccessToken* FromJson(const FString& Json);

	/**
	 * Converts the `UAccessToken` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UAccessToken` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;
	
private:
	UPROPERTY()
	FString AccessToken;
	
	UPROPERTY()
	int64 ExpiresIn;
	
	UPROPERTY()
	FString IdToken;
	
	UPROPERTY()
	FString RefreshToken;
	
	UPROPERTY()
	FString Scope;
	
	UPROPERTY()
	FString TokenType;

public:
	/**
	 * Gets the value of the access token.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Value")
	/** @endcond */
	FString GetValue() const;

	/**
	 * Gets number of seconds until the access token expires.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Expires In")
	/** @endcond */
	int64 GetExpiresIn() const;

	/**
	 * Gets the raw string value of the ID token bound to the access token.
	 * @note The value exists only if the access token is obtained with the "openID" permission.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Id Token Raw")
	/** @endcond */
	FString GetIdTokenRaw() const;

	/**
	 * Gets the refresh token bound to the access token.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Refresh Token")
	/** @endcond */
	FString GetRefreshToken() const;

	/**
	 * Gets permissions granted by the user.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Scope")
	/** @endcond */
	FString GetScope() const;

	/**
	 * Gets the expected authorization type when this token is used in a request header.
	 * @note Fixed to "Bearer" for now.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Access Token")
	UPARAM(DisplayName = "Token Type")
	/** @endcond */
	FString GetTokenType() const;
};
