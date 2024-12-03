#include "main.h"
// Use standard IO functions of iostream header
#include <iostream>
#include "interactive/AdminFunctionalityInteractive.h"
#include "interactive/AdminActionChoosing.h"
#include "interactive/TeacherFunctionalityInteractive.h"
#include "interactive/TeacherActionChoosing.h"
using namespace std;

int main() {
    cout << endl << "Welcome to GIS - Grade Interaction System !" << endl << endl;

    Teacher *teacher = login();

    // Admin logged in
    if(teacher == nullptr) {
        cout << endl << "Welcome Admin!" << endl;

        AdminActionChoice actionChoice;
        do {
            actionChoice = adminChooseAction();

            switch (actionChoice) {
                case AdminActionChoice::adminViewAllStudents:
                    adminViewAllStudents();
                    break;
                case AdminActionChoice::adminViewAllTeachers:
                    adminViewAllTeachers();
                    break;
                case AdminActionChoice::adminViewAllCourses:
                    adminViewAllCourses();
                    break;
                case AdminActionChoice::adminAddNewStudent:
                    adminAddNewStudent();
                    break;
                case AdminActionChoice::adminAddNewTeacher:
                    adminAddNewTeacher();
                    break;
                case AdminActionChoice::adminAddNewCourse:
                    adminAddNewCourse();
                    break;
                case AdminActionChoice::adminUpdateStudent:
                    adminUpdateStudent();
                    break;
                case AdminActionChoice::adminUpdateTeacher:
                    adminUpdateTeacher();
                    break;
                case AdminActionChoice::adminUpdateCourse:
                    adminUpdateCourse();
                    break;
                case AdminActionChoice::adminLogout:
                    break;
            }
        } while(actionChoice != AdminActionChoice::adminLogout);
    }
    // Teacher logged in
    else {
        cout << endl << "Welcome Teacher " << teacher->firstName << " " << teacher->lastName << "!" << endl;
        teacherViewAllCoursesYouTeach(*teacher);

        TeacherActionChoice actionChoice;
        do {
            actionChoice = teacherChooseAction();

            switch (actionChoice) {
                case TeacherActionChoice::teacherViewStudentsWithCourseIdAndClassId:
                    teacherViewStudentsWithCourseIdAndClassId(*teacher);
                    break;
                case TeacherActionChoice::teacherAddGrade:
                    teacherAddGrade();
                    break;
                case TeacherActionChoice::teacherViewMeanForSubjectAndClass:
                    teacherViewMeanForSubjectAndClass();
                    break;
                case TeacherActionChoice::teacherViewMeanOfStudentAllCoursesAllYears:
                    teacherViewMeanOfStudentAllCoursesAllYears();
                    break;
                case TeacherActionChoice::teacherLogout:
                    break;
            }
        } while(actionChoice != TeacherActionChoice::teacherLogout);


    }
    return 0;
}