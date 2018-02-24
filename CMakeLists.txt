cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES x86_64)

add_subdirectory(external)

option(NGEN_BUILD_TESTS "Build unit tests." ON)

project(display_manager)

# Enable correct rendering API
if (NGEN_BUILD_OPENGL)
    find_package(OpenGL REQUIRED)

    if(OPENGL_FOUND)
        MESSAGE( "OpenGL library found successfully.")
        include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
    else(OPENGL_FOUND)
        MESSAGE( "Unable to find OpenGL library, please make sure it is installed." )
    endif (OPENGL_FOUND)

    #include_directories(${ngenOpenGL_SOURCE_DIR}/include)
endif()

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/external/ngen/include)

set(SOURCE_FILES
        source/display_port.cpp
        source/render_layer.cpp
        source/material_request.cpp
        source/request_provider.cpp
        source/display_pipeline.cpp
        source/display_provider.cpp)

set(INCLUDE_FILES
        include/display_port.h
        include/display_pipeline.h
        include/material_request.h
        include/request_provider.h
        include/render_layer.h
        include/request_page.h
        include/camera_args.h
        include/display_provider.h)

add_library(display_manager STATIC
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
)

target_include_directories(display_manager PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${OPENGL_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include/ngen/display_manager>
)

target_include_directories(display_manager SYSTEM PUBLIC
    $<BUILD_INTERFACE:${OPENGL_INCLUDE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/sce_vectormath/include/vectormath/SSE/cpp>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/ngen/include>
)

if (NGEN_BUILD_TESTS)
    add_subdirectory(test)
endif()
