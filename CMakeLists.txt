cmake_minimum_required(VERSION 3.30)
project(Practice VERSION 0.1 LANGUAGES CXX DESCRIPTION "Practice Project")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_INSTALL_RPATH $<INSTALL_INTERFACE:${CMAKE_INSTALL_LIBDIR}>)

find_package(Boost 1.80.0 CONFIG REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

add_library(practice SHARED)
target_sources(practice PRIVATE src/practice.cpp)
target_include_directories(practice PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(practice PUBLIC Boost::system)
target_compile_definitions(practice PRIVATE PROGRAM_VERSION="${CMAKE_PROJECT_VERSION}")

add_executable(program)
target_sources(program PRIVATE src/main.cpp)
target_link_libraries(program PRIVATE practice)

#write_basic_package_version_file(${CMAKE_BINARY_DIR}/PracticeVersion.cmake COMPATIBILITY SameMajorVersion)
install(TARGETS practice EXPORT PracticeTargets COMPONENT Core:: LIBRARY CONFIGURATIONS Release)
install(TARGETS program RUNTIME CONFIGURATIONS Release)
#install(FILES ${CMAKE_BINARY_DIR}/PracticeVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/practice/cmake CONFIGURATIONS Release)

set(CPACK_PACKAGE_VENDOR "Brian Salehi")
set(CPACK_PACKAGE_CONTACT "briansalehi@proton.me")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${CMAKE_PROJECT_DESCRIPTION}")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-system-dev (>= 1.80.0)")
set(CPACK_RPM_PACKAGE_REQUIRES "boost-system >= 1.80.0")
string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME)
string(TOLOWER ${CMAKE_SYSTEM_NAME} CMAKE_SYSTEM_NAME)

include(CPack)
