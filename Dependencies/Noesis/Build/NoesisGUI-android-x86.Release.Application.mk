####################################################################################################
# DIST: NoesisGUI-android-x86
####################################################################################################

APP_PROJECT_PATH := D:/Builds/Slave/build/NoesisSDK
APP_BUILD_SCRIPT := $(APP_PROJECT_PATH)/../Dist/Normal/NoesisGUI-android-x86-2.1.0f1/Build/NoesisGUI-android-x86.Release.mk
APP_PLATFORM := android-16
APP_ABI := x86
APP_STL := gnustl_static
APP_OPTIM := release

include $(APP_PROJECT_PATH)/Config/Common.mk
include $(APP_PROJECT_PATH)/Config/Release/Release.mk

APP_CFLAGS := -DHAVE_GLES2_GL2_H $(CONFIG_CFLAGS)
APP_CPPFLAGS := $(CONFIG_CPPFLAGS)
APP_LDFLAGS := $(CONFIG_LFLAGS)
