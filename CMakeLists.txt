cmake_minimum_required(VERSION 3.16)
project(filler C)

set(CMAKE_C_STANDARD 90)

set(SOURCES sources/main.c sources/ft_parse_player.c sources/ft_parse_plateau_size.c sources/ft_create_map.c sources/ft_error_msg.c sources/ft_parse_map.c)

add_executable(filler ${SOURCES})

include_directories(includes)
include_directories(ft_printf/includes)
include_directories(ft_printf/libft/inc)

add_subdirectory(ft_printf)

target_link_libraries(filler libftprintf)