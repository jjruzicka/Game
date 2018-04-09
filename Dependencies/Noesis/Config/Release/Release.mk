CONFIG_CFLAGS += -Ofast -ffunction-sections -fdata-sections -fomit-frame-pointer -DNDEBUG
CONFIG_CPPFLAGS +=
CONFIG_LFLAGS += -Wl,-O1,--gc-sections,--icf=safe
