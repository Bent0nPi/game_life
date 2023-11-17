cmake_minimum_required(VERSION 3.23)
project(tests_game_space)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_life life.cpp)


#выключает copy elision
add_compile_options(-fno-elide-constructors)

add_subdirectory(game_space_classes)
add_subdirectory(workers)
add_subdirectory(utils)
add_subdirectory(console_process_classes)
add_subdirectory(client)


target_include_directories(game_life PUBLIC game_space_classes workers utils console_process_classes)


target_link_libraries(game_life PUBLIC game_space_lib utils_lib workers_lib console_processors_lib game_client_lib)