#include <iostream>
#include "Stack.h"
using namespace std;

template<typename T, int capacity>
void printStack(Stack<T, capacity>& stack)
{
    while(!stack.isEmpty())
        cout << stack.pop() << " ";
    cout << endl;
}

int main()
{
    Stack<int, 100> intStack;

    for (int i = 0; i < 10; i++)
        intStack.push(i);
    printStack(intStack);

    return 0;
}
