set(component Widgets)

set(H_HEADER_FILES
	include/StatusBar.h
)

set(CPP_SOURCE_FILES
	StatusBar.cpp
)

######
# Uic
##

if (${QT_VERSION_MAJOR} EQUAL 6)
  qt_wrap_ui(uic_files
      ${UI_FILES}
  )
else()
  qt5_wrap_ui(uic_files
  ${UI_FILES}
  )
endif()

add_library(${component} SHARED
	${H_HEADER_FILES}
	${CPP_SOURCE_FILES}
	${uic_files}
	${QRC_FILES}
)

add_library(${project_name}::${component} ALIAS ${component})

target_include_directories(${component}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include/QtEx>
)

target_link_libraries(${component}
  PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)

set_target_properties(${component}
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
###############
# For Windows export
##
include(GenerateExportHeader)
generate_export_header (
  ${component}
  EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/${component}Export.h"
)

###############
# Installation
##
set_target_properties(${component} PROPERTIES PUBLIC_HEADER "${H_HEADER_FILES}")
set_target_properties(${component} PROPERTIES ARCHIVE_OUTPUT_NAME "Sfr${component}")

include(GNUInstallDirs)

set_target_properties(${component} PROPERTIES PREFIX "Sfr")

install(TARGETS ${component}
  EXPORT ${component}Targets
  COMPONENT ${component}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${project_name}/${component}
)

install(EXPORT ${component}Targets
  FILE ${project_name}${component}Targets.cmake
  NAMESPACE ${project_name}::
  DESTINATION ${INSTALL_CMAKEDIR}
  COMPONENT ${component}
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/${project_name}${component}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${project_name}${component}Config.cmake
  INSTALL_DESTINATION ${INSTALL_CMAKEDIR}
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${project_name}${component}Config.cmake
  DESTINATION ${INSTALL_CMAKEDIR}
  COMPONENT ${component}
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${component}Export.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${project_name}/${component}
  COMPONENT ${component}
)