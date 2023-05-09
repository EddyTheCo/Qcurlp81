cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)


find_package(qb1t6 0 QUIET )

if(NOT qb1t6_FOUND AND NOT TARGET qb1t6)
include(FetchContent)
FetchContent_Declare(
        qb1t6
        GIT_REPOSITORY https://github.com/EddyTheCo/Qb1t6.git
        GIT_TAG v0.0.1
        )
FetchContent_MakeAvailable(qb1t6)
endif(NOT qb1t6_FOUND AND NOT TARGET qb1t6)


add_executable(tip12 tip12.cpp)
target_link_libraries(tip12 PRIVATE qb1t6 qcurlp81)
add_test(NAME tip12 COMMAND tip12)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:tip12> $<TARGET_FILE_DIR:tip12>
        COMMAND_EXPAND_LISTS
    )
endif ()

