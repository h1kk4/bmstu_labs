#include <iostream>
#include "TPerson.h"
#include "Student.h"
int main() {
    TPerson person("Alex",18);
    person.Print();
    person.SetName("Jack");
    person.SetAge(20);
    person.Print();
    Student student("Felix",20,2);
    student.SetName("Nick");
    student.SetAge(19);
    student.Set_Year(4);
    student.AddYear();
    student.Print();
    return 0;
}