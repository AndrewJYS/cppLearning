#include <stdio.h>

int main(void)
{
    char name[40];
    scanf("%s", name);
    printf("your name is %s", name);

    while(getchar() != '\n')
        continue;

    scanf("%c", &name[0]);//���û�������while��䣬scanf���������ǰ��scanf����������ݣ�������ڶ����������
    printf("your name is %s", name);

    return 0;
}
