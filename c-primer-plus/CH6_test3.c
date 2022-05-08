#include <stdio.h>
#define SIZE 10

int main(void)
{
    SIZE = 15; //wrong statement
    printf("SIZE is %d", SIZE);

    const int size = 10;
    size = 15; //wrong statement, const variable is read-only
    printf("size is %d", size);

    return 0;
}
