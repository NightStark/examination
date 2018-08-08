#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 合并两个有序的链表，合并后仍然有序。
 * */
char * merge_two_sorted_array(char *arr1, int a1_len, char *arr2, int a2_len)
{
    if (NULL == arr1 || 0 == a1_len) {
        return arr2;
    }
    if (NULL == arr2 || 0 == a2_len) {
        return arr1;
    }

    char *arr_n = NULL;

    arr_n = malloc(a1_len + a2_len);
    if (NULL == arr_n) {
        return arr_n;
    }

    int i = 0, j = 0;
    int n = 0;

    while (i < a1_len && j < a2_len) {
        if (arr1[i] < arr2[j]) {
            arr_n[n] = arr1[i];
            i++;
        } else {
            arr_n[n] = arr2[j];
            j++;
        }
        n++;
    }

    int rest = 0;
    if (i >= a1_len) {
        rest = a2_len - j;
        while (rest-- > 0) {
            arr_n[n] = arr2[j];
            n++;
            j++;
        }
    } else {
        rest = a1_len - i;
        while (rest-- > 0) {
            arr_n[n] = arr1[i];
            n++;
            i++;
        }
    }

    return arr_n;
}

int main(void)
{
    char arr1[] = "135678FGHIJKNefgz";
    char arr2[] = "249ALMabcdxy";

    char *new = NULL;

    new = merge_two_sorted_array(arr1, strlen(arr1), arr2, strlen(arr2));

    printf("new = [%s]\n", new);

    return 0;
}
