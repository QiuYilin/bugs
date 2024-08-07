set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "SFR")
#set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/INSTALL.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "QtEx: Qt-based extension components, including GUI widgets, network, and 2D/3D image display.")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

if(UNIX)
  set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local/SFR")
endif()

if(WIN32 OR MINGW)
  SET(CPACK_PACKAGE_INSTALL_DIRECTORY      "SFR")
  SET(CPACK_NSIS_INSTALL_ROOT              "C:")
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_SOURCE_IGNORE_FILES "${PROJECT_BINARY_DIR};/.git/;.gitignore;menu.yml")
set(CPACK_SOURCE_GENERATOR "ZIP;TGZ")
set(CPACK_GENERATOR "ZIP;TGZ")

if(UNIX)
  if(CMAKE_SYSTEM_NAME MATCHES Linux)
    list(APPEND CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "qiuyilin")
    set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "nlohmann-json3-dev,libeigen3-dev,sfr-utils")

    # list(APPEND CPACK_GENERATOR "RPM")
    # set(CPACK_RPM_PACKAGE_RELEASE "1")
    # set(CPACK_RPM_PACKAGE_LICENSE "MIT")
    # set(CPACK_RPM_PACKAGE_REQUIRES "uuid-devel")
  endif()
endif()

if(WIN32 OR MINGW)
  list(APPEND CPACK_GENERATOR "NSIS")
  set(CPACK_NSIS_PACKAGE_NAME "sfr-qt-ex")
  set(CPACK_NSIS_CONTACT "qiuyilin")
  set(CPACK_NSIS_UNINSTALL_NAME "Uninstall${CMAKE_PROJECT_NAME}")
  set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
  set(CPACK_NSIS_MODIFY_PATH ON)
endif()

# if(APPLE)
#   list(APPEND CPACK_GENERATOR "Bundle")
#   set(CPACK_BUNDLE_NAME "message")
#   configure_file(${PROJECT_SOURCE_DIR}/cmake/Info.plist.in Info.plist @ONLY)
#   set(CPACK_BUNDLE_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
#   set(CPACK_BUNDLE_ICON ${PROJECT_SOURCE_DIR}/cmake/coffee.icns)
# endif()

message(STATUS "CPack generators: ${CPACK_GENERATOR}")

include(CPack)
