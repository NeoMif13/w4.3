#include "StudD.h"

StudentDatabase::StudentDatabase()
    : students(nullptr), numStudents(0)
{
}

StudentDatabase::~StudentDatabase()
{
    delete[] students;
}

void StudentDatabase::addStudent()
{
    Student* newStudents = new Student[numStudents + 1];
    for (int i = 0; i < numStudents; i++)
    {
        newStudents[i] = students[i];
    }
    newStudents[numStudents].fillFromKeyboard();

    delete[] students;
    students = newStudents;
    numStudents++;
}

void StudentDatabase::print()
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Студент " << i + 1 << ":" << endl;
        students[i].print();
        cout << endl;
    }
}

const Student* StudentDatabase::getStudents() const
{
    return students;
}

int StudentDatabase::getNumStudents() const
{
    return numStudents;
}

void StudentDatabase::saveToFile(const char* filename)
{
    ofstream file(filename, ios::binary);
    if (file)
    {
        file.write(reinterpret_cast<const char*>(&numStudents), sizeof(int));
        file.write(reinterpret_cast<const char*>(students), numStudents * sizeof(Student));
        file.close();
    }
    else
    {
        cout << "Ошибка при открытии файла!" << endl;
    }
}

void StudentDatabase::loadFromFile(const char* filename)
{
    ifstream file(filename, ios::binary);
    if (file)
    {
        file.read(reinterpret_cast<char*>(&numStudents), sizeof(int));

        delete[] students;
        students = new Student[numStudents];

        file.read(reinterpret_cast<char*>(students), numStudents * sizeof(Student));

        file.close();
    }
    else
    {
        cout << "Ошибка при открытии файла!" << endl;
    }
}

void StudentDatabase::searchStudentById(int id)
{
    bool found = false;
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getId() == id)
        {
            cout << "Студент найден:" << endl;
            students[i].print();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Студент с указанным ID не найден." << endl;
    }
}