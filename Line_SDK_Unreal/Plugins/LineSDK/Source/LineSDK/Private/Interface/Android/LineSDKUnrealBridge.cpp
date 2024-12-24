#if PLATFORM_ANDROID

#include "API/LineAPI.h"

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

enum class CallbackPayload : unsigned int
{
	API_OK = 0,
	API_ERROR = 1
};

extern "C" {
	
	/*
	 * Class:     co_pokeum_linesdk_unreal_UnrealBridge
	 * Method:    sendMessage
	 * Signature: (ILjava/lang/String;)V
	 */
	JNIEXPORT void JNICALL Java_co_pokeum_linesdk_unreal_UnrealBridge_sendMessage
	(JNIEnv *Env, jclass Class, jint Type, jstring Message)
	{
		CallbackPayload PayloadType = static_cast<CallbackPayload>(Type);
		
		// Copies the new key into its final C string buffer
		const char* UTFString = Env->GetStringUTFChars(Message, nullptr);
		if (UTFString == nullptr) 
		{
			return;  /* OutOfMemoryError already thrown */
		}
		FString Result(UTF8_TO_TCHAR(UTFString));
		
		// release heap memory
		Env->ReleaseStringUTFChars(Message, UTFString);
		Env->DeleteLocalRef(Message);

		switch (PayloadType) 
		{
		case CallbackPayload::API_OK:
				FLineAPI::OnApiOk(Result);
				break;
		case CallbackPayload::API_ERROR:
				FLineAPI::OnApiError(Result);
				break;
		}
	}

}

#endif