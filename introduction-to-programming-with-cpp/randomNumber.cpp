#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int num1 = rand() % 10;
    int num2 = rand() % 10;

    cout << num1 << " " << num2 << endl;

    return 0;
}
