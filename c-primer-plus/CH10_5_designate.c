#include<stdio.h>


int main(void)
{
    const int MONTHS = 12; // const不是整型常量表达式，因此会报错，可以用#define MONTHS 12
    int days[MONTHS] = {31, 28, [4]=31, 30,31, [1]=29 };
    int i;

    for (i = 0; i < MONTHS; i++)
        printf("%2d  %d\n", i + 1, days[i]);

    return 0;
}
