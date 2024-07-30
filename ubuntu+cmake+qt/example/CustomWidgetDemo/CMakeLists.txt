# file(GLOB_RECURSE CPPS  ./*.cpp )
# file(GLOB_RECURSE HS  ./*.h )
set(UI_FILES
	./CustomWidgetDemo.ui
)

if (${QT_VERSION_MAJOR} EQUAL 6)
  qt_wrap_ui(demo_uic_files
      ${UI_FILES}
  )
else()
  qt5_wrap_ui(demo_uic_files
  ${UI_FILES}
  )
endif()

set(example_name customWidget)

add_executable(${example_name} CustomWidgetDemo.h
                               CustomWidgetDemo.cpp
                               main.cpp 
                              #  StatusBar.h 
                              #  StatusBar.cpp
${demo_uic_files})

target_include_directories(${example_name}
  PUBLIC
    $<BUILD_INTERFACE:  ${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:  ${CMAKE_CURRENT_BINARY_DIR}>
	#UIC location
)

target_link_libraries(${example_name} PRIVATE QtEx::Widgets)

if(Win32)
get_filename_component(CMAKE_TOOLCHAIN_FILENAME ${CMAKE_TOOLCHAIN_FILE} NAME)
string(COMPARE EQUAL ${CMAKE_TOOLCHAIN_FILENAME} "vcpkg.cmake" USE_VCPKG)
if(USE_VCPKG)
  set(TOOL_WINDEPLOYQT "windeployqt")
  get_filename_component(CMAKE_TOOLCHAIN_DIR ${CMAKE_TOOLCHAIN_FILE} DIRECTORY)
  add_custom_command(TARGET ${example_name} POST_BUILD
  COMMAND ${CMAKE_TOOLCHAIN_DIR}/../../installed/x64-windows/tools/Qt6/bin/${TOOL_WINDEPLOYQT}$<$<CONFIG:Debug,RelWithDebInfo>:.debug.bat>
          $<TARGET_FILE:${example_name}>
  COMMENT "Running windeployqt... ${CMAKE_TOOLCHAIN_DIR}/../../packages/qtbase_x64-windows/tools/Qt6/bin/${TOOL_WINDEPLOYQT}$<$<CONFIG:Debug,RelWithDebInfo>:.debug.bat>"
  )
endif()
endif()