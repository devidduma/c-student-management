#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student {
    int studentId;
    string firstName;
    string lastName;
    int age;
    int classId;

    //constructors
    Student() = default;

    Student(int studentId, string& firstName, string& lastName, int age, int classId) :
        studentId(studentId),
        firstName(firstName),
        lastName(lastName),
        age(age),
        classId(classId)
    {}
};

#endif