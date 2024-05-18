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

    cout << "Введите количество студентов: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Студент " << i + 1 << ":" << endl;
        database.addStudent();
        database.saveToFile(filename);
    }

    database.loadFromFile(filename);

    cout << endl;
    database.print();

    int targetCourse;
    cout << "Введите номер курса: ";
    cin >> targetCourse;

    int underPerformCount = Student::countBadStudents(database.getStudents(), database.getNumStudents(), targetCourse);
    cout << "Количество неуспевающих студентов на " << targetCourse << " курсе: " << underPerformCount << std::endl;

    int searchId;
    cout << "Введите ID студента для поиска: ";
    cin >> searchId;
    database.searchStudentById(searchId);

    return 0;
}