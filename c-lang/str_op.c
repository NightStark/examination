#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

char * strip_blank(char *str)
{
    char *s = NULL;
    char *t = NULL;

    if (NULL == str) {
        return NULL;
    }

    s = str;
    t = str;

    while (*t) {
        if (*t != ' ') {
            *s = *t;
            s++;
        }
        t++;
    }
    *s = '\0'; /* NB: 一定要记得，而且不用 s++, !!!!!!  */

    return str;
}

int main(void)
{
    char str_buf[] = " hello world ! ";
    printf("before strip_blank:[%s]\n", str_buf);
    printf("after  strip_blank:[%s]\n", strip_blank(str_buf));

    return 0;
}
