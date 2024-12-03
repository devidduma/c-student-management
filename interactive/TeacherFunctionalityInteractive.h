#ifndef TEACHER_FUNCTIONALITY_INTERACTIVE_H
#define TEACHER_FUNCTIONALITY_INTERACTIVE_H

#include "../repository/TeacherFunctionality.h"

void teacherViewAllCoursesYouTeach(const Teacher& teacher) {
    cout << endl << "Here is the list of courses you teach: " << endl;
    cout << "[courseId subjectName teacherId]" << endl;

    List<Subject> subjects = getAllCoursesYouTeach(teacher);

    for(ListNode<Subject> *subject = subjects.head; subject != nullptr; subject = subject->next) {
        cout << subject->data->courseId << " " << subject->data->subjectName << " " << subject->data->teacherId;
        cout << endl;
    }
}

void teacherViewStudentsWithCourseIdAndClassId(const Teacher& teacher) {
    cout << endl << "For what courseId and classId you want to show the list of students and grades ?" << endl;
    int courseId;
    int classId;
    cin >> courseId >> classId;

    cout << "Here is the list of students and grades they took for the courseId and classId you entered:" << endl;
    cout << "[studentId firstName lastName subjectId classId grade]" << endl;

    Vector<Vector<Vector<Grade>>> grades = getListStudentsOfCourseAndClassSorted(courseId, classId, teacher);

    for(int iStud = 0; iStud < grades.size; iStud++)
        for(int iSub = 0; iSub < grades.data[iStud].size; iSub++)
            for(int iGrade = 0; iGrade < grades.data[iStud].data[iSub].size; iGrade++) {
                Student* student = fetchStudentWithStudentId(grades.data[iStud].data[iSub].data->studentId);

                cout << grades.data[iStud].data[iSub].data->studentId << " "
                    << student->firstName << " "
                    << student->lastName << " "
                    << grades.data[iStud].data[iSub].data->subjectId << " "
                    << grades.data[iStud].data[iSub].data->classId << " "
                    << grades.data[iStud].data[iSub].data->grade
                    << endl;
            }
}

void teacherAddGrade() {
    cout << endl << "Enter grade information as follows: " << endl;
    cout << "[subjectId studentId classId grade]" <<endl;

    Grade* grade = new Grade();
    cin >> grade->subjectId >> grade->studentId >> grade->classId >> grade->grade;

    addGrade(grade);
}

void teacherViewMeanForSubjectAndClass() {
    cout << endl << "For which courseId and classId do you want the arithmetic mean ? "<< endl;
    int courseId;
    int classId;
    cin >> courseId >> classId;

    cout << "Arithmetic Mean for courseId " << courseId << " and classId " << classId << " is: ";
    double arithmeticMean = arithmeticMeanForCourseAndClass(courseId, classId);
    cout << arithmeticMean << endl;
}

void teacherViewMeanOfStudentAllCoursesAllYears() {
    cout << endl << "For which studentId do you want to see the arithmetic mean ? "<< endl;
    int studentId;
    cin >> studentId;

    cout << "Arithmetic mean for studentId " << studentId << " is as follows: " << endl;
    Vector<double> arithmeticMean;
    arithmeticMean = arithmeticMeanForStudentAllCoursesAllYears(studentId);

    for(int i = 0; i < 4; i++) {
        cout << "Class " << i+6 << ": " << arithmeticMean.data[i] << endl;
    }
}

#endif