####################################################################################################
# DIST: NoesisGUI-android-arm
####################################################################################################

APP_PROJECT_PATH := D:/Builds/Slave/build/NoesisSDK
APP_BUILD_SCRIPT := $(APP_PROJECT_PATH)/../Dist/Normal/NoesisGUI-android-arm-2.1.0f1/Build/NoesisGUI-android-arm.Debug.mk
APP_PLATFORM := android-16
APP_ABI := armeabi-v7a
APP_STL := gnustl_static
APP_OPTIM := debug

include $(APP_PROJECT_PATH)/Config/Common.mk
include $(APP_PROJECT_PATH)/Config/Debug/Debug.mk

APP_CFLAGS := -DHAVE_GLES2_GL2_H $(CONFIG_CFLAGS)
APP_CPPFLAGS := $(CONFIG_CPPFLAGS)
APP_LDFLAGS := $(CONFIG_LFLAGS)
