#include <stdio.h>

int main(void)
{
    char name[40];
    scanf("%s", name);
    printf("your name is %s", name);

    while(getchar() != '\n')
        continue;

    scanf("%c", &name[0]);//如果没有上面的while语句，scanf会继续填入前面scanf处输入的内容，不会给第二次输入机会
    printf("your name is %s", name);

    return 0;
}
