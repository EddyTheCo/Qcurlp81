cmake_minimum_required(VERSION 3.24)
FetchContent_Declare(
        Qtb1t6
        GIT_REPOSITORY https://github.com/EddyTheCo/Qb1t6.git
        GIT_TAG v0.1.1
        FIND_PACKAGE_ARGS 0.1 CONFIG)
FetchContent_MakeAvailable(Qtb1t6)

foreach(app tip12)
        add_executable(${app} ${app}.cpp)
        target_link_libraries(${app} PRIVATE Qtb1t6::qb1t6 qcurlp81)
        add_test(NAME ${app} COMMAND ${app})
        if(WIN32 AND BUILD_SHARED_LIBS)
                add_custom_command(
                        TARGET ${app}
                        POST_BUILD
                        COMMAND
                                ${CMAKE_COMMAND} -E copy_if_different
                                $<TARGET_RUNTIME_DLLS:${app}>
                                $<TARGET_FILE_DIR:${app}>
                        COMMAND_EXPAND_LISTS)
        endif(WIN32 AND BUILD_SHARED_LIBS)
endforeach()
