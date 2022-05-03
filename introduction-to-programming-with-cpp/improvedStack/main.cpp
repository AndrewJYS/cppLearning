#include <iostream>
#include <vector>
#include "improvedStack.h"
using namespace std;

template<typename T>
void printStack(Stack<T>& stack)
{
    while(!stack.isEmpty())
        cout << stack.pop() << " ";
    cout << endl;
}

int main()
{
    Stack<int> intStack;

    for (int i = 0; i < 18; i++)
        intStack.push(i);
    printStack(intStack);

    //vector<int> deck(5);

    return 0;
}
