#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

struct Teacher {
    int teacherId;
    string username;
    string password;
    string firstName;
    string lastName;
    int age;
    double salary;

    //constructors
    Teacher() = default;

    Teacher(int teacherId, string& username, string& password, string& firstName, string& lastName, int age, double salary) {
        this->teacherId = teacherId;
        this->username = username;
        this->password = password;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->salary = salary;
    }
};

#endif