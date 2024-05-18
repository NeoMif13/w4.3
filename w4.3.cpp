#include "Stud.h "
#include "StudD.h "
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    const char* filename = "students.bin";
    const int MAX_STUDENTS = 100;

    Student students[MAX_STUDENTS];
    int numStudents;

    cout << "Введите количество студентов: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Студент " << i + 1 << ":" << endl;
        students[i].fillFromKeyboard();
        students[i].saveToFile(filename);
    }

    cout << endl;
    cout << "Информация о студентах:" << endl;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Студент " << i + 1 << ":" << endl;
        students[i].print();
        cout << endl;
    }

    int targetCourse;

    cout << "Введите номер курса: ";
    cin >> targetCourse;

    int underPerformCount = Student::countBadStudents(students, numStudents, targetCourse);
    cout << "Количество неуспевающих студентов на " << targetCourse << " курсе: " << underPerformCount << endl;


    Student student1; // Вызов конструктора без параметров
    cout << "Информация о студенте 1:" << endl;
    student1.print();
    cout << endl;
    Student student2(1,"John Doe", 20, 2, 'M', 7); // Вызов конструктора с параметрами
    cout << "Информация о студенте 2:" << endl;
    student2.print();
    cout << endl;
    Student student3 = student2; // Вызов конструктора копирования
    cout << "Информация о студенте 3:" << endl;
    student3.print();
    cout << endl;
    Student student4 = move(student2); // Вызов конструктора перемещения
    cout << "Информация о студенте 4:" << endl;
    student4.print();
    cout << endl;



    return 0;
}