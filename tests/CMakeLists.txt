cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        qb1t6
        GIT_REPOSITORY https://github.com/EddyTheCo/Qb1t6.git
        GIT_TAG v0.0.1
        )
FetchContent_MakeAvailable(qb1t6)



foreach(app IN LISTS tip12)
add_executable(${app} ${app}.cpp)
target_link_libraries(${app} PRIVATE qb1t6 qcurlp81)
add_test(NAME ${app} COMMAND ${app})

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${app}> $<TARGET_FILE_DIR:${app}>
        COMMAND_EXPAND_LISTS
    )
endif ()
endforeach()

