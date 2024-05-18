#include "Stud.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student()//без параметров
{
    fullName[0] = '\0';
    age = 0;
    course = 0;
    gender = '\0';
    marks = 0;
    id = 0;
}

Student::Student(const char* name, int age, int course, char gender, int marks,int id)// с параметрами
{
    strncpy_s(fullName, name, MAX_NAME_LENGTH);
    fullName[MAX_NAME_LENGTH - 1] = '\0';
    this->age = age;
    this->course = course;
    this->gender = gender;
    this->marks = marks;
    this->id = id;
}

Student::Student(const Student& other)//копирования
{
    strncpy_s(fullName, other.fullName, MAX_NAME_LENGTH);
    fullName[MAX_NAME_LENGTH - 1] = '\0';
    age = other.age;
    course = other.course;
    gender = other.gender;
    marks = other.marks;
    id = other.id;

}

Student::Student(Student&& other)//перемещения
{
    strncpy_s(fullName, other.fullName, MAX_NAME_LENGTH);
    fullName[MAX_NAME_LENGTH - 1] = '\0';
    age = other.age;
    course = other.course;
    gender = other.gender;
    marks = other.marks;
    id = other.id;
    other.fullName[0] = '\0';
    other.age = 0;
    other.course = 0;
    other.gender = '\0';
    other.marks = 0;
    other.id = 0;
}

Student::~Student()
{
    // Деструктор
}

void Student::fillFromKeyboard()
{
    cin.ignore();

    cout << "ФИО: ";
    cin.getline(fullName, MAX_NAME_LENGTH);
    do
    {
        cout << "Возраст (от 16 до 30): ";
        cin >> age;

        if (age < 16 || age > 30)
        {
            cout << "Введите значение от 16 до 30." << endl;
        }
    } while (age < 16 || age > 30);


    do
    {
        cout << "Курс (от 1 до 6): ";
        cin >> course;

        if (course < 1 || course > 6)
        {
            cout << "Введите значение от 1 до 6." << endl;
        }
    } while (course < 1 || course > 30);


    cout << "Пол (m/f): ";
    cin >> gender;

    do
    {
        cout << "Успеваемость (от 0 до 10): ";
        cin >> marks;

        if (marks < 0 || marks > 10)
        {
            cout << "Введите значение от 0 до 10." << endl;
        }
    } while (marks < 0 || marks > 10);
}

void Student::saveToFile(const char* filename)
{
    ofstream outputFile(filename, ios::binary | ios::app);

    if (!outputFile.is_open())
    {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }

    outputFile.write(reinterpret_cast<const char*>(this), sizeof(Student));

    outputFile.close();
}

void Student::loadFromFile(const char* filename)
{
    ifstream inputFile(filename, ios::binary);

    if (!inputFile.is_open())
    {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }

    inputFile.read(reinterpret_cast<char*>(this), sizeof(Student));

    inputFile.close();
}

void Student::print()
{
    cout << "ID: " << id << endl;
    cout << "ФИО: " << fullName << endl;
    cout << "Возраст: " << age << endl;
    cout << "Курс: " << course << endl;
    cout << "Пол: " << gender << endl;
    cout << "Успеваемость: ";

    if (marks >= 0 && marks <= 10)
        cout << marks << endl;
    else
        cout << "Некорректное значение" << endl;
  
}

int Student::countBadStudents(Student* students, int numStudents, int targetCourse)
{
    int underperformingCount = 0;

    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].course == targetCourse && students[i].marks < 5)
        {
            underperformingCount++;
        }
    }

    return underperformingCount;
}