#include <include/co_pokeum_linesdk_unreal_UnrealBridge.h>

#include <include/CallbackPayload.h>
#include <include/util/AndroidLog.h>

#include <string>

JNIEXPORT void JNICALL
Java_co_pokeum_linesdk_unreal_UnrealBridge_sendMessage (
    JNIEnv *Env,
    jclass Class,
    jint Type,
    jstring Message
)
{
    using LineSDK::CallbackPayload;

    CallbackPayload PayloadType = static_cast<CallbackPayload>(Type);

    // Copies the new key into its final C string buffer
    const char* cMessageString = Env->GetStringUTFChars(Message, nullptr);
    if (cMessageString == nullptr) {
        return;  /* OutOfMemoryError already thrown */
    }
    std::string MessageString = std::string(cMessageString);

    //release heap memory
    Env->ReleaseStringUTFChars(Message, cMessageString);
    Env->DeleteLocalRef(Message);

    switch (PayloadType) {
        case CallbackPayload::API_OK:
            LOG_DEBUG("[API_OK] Message={%s}", MessageString.c_str());
            break;
        case CallbackPayload::API_ERROR:
            LOG_DEBUG("[API_ERROR] Message={%s}", MessageString.c_str());
            break;
    }
}