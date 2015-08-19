LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CLANG=true
LOCAL_MODULE := dk_server
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := main_server.cpp server.cpp idkinterface.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder
LOCAL_C_INCLUDES += frameworks/base/include system/core/include
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_CLANG=true
LOCAL_MODULE := dk_client
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := main_client.cpp client.cpp idkinterface.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder
LOCAL_C_INCLUDES += frameworks/base/include system/core/include
include $(BUILD_EXECUTABLE)
