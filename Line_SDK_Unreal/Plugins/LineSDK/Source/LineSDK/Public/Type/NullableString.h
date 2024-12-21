#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

private:
	bool		bIsNull;
	FString		Value;
};
