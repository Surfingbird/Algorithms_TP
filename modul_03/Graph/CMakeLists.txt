cmake_minimum_required(VERSION 3.10)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

set(BINDIR ${CMAKE_SOURCE_DIR}/bin)
MAKE_DIRECTORY(${BINDIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BINDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BINDIR})
set(CMAKE_CXX_FLAGS "-lncurses")

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()




add_executable(Graph main.cpp
        graph.hpp

        list_graph/list_graph.hpp
        list_graph/list_graph.cpp

        arc_graph/arc_graph.cpp
        arc_graph/arc_graph.h

        matrix_graph/matrix_graph.cpp
        matrix_graph/matrix_graph.h

        set_graph/set_graph.h
        set_graph/set_graph.cpp
        )

add_executable(tests tests/main_tests.cpp
        set_graph/set_graph.h
        set_graph/set_graph.cpp

        matrix_graph/matrix_graph.h
        matrix_graph/matrix_graph.cpp

        arc_graph/arc_graph.h
        arc_graph/arc_graph.cpp

        list_graph/list_graph.hpp
        list_graph/list_graph.cpp

        graph.hpp
        )
target_link_libraries(tests gtest_main)