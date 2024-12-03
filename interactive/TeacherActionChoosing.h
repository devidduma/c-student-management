#ifndef TEACHER_ACTION_CHOOSING_H
#define TEACHER_ACTION_CHOOSING_H

#include "../repository/TeacherFunctionality.h"
// Make use of standard IO functions from iostream header
#include <iostream>
using namespace std;

enum class TeacherActionChoice {
    teacherViewStudentsWithCourseIdAndClassId = 1,
    teacherAddGrade = 2,
    teacherViewMeanForSubjectAndClass = 3,
    teacherViewMeanOfStudentAllCoursesAllYears = 4,
    teacherLogout = 100,
    teacherUndefined
};

TeacherActionChoice teacherChooseAction() {
    cout << endl << "What would you like to do ?" << endl;
    cout << "\tView list of students for courseId and classId = 1\n"
            << "\tAdd grade = 2\n"
            << "\tView mean for subject and class = 3\n"
            << "\tView mean of student for all courses and all years = 4\n"
            << "\tLogout = 100\n";

    int choiceVal;
    cin >> choiceVal;

    TeacherActionChoice choice;
    switch(choiceVal) {
        case 1:
            choice = TeacherActionChoice::teacherViewStudentsWithCourseIdAndClassId;
            break;
        case 2:
            choice = TeacherActionChoice::teacherAddGrade;
            break;
        case 3:
            choice = TeacherActionChoice::teacherViewMeanForSubjectAndClass;
            break;
        case 4:
            choice = TeacherActionChoice::teacherViewMeanOfStudentAllCoursesAllYears;
            break;
        case 100:
            choice = TeacherActionChoice::teacherLogout;
            break;
        default:
            choice = TeacherActionChoice::teacherUndefined;
    }

    return choice;
}

#endif