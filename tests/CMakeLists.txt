
cmake_minimum_required(VERSION 3.24)
FetchContent_Declare(
	qb1t6
	GIT_REPOSITORY https://github.com/EddyTheCo/Qb1t6.git
	GIT_TAG develop
	FIND_PACKAGE_ARGS 0.0 CONFIG
	)
FetchContent_MakeAvailable(qb1t6)

foreach(app  tip12)
	add_executable(${app} ${app}.cpp)
	target_link_libraries(${app} PRIVATE qb1t6 qcurlp81)
	add_test(NAME ${app} COMMAND ${app})
endforeach()

