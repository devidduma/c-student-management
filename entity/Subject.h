#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

struct Subject {
        int courseId;
        string subjectName;
        int teacherId;

        //constructors
        Subject() = default;

        Subject(int courseId, string& subjectName, int teacherId) :
        courseId(courseId),
        subjectName(subjectName),
        teacherId(teacherId)
        {}
};

#endif