#include "StudD.h"
#include "Stud.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const char* filename = "students.bin";

    StudentDatabase database;

    cout << "������� ���������� ���������: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "������� " << i + 1 << ":" << endl;
        database.addStudent();
        database.saveToFile(filename);
    }

    database.loadFromFile(filename);

    cout << endl;
    database.print();

    int targetCourse;
    cout << "������� ����� �����: ";
    cin >> targetCourse;

    int underPerformCount = Student::countBadStudents(database.getStudents(), database.getNumStudents(), targetCourse);
    cout << "���������� ������������ ��������� �� " << targetCourse << " �����: " << underPerformCount << std::endl;

    int searchId;
    cout << "������� ID �������� ��� ������: ";
    cin >> searchId;
    database.searchStudentById(searchId);

    return 0;
}