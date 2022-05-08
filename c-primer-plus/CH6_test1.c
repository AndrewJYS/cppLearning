#include <stdio.h>
int main(void)
{
    int num;
    char ch;

    while(scanf("%d", &num) == 1)
        ; //skip integers

    scanf("%c", &ch);
    printf("The character is %c", ch);

    return 0;
}
