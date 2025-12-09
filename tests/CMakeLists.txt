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

add_executable(
    day2_test
    day2.c
    ../day2/lib.c
    ../day2/data.c
)

target_link_libraries(
    day2_test
    unity
)
