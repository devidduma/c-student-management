Devid Duma Project Midterm C++

Instructions:

1) Please use C++11 or newer. The project uses nullptr.
2) Please put the executables in their own folder after compilation parallel to database folder so that it can find the .txt files. The ifstream looks at relative paths starting with "../". Example:
ifstream fin("../database/students.txt");
3) The project assumes there are some garbage characters before end of file is reached. At least that is how things work in my linux PC. This means that when reading from .txt files, the last input will contain garbage info. I worked around this by popping off the last element when saving them in lists.
4) If the above requirements are met, the project behaves successfully as described in all functionalities.

Documentation:

First you are greeted and asked to login. The login menu will keep appearing as long as you have not successfully logged in (because of bad username or password). 
Then the program provides very basic outputs able to guide the user in the process of executing actions that view, add or update stuff. The first menu is that of action choosing, you input a number corresponding to an action, then the action's menu comes asking you for more input information. When the action is completed, you return to the main menu that is action choosing. You can also logout, which terminates the program. You are advised to follow the instructions carefully when adding or updating, since not inputing information exactly as it is required may lead to unexpected behaviour.

Problems during development:

Problems that arose during development were about memory management: organizing the use of scope and destructors with the delete command. I tried using destructors to free up memory, but very often i got a SIGABRT (signal abort) or a SIGSEGV (segmentation fault). So i ended up not using any destructors, which could cause memory leaks.

Challenges:

The challenges were mostly about solving the problems mentioned above. I think one challenge was being restricted to structs and not being able to use classes. The reason is, that whenever i tried something like push_back(&list, data) i gave the push_back() method the opportunity to call the list's destructor when the push_back() method finished executing and the referenced variable inside push_back() got out of scope. Doing something like list = push_back(&list, data), i.e. making use of operator= did not help either. list = push_back(list, data) where list was not a reference but a copy (using copy constructor) did not help either. Somehow the list inside push_back() was destroyed before being able to return it.

Then it struck me that this was happening because the list contained a POINTER to a head element, and the copy constructor or operator= was copying the pointer to the new list. So after copying / assigning the value, the memory it was pointing at was still going to be destroyed because of the other list going out of scope.

If we had used classes though the story would have been a little different, since the push_back() function could have been called inside list object and would not require passing it as a parameter to the function, which would eliminate the possibility of a list copy going out of scope. Still though, returning it from a function would still destroy it.

After finishing the project i realized that there is no way of magically destroying objects on the heap when they are no longer needed by tuning destructors and scopes of variables. In C++ you HAVE to use delete explicitly when the objects are no longer needed. It is also mandatory to create an object on the heap if you want it to leave longer than the scope of a function block allows you to.

What would i have done differently:

I would have invested some more time using delete when objects are no longer needed but i already had spent enough time on the project and had to move on to other projects and assignments. 
