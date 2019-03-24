cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	add_compile_options(/W4 /WX)
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)