#include <stdio.h>

void whileloop();
void forloop();

int main(void)
{
    whileloop();
    forloop();

    return 0;
}

void whileloop()
{
    int count = 0;
    char ch;

    while (count < 10)
    {
        ch = getchar();
        if (ch == '\n')
            continue;
        putchar(ch);
        count++;
    }

    printf("\nwhileloop is over.\n");
}

void forloop()
{
    int count;
    char ch;

    for (count = 0; count < 10; count++)
    {
        ch = getchar();
        if (ch == '\n')
            continue;
        putchar(ch);
    }

    printf("\nforloop is over.\n");
}
