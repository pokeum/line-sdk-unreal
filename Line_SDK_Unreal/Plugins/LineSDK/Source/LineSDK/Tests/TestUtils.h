#pragma once

#include <string>

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LineSDKTest, Log, All);
#define LINE_SDK_TEST_LOG(Format, ...) UE_LOG(LineSDKTest, Warning, TEXT("%s"), *FString::Printf(Format, ##__VA_ARGS__))

class TestUtils
{
public:
	static FString GetStringFromFile(const FString& FileName);
};
