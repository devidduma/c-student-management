#ifndef ADMIN_FUNCTIONALITY_INTERACTIVE_H
#define ADMIN_FUNCTIONALITY_INTERACTIVE_H

#include "../repository/AdminFunctionality.h"

void adminViewAllStudents() {
    cout << endl << "Here is the list of all students: " << endl
         << "[studentId firstName lastName age classId]" << endl;

    viewAllStudents();
    cout << endl;
}

void adminViewAllTeachers() {
    cout << endl << "Here is the list of all teachers: " << endl
         << "[teacherId username password firstName lastName age salary]" << endl;

    viewAllTeachers();
    cout << endl;
}

void adminViewAllCourses() {
    cout << endl << "Here is the list of all courses: " << endl
         << "[courseId subjectName teacherId]" << endl;

    viewAllCourses();
    cout << endl;
}

void adminAddNewStudent() {
    cout << endl << "Enter new student information in this order separated by spaces: " << endl
         << "[firstName lastName age classId]" << endl;

    Student* newStudent = new Student();
    cin >> newStudent->firstName >> newStudent->lastName >> newStudent->age >> newStudent->classId;

    addNewStudent(newStudent);
}

void adminAddNewTeacher() {
    cout << endl << "Enter new teacher information in this order separated by spaces: " << endl
         << "[username password firstName lastName age salary]" << endl;

    Teacher* newTeacher = new Teacher();
    cin >> newTeacher->username >> newTeacher->password >> newTeacher->firstName >> newTeacher->lastName >> newTeacher->age >> newTeacher->salary;

    addNewTeacher(newTeacher);
}

void adminAddNewCourse() {
    cout << endl << "Enter new course information in this order separated by spaces: " << endl
         << "[subjectName teacherId]" << endl;

    Subject* newSubject = new Subject();
    cin >> newSubject->subjectName >> newSubject->teacherId;

    addNewCourse(newSubject);
}

void adminUpdateStudent() {
    cout << endl << "Enter updated student information (studentId does not change) in this order separated by spaces: " << endl
         << "[studentId firstName lastName age classId]" << endl;

    Student* student = new Student();
    cin >> student->studentId >> student->firstName >> student->lastName >> student->age >> student->classId;

    updateStudents(student);
}

void adminUpdateTeacher() {
    cout << endl << "Enter updated teacher information (teacherId does not change) in this order separated by spaces: " << endl
         << "[teacherId username password firstName lastName age salary]" << endl;

    Teacher* teacher = new Teacher();
    cin >> teacher->teacherId >> teacher->username >> teacher->password >> teacher->firstName >> teacher->lastName >> teacher->age >> teacher->salary;

    updateTeachers(teacher);
}

void adminUpdateCourse() {
    cout << endl << "Enter updated course information (courseId does not change) in this order separated by spaces: " << endl
         << "[courseId subjectName teacherId]" << endl;

    Subject* subject = new Subject();
    cin >> subject->courseId >> subject->subjectName >> subject->teacherId;

    updateCourses(subject);
}

#endif