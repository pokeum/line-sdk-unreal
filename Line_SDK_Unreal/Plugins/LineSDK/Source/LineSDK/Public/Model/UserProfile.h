#pragma once

#include "CoreMinimal.h"
#include "Utils/Response.h"
#include "UserProfile.generated.h"

/**
 * Represents a user profile used in LINE SDK.
 */
UCLASS()
class LINESDK_API UUserProfile : public UResponse
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UUserProfile` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UUserProfile` object.
	 */
	static UUserProfile* FromJson(const FString& Json);

	/**
	 * Converts the `UUserProfile` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UUserProfile` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;

private:
	UPROPERTY()
	FString UserId;

	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FString PictureUrl;

	UPROPERTY()
	FString StatusMessage;

public:
	/**
	 * Gets the user ID of the current authorized user.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "User Id")
	/** @endcond */
	FString GetUserId() const;

	/**
	 * Gets the display name of the current authorized user.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Display Name")
	/** @endcond */
	FString GetDisplayName() const;
	
	/**
	 * Gets the status message of the current authorized user.
	 * Empty if the user has not set a status message.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Status Message")
	/** @endcond */
	FString GetStatusMessage() const;

	/**
	 * Gets the profile image URL of the current authorized user.
	 * Empty if the user has not set a profile image.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Picture Url")
	/** @endcond */
	FString GetPictureUrl() const;

	/**
	 * Gets the large profile image URL of the current authorized user.
	 * Empty if the user has not set a profile image.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Picture Url Large")
	/** @endcond */
	FString GetPictureUrlLarge() const;

	/**
	 * Gets the small profile image URL of the current authorized user.
	 * Empty if the user has not set a profile image.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|User Profile")
	UPARAM(DisplayName = "Picture Url Small")
	/** @endcond */
	FString GetPictureUrlSmall() const;
};