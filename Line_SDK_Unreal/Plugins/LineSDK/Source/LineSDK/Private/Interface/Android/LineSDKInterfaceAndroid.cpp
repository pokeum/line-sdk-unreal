#include "LineSDKInterfaceAndroid.h"

#include "LineSDKConfig.h"

FLineSDKInterfaceAndroid::FLineSDKInterfaceAndroid()
{
	SetupSDK();
}

FLineSDKInterfaceAndroid::~FLineSDKInterfaceAndroid()
{
	
}

void FLineSDKInterfaceAndroid::Logger(const FString& Message)
{
	GameActivityCallMethod_OneParam_String("lineSdk_logger", Message);
}

void FLineSDKInterfaceAndroid::Login(
	const FString& Identifier,
	const FString& Scopes,
	bool OnlyWebLogin,
	const FNullableString& BotPrompt,
	const FNullableString& TokenNonce
)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID Method = FJavaWrapper::FindMethod(Env,
			FJavaWrapper::GameActivityClassID,
			"lineSdk_login",
			"(Ljava/lang/String;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,
			Env->NewStringUTF(TCHAR_TO_UTF8(*Identifier)),
			Env->NewStringUTF(TCHAR_TO_UTF8(*Scopes)),
			(OnlyWebLogin ? JNI_TRUE : JNI_FALSE),
			BotPrompt.GetJavaString(Env),
			TokenNonce.GetJavaString(Env)
		);
	}
#endif
}

void FLineSDKInterfaceAndroid::SetupSDK()
{
	GameActivityCallMethod_OneParam_String("lineSdk_setupSdk", LineSDKConfig::ChannelID);
}
	
void FLineSDKInterfaceAndroid::Logout(const FString& Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_logout", Identifier);
}

void FLineSDKInterfaceAndroid::RefreshAccessToken(const FString& Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_refreshAccessToken", Identifier);
}

void FLineSDKInterfaceAndroid::RevokeAccessToken(const FString& Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_revokeAccessToken", Identifier);
}

void FLineSDKInterfaceAndroid::VerifyAccessToken(const FString& Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_verifyAccessToken", Identifier);
}

void FLineSDKInterfaceAndroid::GetProfile(const FString&  Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_getProfile", Identifier);
}

void FLineSDKInterfaceAndroid::GetBotFriendshipStatus(const FString& Identifier)
{
	GameActivityCallMethod_OneParam_String("lineSdk_getBotFriendshipStatus", Identifier);
}

FString FLineSDKInterfaceAndroid::GetCurrentAccessToken()
{
	return GameActivityCallMethod_Return_String("lineSdk_getCurrentAccessToken");
}

void FLineSDKInterfaceAndroid::GameActivityCallMethod_OneParam_String(const ANSICHAR* MethodName, const FString& Param)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID Method = FJavaWrapper::FindMethod(Env,
			FJavaWrapper::GameActivityClassID,
			MethodName, "(Ljava/lang/String;)V", false);
		jstring JString = Env->NewStringUTF(TCHAR_TO_UTF8(*Param));
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, JString);
	}
#endif
}

FString FLineSDKInterfaceAndroid::GameActivityCallMethod_Return_String(const ANSICHAR* MethodName)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID Method = FJavaWrapper::FindMethod(Env,
			FJavaWrapper::GameActivityClassID,
			MethodName, "()Ljava/lang/String;", false);
		jstring Return = (jstring) FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);

		if (Return == nullptr)
		{
			return FString();
		}

		const char* UTFString = Env->GetStringUTFChars(Return, nullptr);
		FString Result(UTF8_TO_TCHAR(UTFString));

		Env->ReleaseStringUTFChars(Return, UTFString);
		Env->DeleteLocalRef(Return);

		return Result;
	}
#endif
	return FString();
}