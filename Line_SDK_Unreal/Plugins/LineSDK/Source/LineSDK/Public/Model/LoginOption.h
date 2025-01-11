#pragma once

#include "CoreMinimal.h"
#include "Type/NullableString.h"
#include "LoginOption.generated.h"

/**
 * Represents options for logging in to the LINE Platform.
 */
UCLASS(Blueprintable)
class LINESDK_API ULoginOption : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Constructs a new `ULoginOption` object.
	 * @return A pointer to a new instance of `ULoginOption`.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Option", meta = (DisplayName = "Create Login Option"))
	/** @endcond */
	static
	/** @cond Doxygen_Suppress_Param */
	UPARAM(DisplayName = "Login Option")
	/** @endcond */
	ULoginOption* Construct();

	/**
	 * Sets the login option to use only the web authentication flow.
	 * @param OnlyWebLogin Set to `true` to enable only the web authentication flow;
	 * set to `false` to allow the LINE app-to-app authentication flow.
	 * @return The `ULoginOption` pointer for method chaining.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target")
	/** @endcond */
	ULoginOption* SetOnlyWebLogin(const bool OnlyWebLogin);

	/**
	 * Gets the current setting for web-only authentication.
	 * @return A boolean value indicating whether only the web authentication flow is enabled.
	 */
	bool GetOnlyWebLogin() const;

	/**
	 * Sets the strategy for showing the "adding the LINE Official Account as friend" option on the consent screen.
	 * @param BotPrompt A string specifying the prompt strategy. Accepted values are:
     * - "normal": Includes an option to add a LINE Official Account as friend on the consent screen.
     * - "aggressive": Opens a new screen to add a LINE Official Account as a friend after the user agrees to the permissions on the consent screen.
     * @return The `ULoginOption` pointer for method chaining.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target")
	/** @endcond */
	ULoginOption* SetBotPrompt(const FString& BotPrompt);

	/**
	 * Gets the current bot prompt strategy used on the consent screen.
	 * @return A `FNullableString` containing the bot prompt strategy. If no strategy is set, value is null.
	 */
	FNullableString GetBotPrompt() const;

	/**
	 * Sets the nonce value for ID token verification.
	 * @param IDTokenNonce A string representing the nonce value.
	 * <value>
	 * This value is used when requesting user authorization with `.openID` permission to prevent replay attacks
	 * to your backend server. If not set, LINE SDK will generate a random value as the token nonce. Whether set
	 * or not, LINE SDK verifies against the nonce value in received ID token locally.
	 * </value>
	 * @return The `ULoginOption` pointer for method chaining.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Login Option")
	UPARAM(DisplayName = "Return Target")
	/** @endcond */
	ULoginOption* SetIDTokenNonce(const FString& IDTokenNonce);

	/**
	 * Gets the current nonce value used for ID token verification.
	 * @return An `FNullableString` containing the nonce value if set, or null if no nonce has been set.
	 */
	FNullableString GetIDTokenNonce() const;

private:
	UPROPERTY()
	bool bOnlyWebLogin = false;

	UPROPERTY()
	FNullableString StrBotPrompt;

	UPROPERTY()
	FNullableString StrIDTokenNonce;
};