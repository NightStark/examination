#include <stdio.h>

int main(void)
{
    const char * data = "hello";
    char const * data2 =  "hello2";
    char * const data3 = "hello";

    data = "fuck U";   //is OK.
    data2 = "fuck U2"; //is OK.
    data[0] = 'w';     //error: assignment of read-only location ‘*data’
    data2[0] = 'w';    //error: assignment of read-only location ‘*data’
    data3 = "fuck U3"; //error: assignment of read-only variable ‘data3’

    printf("data = %s\n", data);
    printf("data2 = %s\n", data2);
    printf("data3 = %s\n", data3);

    return 0;
}
