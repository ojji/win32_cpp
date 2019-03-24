project(win32_window)

add_definitions(-DUNICODE -D_UNICODE)
add_executable(win32_window WIN32 main.cpp BaseWindow.h SampleWindow.h SampleWindow.cpp)