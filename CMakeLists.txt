cmake_minimum_required(VERSION 3.9)

project(imp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

find_package(Threads)
conan_basic_setup()

add_executable(imp main.cpp)
set_target_properties(
	imp
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
target_link_libraries(imp ${CMAKE_THREAD_LIBS_INIT} ${CONAN_LIBS})

enable_testing()
add_subdirectory(test)
