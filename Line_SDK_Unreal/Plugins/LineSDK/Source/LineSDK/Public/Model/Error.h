#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Error.generated.h"

/**
 * Represents an error that happens in LINE SDK.
 */
UCLASS()
class LINESDK_API UError : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Creates an instance of `UError` from a JSON string.
	 * @param Json The JSON string containing the access token data.
	 * @return A pointer to the created `UError` object.
	 */
	static UError* FromJson(const FString& Json);

	/**
	 * Converts the `UError` object to a JSON object.
	 * @return A shared pointer to the serialized JSON object.
	 */
	TSharedPtr<FJsonObject> ToJsonObject() const;

	/**
	 * Converts the `UError` object to a JSON string.
	 * @return The serialized JSON string.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Json")
	/** @endcond */
	FString ToJson() const;
	
private:
	UPROPERTY()
	int32 Code;

	UPROPERTY()
	FString Message;

public:
	/**
	 * @return Error code showing the type of error.
	 * <value>
	 * This value differs per operating system. For details,
	 * see the reference documentation for LINE SDK for iOS Swift and LINE SDK for Android.
	 *
	 * - LINE SDK for iOS Swift: https://developers.line.biz/en/reference/ios-sdk-swift/Enums/LineSDKError.html
	 * - LINE SDK for Android: https://developers.line.biz/en/reference/android-sdk/reference/com/linecorp/linesdk/LineApiResponseCode.html
	 * </value> 
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Code")
	/** @endcond */
	int32 GetCode() const;

	/**
	 * @return Human-readable error description.
	 */
	/** @cond Doxygen_Suppress_Param */
	UFUNCTION(BlueprintCallable, Category = "Line|Error")
	UPARAM(DisplayName = "Message")
	/** @endcond */
	FString GetMessage() const;
};
