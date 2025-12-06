#include "unity.h"

#include "day1/lib.h"

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
    TEST_ASSERT_EQUAL(COUNT_UP, rotation);
}

void test_get_rotation_and_number_2(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("R1", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(1, count);
    TEST_ASSERT_EQUAL(COUNT_DOWN, rotation);
}

void test_get_rotation_and_number_3(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("L125", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(125, count);
    TEST_ASSERT_EQUAL(COUNT_UP, rotation);
}

void test_get_rotation_and_number_4(){
    bool rotation;
    uint64_t count = 0;

    get_rotation_and_number("R1000", &rotation, &count);

    TEST_ASSERT_EQUAL_INT64(1000, count);
    TEST_ASSERT_EQUAL(COUNT_DOWN, rotation);
}

void test_count_rotation_1(){
    count_rotation("L100");

    TEST_ASSERT_EQUAL_INT64(50, get_rotation());
}

void test_count_rotation_2(){
    count_rotation("L75");

    TEST_ASSERT_EQUAL_INT64(25, get_rotation());
}

void test_count_rotation_3(){
    count_rotation("R75");

    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
}

void test_count_rotation_4(){
    count_rotation("R275");

    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
}

void test_count_rotation_5(){
    count_rotation("L275");

    TEST_ASSERT_EQUAL_INT64(75, get_rotation());
}

void test_count_rotation_6(){
    count_rotation("L50");

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
}

void test_count_rotation_7(){
    count_rotation("R50");

    TEST_ASSERT_EQUAL_INT64(0, get_rotation());
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

    UNITY_END();
}
