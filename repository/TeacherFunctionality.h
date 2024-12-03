#ifndef TEACHER_FUNCTIONALITY_H
#define TEACHER_FUNCTIONALITY_H


#include "../container/List.h"
#include "../container/Vector.h"
#include "../entity/Teacher.h"
#include "../entity/Subject.h"
#include "../entity/Grade.h"
#include "../repository/databaseIO.h"

//----- getAllCoursesYouTeach ------

// recursive function
// helper function
List<Subject> getAllCoursesYouTeach(const Teacher& teacher, ListNode<Subject> *subject) {
    // base case, if end of list return empty List<Subject>
    if(subject == nullptr)
        return {};

    // if teacher teaches current subject in the subjects list
    if(subject->data->teacherId == teacher.teacherId) {
        // recursive call for next subject. it's result is a list, and we push_back current subject to that list
        List<Subject> coursesITeach = getAllCoursesYouTeach(teacher, subject->next);
        return push_back(coursesITeach, subject->data);
    } else {
        // recursive call for next subject. since subject is not taught by teacher, don't push_back subject
        return getAllCoursesYouTeach(teacher, subject->next);
    }
}

// Function Polymorphism
// Default parameters
List<Subject> getAllCoursesYouTeach(const Teacher& teacher, List<Subject> subject = getAllSubjects()) {
    return getAllCoursesYouTeach(teacher, subject.head);
}

/*
 * deprecated in order to use the recursive version above
List<Subject> getAllCoursesYouTeach(Teacher teacher, List<Subject> subjects) {
    List<Subject> result;

    for(ListNode<Subject> *subject = subjects.head; subject != nullptr; subject = subject->next) {
        if(subject->data->teacherId == teacher.teacherId)
            push_back(result, subject);
    }

    return result;
}
 */


// ------ getListStudentsOfCourseAndClass --------

// recursive function
// get a list of grades for a specific courseId and classId, unsorted
List<Grade> getListStudentsOfCourseAndClassRaw(int courseId, int classId, ListNode<Grade> *grade) {
    // base case, if end of list return empty List<Grade>
    if(grade == nullptr)
        return {};

    // if courseId and classId are what we are looking for in grades
    if(courseId == grade->data->subjectId && classId == grade->data->classId) {
        // recursive call. it's result is a list. push_back grade to that list, and return list
        List<Grade> listByCourseClass = getListStudentsOfCourseAndClassRaw(courseId, classId, grade->next);
        return push_back(listByCourseClass, grade->data);
    } else {
        // recursive call. it's result is a list. don't push_back grade, since it is not what we are looking for. return list.
        return getListStudentsOfCourseAndClassRaw(courseId, classId, grade->next);
    }
}

// Function Polymorphism
// helper function
List<Grade> getListStudentsOfCourseAndClassRaw(int courseId, int classId, List<Grade> grades) {
    return getListStudentsOfCourseAndClassRaw(courseId, classId, grades.head);
}

/* deprecated in order to use the recursive version above
// does not check if teacher is allowed to add grades for that subject
private List<Grade> getListStudentsOfCourseAndClassRaw(int courseId, int classId, List<Grade> grades) {
    //grades result not sorted
    List<Grade> result;

    for(ListNode<Grade> *grade = grades.head; grade != nullptr; grade = grade->next) {
        // grade with courseId and classId found for any student
        if(courseId == grade->data->subjectId && classId == grade->data->classId) {

            //push_back the grade in the result list
            push_back(result, *grade);
        }
    }

    return result;
}
 */

//sorts the list of grades by studentId then subjectId
// helper function
Vector<Vector<Vector<Grade>>> getListStudentsOfCourseAndClassSorted(int courseId, int classId, List<Grade> grades) {
    //get raw results for grades with courseId, classId specified
    grades = getListStudentsOfCourseAndClassRaw(courseId, classId, grades);

    //result grades, sorted by studentId, then by subjectId
    Vector<Vector<Vector<Grade>>> result;

    for(ListNode<Grade> *grade = grades.head; grade != nullptr; grade = grade->next) {

        //check if studentId found in the 3D vector, otherwise, push_back
        int iStud = 0;
        while(iStud < result.size) {
            if(result.data[iStud].data[0].data->studentId == grade->data->studentId)
                break;
            iStud++;
        }
        if(iStud == result.size)
            push_back(result);

        //check if subjectId found in the 3D vector, otherwise, push_back
        int iSub = 0;
        while(iSub < result.data[iStud].size) {
            if(result.data[iStud].data[iSub].data->subjectId == grade->data->subjectId)
                break;
            iSub++;
        }
        if(iSub == result.data[iStud].size)
            push_back(result.data[iStud]);

        //push_back the grade in the correct position in the 3D vector
        push_back(result.data[iStud].data[iSub], grade->data);
    }

    return result;
}


// Function Polymorphism / Overloading
// Default parameters
// checks if teacher is allowed to add grades for that subject
// sorts the list of grades by studentId then subjectId
Vector<Vector<Vector<Grade>>> getListStudentsOfCourseAndClassSorted(int courseId, int classId, const Teacher& teacher,
        List<Grade> grades = getAllGrades(), List<Subject> subjects = getAllSubjects()) {
    // either subject = getAllSubjects() or subject = getAllCoursesYouTeach(teacher), but the last one is overkill, since we are checking here both teacherId and courseId

    //initialize to false
    bool allowed = false;
    for(ListNode<Subject> *subject = subjects.head; subject != nullptr; subject = subject->next) {
        if(subject->data->courseId == courseId && subject->data->teacherId == teacher.teacherId) {
            allowed = true;
            break;
        }
    }

    Vector<Vector<Vector<Grade>>> result;
    if(allowed) {
        result = getListStudentsOfCourseAndClassSorted(courseId, classId, grades);
        return result;
    } else {
        return result;
    }
}

Student* fetchStudentWithStudentId(int studentId) {
    List<Student> list = getAllStudents();

    ListNode<Student> *student;
    for(student = list.head; student != nullptr; student = student->next) {
        if(student->data->studentId == studentId)
            break;
    }

    return student->data;
}


// ------ addGrade -------

void addGrade(Grade* grade, bool persist = true, List<Grade> grades = getAllGrades()) {
    push_back(grades, grade);

    if(persist)
        writeAllGrades(grades);
}


// ------ Arithmetic Means ------

// Making use of standard functions: operator/()
double arithmeticMeanForCourseAndClass(int courseId, int classId, List<Grade> grades = getAllGrades()) {
    grades = getListStudentsOfCourseAndClassRaw(courseId, classId, grades);

    //calculate
    double sum = 0;
    int counter = 0;
    for (ListNode<Grade> *grade = grades.head; grade != nullptr; grade = grade->next) {
        sum += grade->data->grade;
        counter++;
    }
    double arithmeticMean = sum / double(counter);

    return arithmeticMean;
}

// Making use of standard functions: operator/()
Vector<double> arithmeticMeanForStudentAllCoursesAllYears(int studentId, List<Grade> grades = getAllGrades()) {
    // index 0 for year 6, index 1 for year 7, index 2 for year 8, index 3 for year 9
    double sum[4] = {0};
    int count[4] = {0};

    for(ListNode<Grade> *grade = grades.head; grade != nullptr; grade = grade->next) {
        if(grade->data->studentId == studentId) {
            sum[grade->data->classId - 6] += grade->data->grade;
            count[grade->data->classId - 6]++;
        }
    }

    Vector<double> arithmeticMean;
    for(int i = 0; i < 4; i++) {
        arithmeticMean.data[i] = sum[i] / double(count[i]);
    }
    return arithmeticMean;
}

#endif