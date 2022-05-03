#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::~Course()
{
    delete [] students;
}

Course::Course(const Course& course)
{
    courseName = course.courseName;
    numberOfStudents = course.numberOfStudents;
    capacity = course.capacity;
    students = new string[capacity];
    for (int i = 0; i < numberOfStudents; i++)
        students[i] = course.students[i];
}

string Course::getCourseName() const
{
    return courseName;
}

void Course::addStudent(const string& name)
{
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
    // not finished
    numberOfStudents--;
}
string* Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

const Course& Course::operator=(const Course& course)
{
    if (this != &course)
    {
        courseName = course.courseName;
        numberOfStudents = course.numberOfStudents;
        capacity = course.capacity;

        delete [] this->students;

        students = new string[capacity];
        for (int i = 0; i < numberOfStudents; i++)
            students[i] = course.students[i];
    }

    return *this;
}
