#include "entity/Teacher.h"
#include "repository/databaseIO.h"
#include <iostream>
#include <string>

Teacher* lookupTeacherInfoInDatabase(const string& username, const string& password) {
    List<Teacher> teachers = getAllTeachers();

    for(ListNode<Teacher> *teacher = teachers.head; teacher != nullptr; teacher = teacher->next) {
        if(teacher->data->username == username && teacher->data->password == password)
            return teacher->data;
    }

    return nullptr;
}

// tail recursive function
Teacher* login() {
    cout << "Please login: ";

    string username;
    string password;

    cin >> username >> password;

    // first base case
    if(username == "admin" && password == "admin")
        return nullptr;
    else {
        Teacher *teacher = lookupTeacherInfoInDatabase(username, password);
        // second base case
        if(teacher != nullptr)
            return teacher;
    }

    cout << "Logging in was not possible! Either username or password was wrong. Try again." <<endl;
    return login();
}