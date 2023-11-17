add_library(game_client_lib client.cpp client.h i_execute.h i_request.h)

target_link_libraries(game_client_lib PUBLIC console_processors_lib game_space_lib utils_lib workers_lib)