#include <stdio.h>

struct B{
    char b;
    int a;
    short c;
};

struct C{
    int a;
    double b;
    float c;
};

struct D{ 
    char e[2]; 
    int f; 
    double g;   
    short h; 
    struct C i; 
}; 

#define OFFSET(st, filed) (unsigned int)&(((typeof(st)*)0)->filed)

int main(void)
{
    printf("sizeof(B) = %d\n", sizeof(struct B)); //12
    printf("sizeof(double) = %d, sizeof(float) = %d\n", sizeof(double), sizeof(float));//8, 4
    
    struct C c;
    printf("&c->b = %d, &c->c = %d\n", OFFSET(c, b), OFFSET(c, c));

    //旧的gcc，会按照结构体中，最大的成员进行对齐，补齐。
    //新的gcc，会安装4字节（32位机上）进行对齐。好像进行了强制的4字节对齐。
    printf("sizeof(C) = %d\n", sizeof(struct C)); //new-gcc 16 / old-gcc 24
    printf("sizeof(D) = %d\n", sizeof(struct D));  //new-gcc 36 / old-gcc 48
    struct D d;

    printf("offset of D, f=%d, g=%d, h=%d, i=%d\n", 
        OFFSET(d, f), OFFSET(d, g), OFFSET(d, h), OFFSET(d, i));
        //new-gcc: offset of D, f=4, g=8, h=16, i=20
        //old-gcc: offset of D, f=4, g=8, h=16, i=24

    return 0;
}
