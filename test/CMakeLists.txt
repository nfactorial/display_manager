project(ngen_displaytests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ngen_displaytests
        test_display_pipeline.cpp
        test_display_port.cpp
        test_display_provider.cpp
        test_material_request.cpp
        test_render_layer.cpp
        test_request_provider.cpp)

if (NGEN_BUILD_OPENGL)
    target_link_libraries(ngen_displaytests ngen_opengl)
endif()

target_link_libraries(ngen_displaytests gtest gtest_main)
target_link_libraries(ngen_displaytests ngen_display)
