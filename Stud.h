#ifndef STUD_H
#define STUD_H

const int MAX_NAME_LENGTH = 100;

class Student
{
private:
    char fullName[MAX_NAME_LENGTH];
    int age;
    int course;
    char gender;
    int marks;
    int id;

public:
    Student();
    Student(const char* name, int age, int course, char gender, int marks,int id);
    Student(const Student& other);
    Student(Student&& other);
    ~Student();

    void fillFromKeyboard();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
    void print();

    static int countBadStudents(Student* students, int numStudents, int targetCourse);
};

#endif // STUD_H
