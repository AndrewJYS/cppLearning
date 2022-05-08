#include<stdio.h>

int main(void)
{
    int a = 4;
    int* p1 = &a;
    float* p2 = &a;
    double* p3 = &a;

    printf("int pointer p1 is %p\n", p1);
    printf("float pointer p2 is %p\n", p2);
    printf("double pointer p3 is %p\n", p3);

    *p1 = 3.67;
    printf("%f\n", *p1);
    printf("%d", a);

    return 0;

}
