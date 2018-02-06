cmake_minimum_required(VERSION 3.9)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

find_package(Threads)
conan_basic_setup()

add_executable(imp_test main.cpp)
set_target_properties(
	imp_test
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
target_link_libraries(imp_test ${CMAKE_THREAD_LIBS_INIT} ${CONAN_LIBS})

add_test(
	NAME imp_test
	COMMAND imp_test
)
