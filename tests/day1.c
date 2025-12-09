#include "unity.h"

#include "day1/lib.h"
#include "day1/data.h"

//void get_rotation_and_number(char *, bool *direction, uint64_t *rotation_count);
//int64_t count_rotation();

void setUp() {
    reset();
}

void tearDown() {
}

void test_get_rotation_and_number_1(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("L1", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(1, count);
    TEST_ASSERT_EQUAL(COUNT_DOWN, rotation);
}

void test_get_rotation_and_number_2(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("R1", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(1, count);
    TEST_ASSERT_EQUAL(COUNT_UP, rotation);
}

void test_get_rotation_and_number_3(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("L125", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(125, count);
    TEST_ASSERT_EQUAL(COUNT_DOWN, rotation);
}

void test_get_rotation_and_number_4(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("R1000", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(1000, count);
    TEST_ASSERT_EQUAL(COUNT_UP, rotation);
}

void test_count_rotation_1(){
    count_rotation("L100", true);

    TEST_ASSERT_EQUAL_INT64(50, get_rotation());
}

void test_count_rotation_2(){
    count_rotation("L75", true);

    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
}

void test_count_rotation_3(){
    count_rotation("R75", true);

    TEST_ASSERT_EQUAL_INT64(25, get_rotation());
}

void test_count_rotation_4(){
    count_rotation("R275", true);

    TEST_ASSERT_EQUAL_INT64(25, get_rotation());
}

void test_count_rotation_5(){
    count_rotation("L275", true);
    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
}

void test_count_rotation_6(){
    count_rotation("L50", true);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
}

void test_count_rotation_7(){
    count_rotation("R50", true);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
}

void test_run_1(){
    char *data[] = {
        "L25",
    };

    run_part1(data, 1);

    TEST_ASSERT_EQUAL_INT64(0, get_number_of_hits());
}

void test_run_2(){
    char *data[] = {
        "L25",
        "L25",
    };

    run_part1(data, 2);

    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_3(){
    char *data[] = {
        "R25",
    };

    run_part1(data, 1);

    TEST_ASSERT_EQUAL_INT64(0, get_number_of_hits());
}

void test_run_4(){
    char *data[] = {
        "R25",
        "R25",
    };

    run_part1(data, 2);

    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_5(){
    char *data[] = {
        "R50",
        "R25",
    };

    run_part1(data, 2);

    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_6(){
    char *data[] = {
        "R50",
        "L100",
    };

    run_part1(data, 2);

    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_7(){
    // Start at 50
    char *data[] = {
    "L68", // 50 - 68
    "L30", // 48 
    "R48", // 0
    };

    run_part1(data, 3);

    TEST_ASSERT_EQUAL_INT(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_8(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
    };

    run_part1(data, 6);

    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_9(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
    };

    run_part1(data, 4);

    TEST_ASSERT_EQUAL_INT(95, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_10(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
    };

    run_part1(data, 5);

    TEST_ASSERT_EQUAL_INT(55, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_11(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
    };

    run_part1(data, 8);

    TEST_ASSERT_EQUAL_INT64(3, get_number_of_hits());
}

void test_run_provided_example_data(){
    run_part1(get_data(), get_size());

    TEST_ASSERT_EQUAL_INT64(3, get_number_of_hits());
}

void test_count_rotation_part_2_1(){
    count_rotation("L75", true);

    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_count_rotation_part_2_2(){
    count_rotation("R75", true);

    TEST_ASSERT_EQUAL_INT64(25, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_count_rotation_part_2_3(){
    count_rotation("R175", true);

    TEST_ASSERT_EQUAL_INT64(25, get_rotation());
    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_part_2_1(){
    char *data[] = {
        "L68",
    };

    run_part2(data, 1);

    TEST_ASSERT_EQUAL_INT64(82, get_rotation());
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

void test_run_part_2_2(){
    char *data[] = {
        "L68",
        "L30",
        "R48"
    };

    run_part2(data, 3);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_part_2_3(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
    };

    run_part2(data, 5);

    TEST_ASSERT_EQUAL_INT64(55, get_rotation());
    TEST_ASSERT_EQUAL_INT64(3, get_number_of_hits());
}

void test_run_part_2_4(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55"
    };

    run_part2(data, 6);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(4, get_number_of_hits());
}

void test_run_part_2_5(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99"
    };

    run_part2(data, 8);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(5, get_number_of_hits());
}

void test_run_part_2_6(){
    char *data[] = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82",
    };

    run_part2(data, 10);

    TEST_ASSERT_EQUAL_INT64(32, get_rotation());
    TEST_ASSERT_EQUAL_INT64(6, get_number_of_hits());
}

void test_run_part_2_7(){
    char *data[] = {
        "R1000",
    };

    run_part2(data, 1);

    TEST_ASSERT_EQUAL_INT64(10, get_number_of_hits());
}

void test_run_part_2_8(){
    char *data[] = {
        "R50",
        "R100",
    };

    run_part2(data, 2);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_part_2_9(){
    char *data[] = {
        "R50",
        "L100",
    };

    run_part2(data, 2);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(2, get_number_of_hits());
}

void test_run_part_2_10(){
    char *data[] = {
        "R50",
        "R200",
    };

    run_part2(data, 2);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(3, get_number_of_hits());
}

void test_run_part_2_11(){
    char *data[] = {
        "R50",
        "L200",
    };

    run_part2(data, 2);

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
    TEST_ASSERT_EQUAL_INT64(3, get_number_of_hits());
}

void test_run_provided_example_data_part_2(){
    run_part2(get_data(), get_size());

    TEST_ASSERT_EQUAL_INT64(6, get_number_of_hits());
}

void test_count_rotation_dumb(){
    set_rotation_count(1);
    count_rotation_dumb("L12");
    TEST_ASSERT_EQUAL_INT64(1, get_number_of_hits());
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_get_rotation_and_number_1);
    RUN_TEST(test_get_rotation_and_number_2);
    RUN_TEST(test_get_rotation_and_number_3);
    RUN_TEST(test_get_rotation_and_number_4);

    RUN_TEST(test_count_rotation_1);
    RUN_TEST(test_count_rotation_2);
    RUN_TEST(test_count_rotation_3);
    RUN_TEST(test_count_rotation_4);
    RUN_TEST(test_count_rotation_5);
    RUN_TEST(test_count_rotation_6);
    RUN_TEST(test_count_rotation_7);

    RUN_TEST(test_run_1);
    RUN_TEST(test_run_2);
    RUN_TEST(test_run_3);
    RUN_TEST(test_run_4);
    RUN_TEST(test_run_5);
    RUN_TEST(test_run_6);
    RUN_TEST(test_run_7);
    RUN_TEST(test_run_8);
    RUN_TEST(test_run_9);
    RUN_TEST(test_run_10);
    RUN_TEST(test_run_11);

    // With example data provided by Advent of Code
    RUN_TEST(test_run_provided_example_data);

    // Part 2
    RUN_TEST(test_count_rotation_part_2_1);
    RUN_TEST(test_count_rotation_part_2_2);
    RUN_TEST(test_count_rotation_part_2_3);

    RUN_TEST(test_run_part_2_1);
    RUN_TEST(test_run_part_2_2);
    RUN_TEST(test_run_part_2_3);
    RUN_TEST(test_run_part_2_4);
    RUN_TEST(test_run_part_2_5);
    RUN_TEST(test_run_part_2_6);
    RUN_TEST(test_run_part_2_7);
    RUN_TEST(test_run_part_2_8);
    RUN_TEST(test_run_part_2_9);
    RUN_TEST(test_run_part_2_10);
    RUN_TEST(test_run_part_2_11);

    RUN_TEST(test_run_provided_example_data_part_2);

    RUN_TEST(test_count_rotation_dumb);

    UNITY_END();
}
