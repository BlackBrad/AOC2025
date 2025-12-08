set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

add_executable(
    day1_test
    day1.c
    ../day1/lib.c
    ../day1/data.c
)

target_link_libraries(
    day1_test
    unity
)
