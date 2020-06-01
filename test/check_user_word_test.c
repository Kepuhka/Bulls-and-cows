#include <gtk/gtk.h>
#include "../ctest/ctest.h"
#include "../src/func.h"
#include "../src/word.h"
#include "../src/number.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(check_user_word, 1)
{
    num_length = 3;
    char userWord[4] = "dog";
    int result_n = check_user_word(userWord, num_length);

    int expected_n = 0;

    ASSERT_EQUAL(expected_n, result_n);
}

CTEST(check_user_word, 2)
{
    num_length = 3;
    char userWord[4] = "d0g";
    int result_n = check_user_word(userWord, num_length);

    int expected_n = 1;

    ASSERT_EQUAL(expected_n, result_n);
}

CTEST(check_user_word, 3)
{
    num_length = 3;
    char userWord[4] = "Dog";
    int result_n = check_user_word(userWord, num_length);

    int expected_n = 1;

    ASSERT_EQUAL(expected_n, result_n);
}

CTEST(check_user_word, 4)
{
    num_length = 3;
    char userWord[4] = "d@g";
    int result_n = check_user_word(userWord, num_length);

    int expected_n = 1;

    ASSERT_EQUAL(expected_n, result_n);
}