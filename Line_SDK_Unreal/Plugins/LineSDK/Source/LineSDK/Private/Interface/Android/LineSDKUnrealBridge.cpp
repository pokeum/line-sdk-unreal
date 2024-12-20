#include "LineSDKUnrealBridge.h"

#if PLATFORM_ANDROID

#include "LineSDKInterfaceAndroid.h"
#include "LineSDKModule.h"

#define LINE_SDK_MODULE_POINTER			(FLineSDKModule::Get())
#define LINE_SDK_INTERFACE_POINTER		(static_cast<LineSDKInterfaceAndroid*>(FLineSDKModule::Get()->GetLineSDK().Get()))

extern "C" {
	
	/*
	 * Class:     co_pokeum_linesdk_unreal_UnrealBridge
	 * Method:    sendMessage
	 * Signature: (ILjava/lang/String;)V
	 */
	JNIEXPORT void JNICALL Java_co_pokeum_linesdk_unreal_UnrealBridge_sendMessage
	(JNIEnv *Env, jclass Class, jint Type, jstring Message)
	{
		using LineSDK::CallbackPayload;

		CallbackPayload PayloadType = static_cast<CallbackPayload>(Type);

		// Copies the new key into its final C string buffer
		const char* cMessageString = Env->GetStringUTFChars(Message, nullptr);
		if (cMessageString == nullptr) {
			return;  /* OutOfMemoryError already thrown */
		}
		FString MessageString = FString(cMessageString);
		
		// release heap memory
		Env->ReleaseStringUTFChars(Message, cMessageString);
		Env->DeleteLocalRef(Message);

		switch (PayloadType) {
			case CallbackPayload::API_OK:
				// Check if module is loaded
				if (LINE_SDK_MODULE_POINTER)
				{
					LINE_SDK_INTERFACE_POINTER->OnApiOk(MessageString);	
				}
				break;
			case CallbackPayload::API_ERROR:
				// Check if module is loaded
				if (LINE_SDK_MODULE_POINTER)
				{
					LINE_SDK_INTERFACE_POINTER->OnApiError(MessageString);	
				}
				break;
		}
	}

}

#endif