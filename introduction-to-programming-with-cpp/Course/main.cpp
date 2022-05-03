#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

int main()
{
    Course course1("Data Structures", 10);
    Course course2(course1);
    course1.addStudent("Peter Jones");
    course1.addStudent("Brain Smith");
    course1.addStudent("Anne Kennedy");

    Course course3 = course1;
    course3.addStudent("Kitty");

    cout << course3.getCourseName() << endl;
    cout << course3.getNumberOfStudents() << endl;

    string* students1 = course1.getStudents();
    for (int i = 0; i < course3.getNumberOfStudents(); i++)
        cout<< students1[i] << ",";
    cout << endl;

    string* students3 = course3.getStudents();
    for (int i = 0; i < course3.getNumberOfStudents(); i++)
        cout<< students3[i] << ",";
    cout << endl;

    return 0;
}
