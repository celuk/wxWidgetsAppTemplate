find_package(wxWidgets COMPONENTS REQUIRED)

include( "${wxWidgets_USE_FILE}" )

set(myApp_SOURCE_FILES myApp.h myApp.cpp myMain.h myMain.cpp)

if(WIN32)
 set(myApp_SOURCE_FILES ${encIDE_SOURCE_FILES} icon.rc)
endif(WIN32)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${myApp_SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})

