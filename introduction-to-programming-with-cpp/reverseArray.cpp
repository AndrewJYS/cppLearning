#include<iostream>
using namespace std;

int* reverse1(int* list, int size)
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }

    return list;
}

int* reverse2(int* list, int size)
{
    int* result = new int[size];

    for (int i = 0, j = size - 1; i < size; i++, j--)
        result[i] = list[j];

    return result;
}

void printArray(const int* list, int size)
{
    for (int i = 0; i < size; i++)
        cout<< list[i] << " ";
}

int main()
{
    int list[] = {1, 2, 3, 4, 5, 6};
    int* p = reverse2(list, 6);

    printArray(p, 6);
    delete p;
    delete [] list;

    return 0;
}
