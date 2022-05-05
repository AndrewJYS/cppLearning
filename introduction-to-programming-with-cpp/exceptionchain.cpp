#include <iostream>
#include <stdexcept>
using namespace std;

void function1();
void function2();
void function3();


int main()
{
    try
    {
        function1();
        cout << "statement 1" << endl;
    }
    catch(runtime_error)
    {
        cout << "runtime error" << endl;
    }
    cout << "statement 2" << endl;

    return 0;
}

void function1()
{
    try
    {
        function2();
        cout << "statement 3" << endl;
    }
    catch(logic_error)
    {
        cout << "logic error" << endl;
    }
    cout << "statement 4" << endl;
}

void function2()
{
    try
    {
        function3();
        cout << "statement 5" << endl;
    }
    catch(bad_alloc)
    {
        cout << "bad allocation" << endl;
    }
    cout << "statement 6" << endl;
}

void function3()
{
    int num;
    cin >> num;
    if (num == 0)
        throw logic_error("zero");
}
