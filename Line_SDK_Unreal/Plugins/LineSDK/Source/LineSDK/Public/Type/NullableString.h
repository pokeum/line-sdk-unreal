#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#endif

#include "NullableString.generated.h"

/**
 * Represents a nullable string
 */
USTRUCT()
struct LINESDK_API FNullableString
{
	GENERATED_USTRUCT_BODY()

	/** @cond HIDDEN_SYMBOLS */
	
	FNullableString() : bIsNull(true) { }
	
	FNullableString(const FNullableString&)				= default;
	FNullableString(FNullableString&&)					= default;
	
	FNullableString& operator=(FNullableString&&)		= default;
	FNullableString& operator=(const FNullableString&)	= default;
	
	explicit FNullableString(const FString& InString)	: bIsNull(false), Value(InString) { }
	explicit FNullableString(FString&& InString)		: bIsNull(false), Value(MoveTemp(InString)) { }
	
	FNullableString& operator=(const FString& InString)
	{
		bIsNull = false; Value = InString;
		return *this;
	}
	
	FNullableString& operator=(FString&& InString)
	{
		bIsNull = false; Value = InString;
		return *this;
	}
	
	/** @endcond */

	/**
	 * Checks if the object is in a null state.
	 * @return `true` if the object is null; `false` otherwise.
	 */
	bool IsNull() const { return bIsNull; }

	/**
	 * Get the value associated with `this` object.
	 * This method will assert that the value is not null before returning it.
	 * @return A stored string value, if the value is not null.
	 * <example>
	 * **Example usage**
	 * @code
	 * FNullableString NullableString;
	 * if (NullableString.IsNull() == false)
	 * {
	 *     NullableString.GetValue();
	 * }
	 * @endcode 
	 * </example>
	 */
	const FString& GetValue() const
	{
		// Ensure value is not null
		check(bIsNull == false);
		// Safe to proceed if value is not null
		return Value;
	}

#if PLATFORM_ANDROID
	/** Convert FNullableString to JNI jstring */
	jstring GetJavaString(JNIEnv* Env) const
	{
		return bIsNull
			? nullptr
			: Env->NewStringUTF(TCHAR_TO_UTF8(*Value));
	}
#endif
#ifdef __OBJC__
	/** Convert FNullableString to Objective-C NSString */
	NSString* GetNSString() const
	{
		return bIsNull
			? nil
			: Value.GetNSString();
	}
#endif

private:
	bool		bIsNull;
	FString		Value;
};
