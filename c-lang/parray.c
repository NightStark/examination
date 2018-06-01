#include <stdio.h>
#include <stdlib.h>

int show_hello(char *w)
{
    printf("%s\n", w);
    return 0;
}

int datas[4] = {0xAA, 0xBB, 0xCC, 0xDD};
int (*get_datas(char *w)) [4]
{
    printf("%s\n", w);
    return &datas;
}

int main(void)
{
    char b[4] = {0xAA}; 
    char (*a)[4]; 
    a = &b;
    printf("sizeof(a) = %d\n", sizeof(a)); //4

    char *c[4];
    printf("sizeof(c) = %d\n", sizeof(c)); //4 x 4

    int (*s_h)(char *);
    s_h = show_hello;
    printf("sizeof(s_h) = %d\n", sizeof(s_h)); //4
    s_h("I say hello.");

    int (*s_h_a[4])(char *); //"函数指针" 数组, s_h_a是一个数组， 数组里面放的是指针，指针是函数指针
    printf("sizeof(s_h_a) = %d\n", sizeof(s_h_a)); //4 x 4
    s_h_a[2] = show_hello;
    s_h_a[2]("I sa hello with array-pointer");

    typedef int (*s_h_b_t[4])(char *); 
    s_h_b_t *s_h_a_p = &s_h_a;
    printf("sizeof(s_h_a_p) = %d\n", sizeof(s_h_a_p)); //4
    int (*(*s_h_c_p)[4])(char *); //s_h_c_p 是一个指针， 指向一个数组，这个数组放的是 函数指针
    s_h_c_p = &s_h_a;
    printf("sizeof(s_h_c_p) = %d\n", sizeof(s_h_c_p)); //4
    (*s_h_c_p)[2]("I say good.");

    int (*(*s_h_d)(char *))[4]; //s_h_d 是一个指针，指向一个函数，函数的参数是char *, 返回值是个指针( 指针指向一个数组 )
    printf("sizeof(s_h_d) = %d\n", sizeof(s_h_d)); //4
    s_h_d = get_datas;
    printf("(*s_h_d)[3] = %X\n", (*s_h_d("Give me a 4"))[3]);

    int (*(*s_h_e[4])(char *))[4];
    printf("sizeof(s_h_e) = %d\n", sizeof(s_h_e)); //4 x 4
    //s_h_d[3] = get_datas; //虽然这个定义是对的，但是s_h_e是一个右值。

    int (*(*(*s_h_f)[4])(char *))[4]; 
    //s_h_f 是一个指针，指向一个数组，数组元素的类型是指针，指向的类型为函数指针，函数的换回值为指针( 指针指向一个数组 )
    
    printf("sizeof(s_h_f) = %d\n", sizeof(s_h_f)); //4
    //printf("(*s_h_d[3])[3] = %X\n", (*s_h_d[3]("Give me a 4"))[3]);

    return 0;
}
