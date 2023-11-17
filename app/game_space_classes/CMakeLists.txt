add_library(game_space_lib field.cpp field.h universe.cpp universe.h)

target_link_libraries(game_space_lib PUBLIC  utils_lib)