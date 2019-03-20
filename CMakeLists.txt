cmake_minimum_required(VERSION 3.12)

IF(MSVC)
	add_compile_options(/W4 /WX)
ELSE()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
ENDIF()

add_subdirectory(src)
