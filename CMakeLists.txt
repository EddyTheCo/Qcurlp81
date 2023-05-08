cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
include(local_conf.cmake OPTIONAL)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
include(cmake/VersionFromGit.cmake)

version_from_git(
  LOG       ON
  TIMESTAMP "%Y%m%d%H%M%S"
)
project(Qtcurlp-81 VERSION ${VERSION} DESCRIPTION "simple IOTA-QT curl-p hashing" LANGUAGES CXX)


set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
		STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/FindQt.cmake)

add_library(qcurlp81 include/hashing/qcurlp81.hpp qcurlp81.cpp)

target_link_libraries(qcurlp81 PUBLIC  Qt6::Core )

target_include_directories(qcurlp81 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")

install(TARGETS qcurlp81 EXPORT qcurlp81Targets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)

install(EXPORT qcurlp81Targets
	FILE qcurlp81Targets.cmake
	DESTINATION lib/cmake/qcurlp81
	)
include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/qcurlp81Config.cmake"
	INSTALL_DESTINATION "lib/cmake/qcurlp81"
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
	)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/qcurlp81ConfigVersion.cmake"
	VERSION ${VERSION}
	COMPATIBILITY SameMajorVersion
	)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/qcurlp81Config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/qcurlp81ConfigVersion.cmake
	DESTINATION lib/cmake/qcurlp81
	)
export(EXPORT qcurlp81Targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/qcurlp81Targets.cmake"
	)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-v${SEMVER}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}")
    if(NOT BUILD_SHARED_LIBS)	    
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_FILE_NAME}-static")
    endif(NOT BUILD_SHARED_LIBS)		    
    include(CPack)
endif()
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
