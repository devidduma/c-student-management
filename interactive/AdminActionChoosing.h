#ifndef ADMIN_ACTION_CHOOSING_H
#define ADMIN_ACTION_CHOOSING_H

#include "../repository/AdminFunctionality.h"
// Make use of standard IO functions from iostream header
#include <iostream>
using namespace std;

enum class AdminActionChoice {
    adminViewAllStudents = 1,
    adminViewAllTeachers = 2,
    adminViewAllCourses = 3,
    adminAddNewStudent = 4,
    adminAddNewTeacher = 5,
    adminAddNewCourse = 6,
    adminUpdateStudent = 7,
    adminUpdateTeacher = 8,
    adminUpdateCourse = 9,
    adminLogout = 100,
    adminUndefined
};

AdminActionChoice adminChooseAction() {
    cout << endl << "What would you like to do ?" << endl;
    cout << "\tView all students = 1\n"
            << "\tView all teachers = 2\n"
            << "\tView all courses = 3\n"
            << "\tAdd new student = 4\n"
            << "\tAdd new teacher = 5\n"
            << "\tAdd new course = 6\n"
            << "\tUpdate student = 7\n"
            << "\tUpdate teacher = 8\n"
            << "\tUpdate course = 9\n"
            << "\tLogout = 100\n";

    int choiceVal;
    cin >> choiceVal;

    AdminActionChoice choice;
    switch(choiceVal) {
        case 1:
            choice = AdminActionChoice::adminViewAllStudents;
            break;
        case 2:
            choice = AdminActionChoice::adminViewAllTeachers;
            break;
        case 3:
            choice = AdminActionChoice::adminViewAllCourses;
            break;
        case 4:
            choice = AdminActionChoice::adminAddNewStudent;
            break;
        case 5:
            choice = AdminActionChoice::adminAddNewTeacher;
            break;
        case 6:
            choice = AdminActionChoice::adminAddNewCourse;
            break;
        case 7:
            choice = AdminActionChoice::adminUpdateStudent;
            break;
        case 8:
            choice = AdminActionChoice::adminUpdateTeacher;
            break;
        case 9:
            choice = AdminActionChoice::adminUpdateCourse;
            break;
        case 100:
            choice = AdminActionChoice::adminLogout;
            break;
        default:
            choice = AdminActionChoice::adminUndefined;
    }

    return choice;
}

#endif