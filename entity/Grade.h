#ifndef GRADE_H
#define GRADE_H

#include <string>
using namespace std;

struct Grade {
    int subjectId;
    int studentId;
    int classId;
    double grade;

    //constructors
    Grade() = default;

    Grade(int subjectId, int studentId, int classId, double grade) :
        subjectId(subjectId),
        studentId(studentId),
        classId(classId),
        grade(grade)
    {}
};

#endif