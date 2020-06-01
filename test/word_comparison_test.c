#include "../ctest/ctest.h"
#include "../src/func.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(word_comparison, 1)
{
    char randomWord[4] = "war";
    char userWord[4] = "war";
    int bull, cow;

    word_comparison(randomWord, userWord, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 3;
    const int expected_cow = 0;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(word_comparison, 2)
{
    char randomWord[4] = "cat";
    char userWord[4] = "sam";
    int bull, cow;

    word_comparison(randomWord, userWord, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 1;
    const int expected_cow = 0;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(word_comparison, 3)
{
    char randomWord[5] = "four";
    char userWord[5] = "fuel";
    int bull, cow;

    word_comparison(randomWord, userWord, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 1;
    const int expected_cow = 1;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}

CTEST(word_comparison, 4)
{
    char randomWord[5] = "four";
    char userWord[5] = "four";
    int bull, cow;

    word_comparison(randomWord, userWord, &bull, &cow);
    const int result_bull = bull;
    const int result_cow = cow;

    const int expected_bull = 4;
    const int expected_cow = 0;

    ASSERT_EQUAL(expected_bull, result_bull);
    ASSERT_EQUAL(expected_cow, result_cow);
}