#pragma once

#include <string>

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LineSDKUnreal, Log, All);

#define STD_TO_F_STRING(StdString) (FString((const TCHAR*)*FString(StdString.c_str())))

inline std::string ClassName(const std::string& PrettyFunction)
{
	const size_t Colons = PrettyFunction.find("::");
	if (Colons == std::string::npos)
		return "";
	const size_t Begin = PrettyFunction.substr(0, Colons).rfind(" ") + 1;
	const size_t End = Colons - Begin;
	return PrettyFunction.substr(Begin, End);
}

#ifdef _MSC_VER
#define LINE_SDK_UNREAL_LOG_CALL_INFO (FString(__FUNCTION__) + TEXT(" (line ") + FString::FromInt(__LINE__) + TEXT(")"))
#else
#define CLASS_NAME ClassName(__PRETTY_FUNCTION__)
#define LINE_SDK_UNREAL_LOG_CALL_INFO \
	(STD_TO_F_STRING(CLASS_NAME) + TEXT("::") + FString(__FUNCTION__) + TEXT(" (line ") + FString::FromInt(__LINE__) + TEXT(")"))
#endif
#define LINE_SDK_UNREAL_LOG(Verbosity, Format, ...) \
	UE_LOG(LineSDKUnreal, Verbosity, TEXT("%s \n\t at %s"), *FString::Printf(Format, ##__VA_ARGS__), *LINE_SDK_UNREAL_LOG_CALL_INFO)