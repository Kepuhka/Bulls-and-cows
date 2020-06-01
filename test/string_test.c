#include "../src/func.h"
#include "../ctest/ctest.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(string, 1)
{
    num_length = 3;
    const char str_number_user[3] = "123";
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    int bull = 2;
    int cow = 1;

    string(str_number_user, str2, str3, bull, cow);

    const char str3_expected[50] = "123: Быков 2, коров 1";

    ASSERT_STR(str3_expected, str3);
}

CTEST(string, 2)
{
    num_length = 5;
    const char str_number_user[5] = "18759";
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    int bull = 5;
    int cow = 0;

    string(str_number_user, str2, str3, bull, cow);

    const char str3_expected[50] = "18759: Быков 5, коров 0";

    ASSERT_STR(str3_expected, str3);
}

CTEST(string, 3)
{
    num_length = 4;
    const char str_number_user[4] = "1298";
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    int bull = 0;
    int cow = 4;

    string(str_number_user, str2, str3, bull, cow);

    const char str3_expected[50] = "1298: Быков 0, коров 4";

    ASSERT_STR(str3_expected, str3);
}

CTEST(string, 4)
{
    num_length = 7;
    const char str_number_user[7] = "1298546";
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    int bull = 5;
    int cow = 2;

    string(str_number_user, str2, str3, bull, cow);

    const char str3_expected[50] = "1298546: Быков 5, коров 2";

    ASSERT_STR(str3_expected, str3);
}