#include "../ctest/ctest.h"
#include "../src/func.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(reading_file, 1)
{
    char str[] = "src/LibraryFreeWords.txt";
    char* result_buffer = reading_file(str);

    char expected_buffer[]
            = "fox,dog,cat,sea,sky,low,son,sun,wet,red,can,car,bed,bag,air,sit,big,hot,fly,try,man,"
              "die,may,day,toy,one,two,six,ten,lie,pen,paw,owl,oil";

    ASSERT_STR(expected_buffer, result_buffer);
}

CTEST(reading_file, 2)
{
    char str[] = "src/LibraryFourWords.txt";
    char* result_buffer = reading_file(str);

    char expected_buffer[]
            = "cafe,bank,shop,road,stop,path,park,lake,sand,flat,sofa,oven,meat,pork,lamb,fish,"
              "dark,corn,soup,rice,salt,pear,plum,cake,soda,wine,milk,curd,dish,fork,meal,tram,"
              "ship,time";

    ASSERT_STR(expected_buffer, result_buffer);
}