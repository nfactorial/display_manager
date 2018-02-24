project(display_manager_test)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(display_manager_test
        test_display_pipeline.cpp
        test_display_port.cpp
        test_display_provider.cpp
        test_material_request.cpp
        test_render_layer.cpp
        test_request_provider.cpp)

if (NGEN_BUILD_OPENGL)
    target_link_libraries(display_manager_test PUBLIC
        ngen_opengl
    )
endif()

target_link_libraries(display_manager_test PUBLIC
    gtest
    gtest_main
    display_manager
)
