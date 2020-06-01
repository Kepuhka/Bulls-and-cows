#include "../src/func.h"
#include "../ctest/ctest.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(game_number, 1)
{
    num_length = 3;
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};
    int bull, cow;

    game_number(a, b, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 3;
    const int expected_cow = 0;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(game_number, 2)
{
    num_length = 3;
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int bull, cow;

    game_number(a, b, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 0;
    const int expected_cow = 0;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(game_number, 3)
{
    num_length = 5;
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 3, 7, 6, 9};
    int bull, cow;

    game_number(a, b, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 2;
    const int expected_cow = 1;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(game_number, 4)
{
    num_length = 5;
    int a[5] = {7, 1, 5, 9, 2};
    int b[5] = {1, 7, 2, 5, 9};
    int bull, cow;

    game_number(a, b, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 0;
    const int expected_cow = 5;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}
