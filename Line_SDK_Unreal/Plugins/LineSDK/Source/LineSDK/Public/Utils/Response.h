#pragma once

#include "Response.generated.h"

/**
 * Represents a generic response from the LINE Platform APIs.
 */
UCLASS(Blueprintable)
class LINESDK_API UResponse : public UObject
{
	GENERATED_BODY()

public:
	/** @cond HIDDEN_SYMBOLS */
	virtual ~UResponse() override { }
	/** @endcond */

	/**
	 * Represents an empty result value.
	 * It represents a success signal without any data.
	 */
	static UResponse* Unit()
	{
		return NewObject<UResponse>(GetTransientPackage(), StaticClass());
	}
};

typedef UResponse UUnit;