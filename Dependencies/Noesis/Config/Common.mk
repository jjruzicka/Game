# maybe-uninitialized is activated in gcc (not clang) by default and the analysis is imperfect

CONFIG_CFLAGS = -g -pipe -Wall -Wno-uninitialized -Werror -Wfatal-errors -Wtype-limits -fvisibility=hidden -D_FILE_OFFSET_BITS=64
CONFIG_CPPFLAGS = -std=c++11 -Wno-invalid-offsetof -fvisibility-inlines-hidden -fno-threadsafe-statics -fno-rtti -fno-exceptions
CONFIG_LFLAGS = -g -Wall -Werror -Wextra
