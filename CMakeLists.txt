cmake_minimum_required(VERSION 3.23)
project(tests_game_space)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests_game_space tests/field_tests.cpp tests/universe_tests.cpp tests/iterator_tests.cpp tests/file_handler_tests.cpp)


#выключает copy elision
add_compile_options(-fno-elide-constructors)

add_subdirectory(app/game_space_classes)
add_subdirectory(app/workers)
add_subdirectory(app/utils)
add_subdirectory(app/console_process_classes)
add_subdirectory(app/client)


target_include_directories(tests_game_space PUBLIC app/game_space_classes app/workers app/utils app/console_process_classes)



include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


target_link_libraries(tests_game_space PUBLIC game_space_lib utils_lib workers_lib console_processors_lib game_client_lib gtest_main)