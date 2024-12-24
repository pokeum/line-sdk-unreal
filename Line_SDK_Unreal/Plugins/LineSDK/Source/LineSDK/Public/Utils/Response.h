#pragma once

#include "Response.generated.h"

UCLASS()
class LINESDK_API UResponse : public UObject
{
	GENERATED_BODY()

public:
	virtual ~UResponse() override { }

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