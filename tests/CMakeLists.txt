cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        qb1t6
        GIT_REPOSITORY git@github.com:EddyTheCo/Qb1t6.git
        GIT_TAG main
        )
FetchContent_MakeAvailable(qb1t6)



add_executable(tip12 tip12.cpp)
target_link_libraries(tip12 PRIVATE  qb1t6)
target_link_libraries(tip12 PRIVATE qcurlp81)
add_test(NAME tip12 COMMAND tip12)
