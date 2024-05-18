#include "Stud.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student()//��� ����������
{
    fullName[0] = '\0';
    age = 0;
    course = 0;
    gender = '\0';
    marks = 0;
    id = 0;
}

Student::Student(const char* name, int age, int course, char gender, int marks,int id)// � �����������
{
    strncpy_s(fullName, name, MAX_NAME_LENGTH);
    fullName[MAX_NAME_LENGTH - 1] = '\0';
    this->age = age;
    this->course = course;
    this->gender = gender;
    this->marks = marks;
    this->id = id;
}

Student::Student(const Student& other)//�����������
{
    strncpy_s(fullName, other.fullName, MAX_NAME_LENGTH);
    fullName[MAX_NAME_LENGTH - 1] = '\0';
    age = other.age;
    course = other.course;
    gender = other.gender;
    marks = other.marks;
    id = other.id;

}

Student::Student(Student&& other)//�����������
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
    // ����������
}

void Student::fillFromKeyboard()
{
    cin.ignore();

    cout << "���: ";
    cin.getline(fullName, MAX_NAME_LENGTH);
    do
    {
        cout << "������� (�� 16 �� 30): ";
        cin >> age;

        if (age < 16 || age > 30)
        {
            cout << "������� �������� �� 16 �� 30." << endl;
        }
    } while (age < 16 || age > 30);


    do
    {
        cout << "���� (�� 1 �� 6): ";
        cin >> course;

        if (course < 1 || course > 6)
        {
            cout << "������� �������� �� 1 �� 6." << endl;
        }
    } while (course < 1 || course > 30);


    cout << "��� (m/f): ";
    cin >> gender;

    do
    {
        cout << "������������ (�� 0 �� 10): ";
        cin >> marks;

        if (marks < 0 || marks > 10)
        {
            cout << "������� �������� �� 0 �� 10." << endl;
        }
    } while (marks < 0 || marks > 10);
}

void Student::saveToFile(const char* filename)
{
    ofstream outputFile(filename, ios::binary | ios::app);

    if (!outputFile.is_open())
    {
        cout << "������ �������� ����� " << filename << endl;
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
        cout << "������ �������� ����� " << filename << endl;
        return;
    }

    inputFile.read(reinterpret_cast<char*>(this), sizeof(Student));

    inputFile.close();
}

void Student::print()
{
    cout << "ID: " << id << endl;
    cout << "���: " << fullName << endl;
    cout << "�������: " << age << endl;
    cout << "����: " << course << endl;
    cout << "���: " << gender << endl;
    cout << "������������: ";

    if (marks >= 0 && marks <= 10)
        cout << marks << endl;
    else
        cout << "������������ ��������" << endl;
  
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