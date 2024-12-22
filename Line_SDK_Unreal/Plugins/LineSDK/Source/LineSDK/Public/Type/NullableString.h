#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#endif

#include "NullableString.generated.h"

USTRUCT()
struct LINESDK_API FNullableString
{
	GENERATED_USTRUCT_BODY()
	
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

	bool IsNull() const { return bIsNull; }
	
	const FString& GetValue() const { return Value; }

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
