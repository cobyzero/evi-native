cmake_minimum_required(VERSION 3.10)
project(SkiaTSApp)

add_library(native-lib SHARED
    cpp/main.cpp
    cpp/skia_renderer.cpp
    cpp/ts_runtime.cpp
    cpp/quickjs/quickjs.c
)

include_directories(
    cpp/include
    cpp/quickjs
    /path/to/skia/include
)

link_directories(
    /path/to/skia/out/Static
)

target_link_libraries(native-lib skia android log)