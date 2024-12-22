#pragma once

#include "CoreMinimal.h"
#include "Unit.generated.h"

/**
 * Represents an empty result value.
 * It represents a success signal without any data.
 */
UCLASS()
class LINESDK_API UUnit : public UObject
{
	GENERATED_BODY()

public:
	static UUnit* Construct()
	{
		return NewObject<UUnit>(GetTransientPackage(), StaticClass());
	}
};
