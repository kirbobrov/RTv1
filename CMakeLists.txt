cmake_minimum_required(VERSION 3.7)
project(RTv1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -lmlx -framework OpenGL -framework AppKit")
set(SOURCE_FILES main.c ft_init.c rt_sphere.c ft_vector.c cylinder.c sphere.c)
add_executable(RTv1 ${SOURCE_FILES})
##target_link_libraries(RTv1 ${CMAKE_SOURCE_DIR}/libft/libft.a)
