cmake_minimum_required(VERSION 3.10)
project(ShortWay)

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

#add_executable(ShortWay main.cpp)

#add_executable(SetShortWay main_with_sets.cpp)

add_executable(MatrixShortWay
        MatrixManyGraph/main_matrix.cpp
        )

add_executable(tests
        test/main_test.cpp
#        MatrixGraph/ShortWayGraph.cpp
#        MatrixGraph/ShortWayGraph.h
#        search_way.h
#        GraphPoint.h
#
#        SetGraph/ShortWaySetG.cpp
#        SetGraph/ShortWaySetG.h

        MatrixManyGraph/MatrixManyGraph.cpp
        MatrixManyGraph/MatrixManyGraph.h
        )

target_link_libraries(tests gtest_main)