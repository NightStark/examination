#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
 * Armstrong 数，就是n位数的各位数的n次方之和等于该数，如：
 *      153=1^3+5^3+3^3
 *      1634=1^4+6^4+3^4+4^4
 * */
void dump_all_armstrong(int len)
{
    if (len < 2 || len > 8) {
        return;
    }
    int begin = pow(10, len - 1);
    int end = pow(10, len) - 1;
    int M = begin, t = 0, S = 0, N = 0;

    while (M < end) {
        N = M;
        S = 0;
        while (N) {
            t = N % 10;
            N = N / 10;
            S = S + pow(t, len);
        }

        if (S == M) {
            printf("[%d]\n", S);
        }
        M++;
    }

    return;
}

void get_some_armStrong(void)
{
    /* 获取数字位数在[2-8]的所有的armStrong数字 */
    int len = 2;

    while (len <= 8) {
        dump_all_armstrong(len);
        len++;
    }

    return;
}

int main(void)
{
    get_some_armStrong();

    return 0;
}
