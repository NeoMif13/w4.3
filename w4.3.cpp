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

    cout << "������� ���������� ���������: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "������� " << i + 1 << ":" << endl;
        students[i].fillFromKeyboard();
        students[i].saveToFile(filename);
    }

    cout << endl;
    cout << "���������� � ���������:" << endl;

    for (int i = 0; i < numStudents; i++)
    {
        cout << "������� " << i + 1 << ":" << endl;
        students[i].print();
        cout << endl;
    }

    int targetCourse;

    cout << "������� ����� �����: ";
    cin >> targetCourse;

    int underPerformCount = Student::countBadStudents(students, numStudents, targetCourse);
    cout << "���������� ������������ ��������� �� " << targetCourse << " �����: " << underPerformCount << endl;


    Student student1; // ����� ������������ ��� ����������
    cout << "���������� � �������� 1:" << endl;
    student1.print();
    cout << endl;
    Student student2(1,"John Doe", 20, 2, 'M', 7); // ����� ������������ � �����������
    cout << "���������� � �������� 2:" << endl;
    student2.print();
    cout << endl;
    Student student3 = student2; // ����� ������������ �����������
    cout << "���������� � �������� 3:" << endl;
    student3.print();
    cout << endl;
    Student student4 = move(student2); // ����� ������������ �����������
    cout << "���������� � �������� 4:" << endl;
    student4.print();
    cout << endl;



    return 0;
}