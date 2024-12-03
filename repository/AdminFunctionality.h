#ifndef ADMIN_FUNCTIONALITY_H
#define ADMIN_FUNCTIONALITY_H


#include "databaseIO.h"
// Make use of standard IO functions from iostream header
#include <iostream>
using namespace std;

// ----- VIEW -----

// recursion
//helper_function
void viewAllStudents(ListNode<Student> *student) {
    // base case, if end of list, return
    if(student == nullptr)
        return;

    // print current student info
    cout << student->data->studentId << " " << student->data->firstName << " "
         << student->data->lastName << " " << student->data->age << " " << student->data->classId;
    cout << endl;

    // recursive call to next student
    viewAllStudents(student->next);
}

// Default parameter
// Function polymorphism
void viewAllStudents(List<Student> list = getAllStudents()) {
    cout << endl;

    viewAllStudents(list.head);
}

// recursion
//helper function
void viewAllTeachers(ListNode<Teacher> *teacher) {
    // base case, if end of list, return
    if(teacher == nullptr)
        return;

    // print current teacher info
    cout << teacher->data->teacherId << " " << teacher->data->username << " " << teacher->data->password << " "
         << teacher->data->firstName << " " << teacher->data->lastName << " " << teacher->data->age << " " << teacher->data->salary;
    cout << endl;

    // recursive call to next teacher
    viewAllTeachers(teacher->next);
}

// Default parameter
// Function polymorphism
void viewAllTeachers(List<Teacher> list = getAllTeachers()) {
    cout << endl;

    viewAllTeachers(list.head);
}

// recursion
//helper function
void viewAllCourses(ListNode<Subject> *subject) {
    // base case, if end of list, return
    if(subject == nullptr)
        return;

    // print current subject info
    cout << subject->data->courseId << " " << subject->data->subjectName << " " << subject->data->teacherId;
    cout << endl;

    // recursive call to next subject
    viewAllCourses(subject->next);
}

// Default parameter
// Function polymorphism
void viewAllCourses(List<Subject> list = getAllSubjects()) {
    cout << endl;

    viewAllCourses(list.head);
}

// ----- ADD -------

// Default parameter
void addNewStudent(Student* student, bool persist = true, List<Student> list = getAllStudents()) {
    int maxId = list.tail->data->studentId;
    student->studentId = maxId+1;

    push_back(list, student);

    if(persist)
        writeAllStudents(list);
}

// Default parameter
void addNewTeacher(Teacher* teacher, bool persist = true, List<Teacher> list = getAllTeachers()) {
    int maxId = list.tail->data->teacherId;
    teacher->teacherId = maxId+1;

    push_back(list, teacher);

    if(persist)
        writeAllTeachers(list);
}

// Default parameter
void addNewCourse(Subject* subject, bool persist = true, List<Subject> list = getAllSubjects()) {
    int maxId = list.tail->data->courseId;
    subject->courseId = maxId+1;

    push_back(list, subject);

    if(persist)
        writeAllSubjects(list);
}

// ----- UPDATE ------

// Default parameter
void updateStudents(Student* student, bool persist = true, List<Student> list = getAllStudents()) {
    for(ListNode<Student> *iStudent = list.head; iStudent != nullptr; iStudent = iStudent->next) {
        if(iStudent->data->studentId == student->studentId) {
            iStudent->data = student;
            break;
        }
    }

    if(persist)
        writeAllStudents(list);
}

// Default parameter
void updateTeachers(Teacher* teacher, bool persist = true, List<Teacher> list = getAllTeachers()) {
    for(ListNode<Teacher> *iTeacher = list.head; iTeacher != nullptr; iTeacher = iTeacher->next) {
        if(iTeacher->data->teacherId == teacher->teacherId) {
            iTeacher->data = teacher;
            break;
        }
    }

    if(persist)
        writeAllTeachers(list);
}

// Default parameter
void updateCourses(Subject* subject, bool persist = true, List<Subject> list = getAllSubjects()) {
    for(ListNode<Subject> *iSubject = list.head; iSubject != nullptr; iSubject = iSubject->next) {
        if(iSubject->data->courseId == subject->courseId) {
            iSubject->data = subject;
            break;
        }
    }

    if(persist)
        writeAllSubjects(list);
}

#endif