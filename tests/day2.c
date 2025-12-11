#include "unity.h"

#include "day2/lib.h"

//void get_rotation_and_number(char *, bool *direction, uint64_t *rotation_count);
//int64_t count_rotation();

void setUp() {
    reset();
}

void tearDown() {
}

void test_get_min_max_1(){
    uint64_t min = 0;
    uint64_t max = 0;
    bool ret = false;

    ret = get_min_max("1-10", &min, &max);

    TEST_ASSERT_EQUAL(false, ret);
    TEST_ASSERT_EQUAL_INT64(1, min);
    TEST_ASSERT_EQUAL_INT64(10, max);
}

void test_get_min_max_2(){
    uint64_t min = 0;
    uint64_t max = 0;
    bool ret = false;

    ret = get_min_max("1-10,1000-1111", &min, &max);
    TEST_ASSERT_EQUAL(true, ret);

    TEST_ASSERT_EQUAL_INT64(1, min);
    TEST_ASSERT_EQUAL_INT64(10, max);
    ret = get_min_max("1-10,1000-1111", &min, &max);

    TEST_ASSERT_EQUAL(false, ret);
    TEST_ASSERT_EQUAL_INT64(1000, min);
    TEST_ASSERT_EQUAL_INT64(1111, max);
}

void test_add_invalid_values_in_range(){
    add_invalid_values_in_range("11-22");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(33, total);
}

void test_add_invalid_values_in_range_2(){
    add_invalid_values_in_range("95-115");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(95, total);
}

void test_add_invalid_values_in_range_3(){
    add_invalid_values_in_range("998-1012");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(1010, total);
}

void test_add_invalid_values_in_range_4(){
    add_invalid_values_in_range("1188511880-1188511890");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(1188511885, total);
}

void test_add_invalid_values_in_range_5(){
    add_invalid_values_in_range("222220-222224");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(222222, total);
}

void test_add_invalid_values_in_range_6(){
    add_invalid_values_in_range("1698522-1698528");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(0, total);
}

void test_add_invalid_values_in_range_7(){
    add_invalid_values_in_range("446443-446449");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(446446, total);
}

void test_add_invalid_values_in_range_8(){
    add_invalid_values_in_range("38593856-38593862");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(38593859, total);
}

void test_add_invalid_values_in_range_9(){
    add_invalid_values_in_range("565653-565659");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(0, total);
}

void test_add_invalid_values_in_range_10(){
    add_invalid_values_in_range("824824821-824824827");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(0, total);
}

void test_add_invalid_values_in_range_11(){
    add_invalid_values_in_range("2121212118-2121212124");

    uint64_t total = get_total();

    TEST_ASSERT_EQUAL_INT64(0, total);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_get_min_max_1);
    RUN_TEST(test_get_min_max_2);

    RUN_TEST(test_add_invalid_values_in_range);
    RUN_TEST(test_add_invalid_values_in_range_2);
    RUN_TEST(test_add_invalid_values_in_range_3);
    RUN_TEST(test_add_invalid_values_in_range_4);
    RUN_TEST(test_add_invalid_values_in_range_5);
    RUN_TEST(test_add_invalid_values_in_range_6);
    RUN_TEST(test_add_invalid_values_in_range_7);
    RUN_TEST(test_add_invalid_values_in_range_8);
    RUN_TEST(test_add_invalid_values_in_range_9);
    RUN_TEST(test_add_invalid_values_in_range_10);
    RUN_TEST(test_add_invalid_values_in_range_11);

    UNITY_END();
}
