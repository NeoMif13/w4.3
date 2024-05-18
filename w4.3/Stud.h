#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_NAME_LENGTH = 100;

class Student
{
private:
    int id;
    char fullName[MAX_NAME_LENGTH];
    int age;
    int course;
    char gender;
    int marks;

public:
    Student();
    Student(int id, const char* name, int age, int course, char gender, int marks);
    Student(const Student& other);
    Student(Student&& other);
    ~Student();

    void fillFromKeyboard();
    Student& operator=(const Student& other);
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
    void print();

    static int countBadStudents(const Student* students, int numStudents, int targetCourse);
    int getId() const;
};
