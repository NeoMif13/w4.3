#ifndef STUDD_H
#define STUDD_H

#include "Stud.h"
#include <iostream>
#include <fstream>

const char* DATABASE_FILENAME = "database.bin";

class StudD
{
private:
    Student* students;
    int numStudents;

public:
    StudD();
    StudD(const StudD& other);
    StudD(StudD&& other);
    StudD& operator=(const StudD& other);
    StudD& operator=(StudD&& other);
    ~StudD();

    void addStudent();
    void loadDatabase();
    void saveDatabase();
    void printDatabase();
    void searchStudentById(int studentId);

private:
    void clear();
    void copyFrom(const StudD& other);
    void moveFrom(StudD&& other);
};

#endif  // STUDD_H

