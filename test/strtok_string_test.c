#include <gtk/gtk.h>
#include <string.h>
#include "../ctest/ctest.h"
#include "../src/func.h"
#include "../src/word.h"
#include "../src/number.h"

/* num_length - A global variable containing the number of digits in a guessable number */

CTEST(strtok_string, 1)
{
    char buffer[150] = "fox,dog,cat,sea,sky,low,son,sun,wet,red,can,car,bed,bag,air,sit,big,eye,hot,fly,try,man,die,may,day,toy,one,two,six,ten,lie,pen,paw,owl,oil";

    size_t rezult_size_str = strlen(strtok_string(buffer));

    size_t expected_size_str = 3;

    ASSERT_EQUAL(rezult_size_str, expected_size_str);
}
CTEST(strtok_string, 2)
{
    char buffer[200] = "cafe,bank,shop,road,stop,path,park,lake,sand,flat,sofa,oven,meat,pork,lamb,fish,dark,corn,soup,rice,salt,pear,plum,cake,soda,wine,milk,curd,dish,fork,meal,tram,ship,time";

    size_t rezult_size_str = strlen(strtok_string(buffer));

    size_t expected_size_str = 4;

    ASSERT_EQUAL(rezult_size_str, expected_size_str);
}