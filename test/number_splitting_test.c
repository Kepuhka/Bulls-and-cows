#include <gtk/gtk.h>
#include <stdlib.h>
#include "../ctest/ctest.h"
#include "../src/func.h"
#include "../src/word.h"
#include "../src/number.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(number_splitting, 1)
{
    num_length = 3;
    const char str_number_user[3] = "123";
    int number_user[3] = {0};

    const int result_return = number_splitting(str_number_user, number_user);
    const int expected_return = 0;
    const int expected_number_user[3] = {1, 2, 3};

    ASSERT_EQUAL(expected_return, result_return);
    ASSERT_EQUAL(number_user[0], expected_number_user[0]);
    ASSERT_EQUAL(number_user[1], expected_number_user[1]);
    ASSERT_EQUAL(number_user[2], expected_number_user[2]);
}

CTEST(number_splitting, 2)
{
    num_length = 3;
    const char str_number_user[3] = "223";
    int number_user[3] = {0};

    const int result_return = number_splitting(str_number_user, number_user);
    const int expected_return = 1;
    const int expected_number_user[3] = {2, 2, 3};

    ASSERT_EQUAL(expected_return, result_return);
    ASSERT_EQUAL(number_user[0], expected_number_user[0]);
    ASSERT_EQUAL(number_user[1], expected_number_user[1]);
    ASSERT_EQUAL(number_user[2], expected_number_user[2]);
}

CTEST(number_splitting, 3)
{
    num_length = 3;
    const char str_number_user[3] = "g23";
    int number_user[3] = {0};

    const int result_return = number_splitting(str_number_user, number_user);
    const int expected_return = 1;
    const int expected_number_user[3] = {0, 0, 0};

    ASSERT_EQUAL(expected_return, result_return);
    ASSERT_EQUAL(number_user[0], expected_number_user[0]);
    ASSERT_EQUAL(number_user[1], expected_number_user[1]);
    ASSERT_EQUAL(number_user[2], expected_number_user[2]);
}

CTEST(number_splitting, 4)
{
    num_length = 3;
    const char str_number_user[3] = "7g3";
    int number_user[3] = {0};

    const int result_return = number_splitting(str_number_user, number_user);
    const int expected_return = 1;
    const int expected_number_user[3] = {7, 0, 0};

    ASSERT_EQUAL(expected_return, result_return);
    ASSERT_EQUAL(number_user[0], expected_number_user[0]);
    ASSERT_EQUAL(number_user[1], expected_number_user[1]);
    ASSERT_EQUAL(number_user[2], expected_number_user[2]);
}
