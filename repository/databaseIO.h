#ifndef DATABASE_IO_H
#define DATABASE_IO_H


#include "../entity/Student.h"
#include "../entity/Teacher.h"
#include "../entity/Subject.h"
#include "../entity/Grade.h"
#include "../container/List.h"

#include <fstream>
//Making use of standard input and output functions of the fstream header

//  ---- STUDENTS ----

List<Student> getAllStudents() {
    List<Student> result;

    ifstream fin("../database/students.txt");

    while(!fin.eof()) {
        Student* newStudent = new Student();

        fin >> newStudent->studentId >> newStudent->firstName
            >> newStudent->lastName >> newStudent->age >> newStudent->classId;

        push_back(result, newStudent);
    }
    // there is not only one EOF character. in the end of the file there are some special characters correlated to EOF.
    // these characters will in the end create a new element in the list with garbage information. so we remove the last element.
    pop_back(result);

    return result;
}

void writeAllStudents(const List<Student>& list) {
    ofstream fout("../database/students.txt");

    for(ListNode<Student> *student = list.head; student != nullptr; student = student->next) {
        fout << student->data->studentId << " " << student->data->firstName << " "
            << student->data->lastName << " " << student->data->age << " " << student->data->classId << endl;
    }
}

// ----- TEACHERS ------

List<Teacher> getAllTeachers() {
    List<Teacher> result;

    ifstream fin("../database/teachers.txt");

    while(!fin.eof()) {
        Teacher* newTeacher = new Teacher();

        fin >> newTeacher->teacherId >> newTeacher->username >> newTeacher->password >> newTeacher->firstName >> newTeacher->lastName >> newTeacher->age >> newTeacher->salary;

        result = push_back(result, newTeacher);
    }
    // there is not only one EOF character. in the end of the file there are some special characters correlated to EOF.
    // these characters will in the end create a new element in the list with garbage information. so we remove the last element.
    pop_back(result);

    return result;
}

void writeAllTeachers(const List<Teacher>& list) {
    ofstream fout("../database/teachers.txt");

    for(ListNode<Teacher> *teacher = list.head; teacher != nullptr; teacher = teacher->next) {
        fout << teacher->data->teacherId << " " << teacher->data->username << " " << teacher->data->password << " "
                << teacher->data->firstName << " " << teacher->data->lastName << " " << teacher->data->age << " " << teacher->data->salary << endl;
    }
}

// ----- SUBJECTS -----

List<Subject> getAllSubjects() {
    List<Subject> result;

    ifstream fin("../database/subjects.txt");

    while(!fin.eof()) {
        Subject* newSubject = new Subject();

        fin >> newSubject->courseId >> newSubject->subjectName >> newSubject->teacherId;

        push_back(result, newSubject);
    }
    // there is not only one EOF character. in the end of the file there are some special characters correlated to EOF.
    // these characters will in the end create a new element in the list with garbage information. so we remove the last element.
    pop_back(result);

    return result;
}


void writeAllSubjects(const List<Subject>& list) {
    ofstream fout("../database/subjects.txt");

    for(ListNode<Subject> *subject = list.head; subject != nullptr; subject = subject->next) {
        fout << subject->data->courseId << " " << subject->data->subjectName << " " << subject->data->teacherId << endl;
    }
}

// ----- GRADES ------

List<Grade> getAllGrades() {
    List<Grade> result;

    ifstream fin("../database/grades.txt");

    while(!fin.eof()) {
        Grade* newGrade = new Grade();

        fin >> newGrade->subjectId >> newGrade->studentId >> newGrade->classId >> newGrade->grade;

        push_back(result, newGrade);
    }
    // there is not only one EOF character. in the end of the file there are some special characters correlated to EOF.
    // these characters will in the end create a new element in the list with garbage information. so we remove the last element.
    pop_back(result);

    return result;
}

void writeAllGrades(const List<Grade>& list) {
    ofstream fout("../database/grades.txt");

    for(ListNode<Grade> *grade = list.head; grade != nullptr; grade = grade->next) {
        fout << grade->data->subjectId << " " << grade->data->studentId << " " << grade->data->classId << " " << grade->data->grade << endl;
    }
}

#endif