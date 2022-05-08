// cypher1.c -- alters input, preserving spaces
#include <stdio.h>
#define SPACE ' ' // that's quote-space-quote
int main(void)
{
    char ch;


    while ((ch = getchar()) != '\n') // while not end of line
    {
        if (ch == SPACE) // leave the space
            putchar(ch); // character unchanged
        else
            putchar(ch + 1); // change other characters
    }
    putchar(ch); // print the newline

    return 0;
}
