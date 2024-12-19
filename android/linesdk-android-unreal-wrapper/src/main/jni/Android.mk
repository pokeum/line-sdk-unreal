LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := co_pokeum_linesdk      # Library Name
FILES           := \
    temp.cpp

LOCAL_SRC_FILES := $(FILES)

LOCAL_LDLIBS := -llog

# target include directories
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

include $(BUILD_SHARED_LIBRARY)