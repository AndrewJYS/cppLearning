#include <iostream>
#include <stdexcept>
using namespace std;

int quotient(int num1, int num2)
{
    if (num2 == 0)
        throw runtime_error("Divisor cannot be zero");

    return num1 / num2;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    try
    {
        int result = quotient(num1, num2);
        cout << result << endl;
    }
    catch (runtime_error& ex)
    {
        cout << ex.what() << endl;
    }

    cout << "Execution continues ...";

    return 0;
}
