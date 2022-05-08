#include<stdio.h>

int main(void)
{
    int num1, num2;
    char ch;

    /*
    printf("please enter two numbers.\n");
    scanf("%d%d", &num1, &num2);
    printf("the first number is %d, and the second number is %d\n", num1, num2);

    printf("Now please enter two numbers again.\n");
    scanf("%d%d", &num1, &num2);
    printf("the first number is %d, and the second number is %d\n", num1, num2);

    printf("Now please enter two numbers again.\n");
    scanf("%d, %d", &num1, &num2); // mind the comma between two %d(s)
    printf("the first number is %d, and the second number is %d\n", num1, num2);
    */

    printf("Now please enter a character\n");
    scanf("%c", &ch);
    printf("The character is %c\n", ch);

    printf("Now please enter a character again\n");
    scanf(" %c", &ch);
    printf("The character is %c\n", ch);


    return 0;
}
