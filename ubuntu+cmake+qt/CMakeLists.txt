cmake_minimum_required(VERSION 3.19)

option(USE_VCPKG "use vcpkg" ON)

set(project_name QtEx)

#temp
set(INSTALL_CMAKEDIR share/${project_name})

option(BUILD_EXAMPLES "Build EXAMPLE" ON)
option(BUILD_WIDGETS "Build Widgets" ON)
option(BUILD_DEBUG_POSTFIX_D "Append d suffix to debug libraries" ON)

project(${project_name} VERSION 2.5.1 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_directory_property(_has_parent PARENT_DIRECTORY)
if(_has_parent)
  set(is_root_project OFF)
else()
  set(is_root_project ON)
endif()


set(SFRQTEX_DEVELOPER_DEFAULTS "${is_root_project}" CACHE BOOL "Turns on default settings for development of QtEx")

if(SFRQTEX_DEVELOPER_DEFAULTS)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Gui OpenGL Network)
message(STATUS "QT_VERSION: ${QT_VERSION}, QT_DIR: ${QT_DIR}")

set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTORCC ON) # Resource Compiler
#set(CMAKE_AUTOUIC ON) # User Interface Compiler

if(BUILD_DEBUG_POSTFIX_D)
  set(CMAKE_DEBUG_POSTFIX "d")
  set(CMAKE_RELEASE_POSTFIX "")
  set(CMAKE_RELWITHDEBINFO_POSTFIX "rd")
  set(CMAKE_MINSIZEREL_POSTFIX "s")
endif()

configure_file(${PROJECT_SOURCE_DIR}/cmake/${project_name}Config.cmake
  ${CMAKE_BINARY_DIR}/${project_name}Config.cmake
  @ONLY
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file( "${CMAKE_CURRENT_BINARY_DIR}/${project_name}ConfigVersion.cmake" 
  COMPATIBILITY SameMajorVersion 
  )

install(FILES
  ${CMAKE_BINARY_DIR}/${project_name}Config.cmake
  ${CMAKE_BINARY_DIR}/${project_name}ConfigVersion.cmake
  DESTINATION ${INSTALL_CMAKEDIR}
)

add_custom_target(uninstall COMMAND xargs rm < install_manifest.txt)

if(BUILD_WIDGETS)
add_subdirectory(Widgets)
endif()
if(BUILD_EXAMPLES)
add_subdirectory(example)
endif()
include(${CMAKE_CURRENT_LIST_DIR}/cmake/CMakeCPack.cmake)