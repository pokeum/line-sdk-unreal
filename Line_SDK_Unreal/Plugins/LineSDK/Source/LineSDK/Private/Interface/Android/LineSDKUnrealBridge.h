#pragma once

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

namespace LineSDK {

	enum class CallbackPayload : unsigned int
	{
		API_OK = 0,
		API_ERROR
	};
}
