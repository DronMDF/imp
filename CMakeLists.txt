cmake_minimum_required(VERSION 3.5)

project(imp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

find_package(Threads)
conan_basic_setup()

add_executable(
	imp
	AsioAcceptor.cpp
	AsioService.cpp
	main.cpp
	Server.cpp
	Session.cpp
)

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

add_custom_target(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
