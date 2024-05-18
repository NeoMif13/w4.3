#include "StudD.h"

StudD::StudD() : students(nullptr), numStudents(0)
{
    // Конструктор без параметров
}

StudD::StudD(const StudD& other) : students(nullptr), numStudents(0)
{
    copyFrom(other);
}

StudD::StudD(StudD&& other) : students(nullptr), numStudents(0)
{
    moveFrom(std::move(other));
}

StudD& StudD::operator=(const StudD& other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

StudD& StudD::operator=(StudD&& other)
{
    if (this != &other)
    {
        clear();
        moveFrom(std::move(other));
    }
    return *this;
}

StudD::~StudD()
{
    clear();
}

void StudD::addStudent()
{
    Student newStudent;
    newStudent.fillFromKeyboard();

    Student* newStudents = new Student[numStudents + 1];
    for (int i = 0; i < numStudents; i++)
    {
        newStudents[i] = students[i];
    }
    newStudents[numStudents] = newStudent;

    delete[] students;
    students = newStudents;
    numStudents++;
}

void StudD::loadDatabase()
{
    clear();

    std::ifstream inputFile(DATABASE_FILENAME, std::ios::binary);
    if (!inputFile.is_open())
    {
        std::cout << "Ошибка открытия файла " << DATABASE_FILENAME << std::endl;
        return;
    }

    inputFile.read(reinterpret_cast<char*>(&numStudents), sizeof(int));
    students = new Student[numStudents];
    inputFile.read(reinterpret_cast<char*>(students), sizeof(Student) * numStudents);

    inputFile.close();
}

void StudD::saveDatabase()
{
    std::ofstream outputFile(DATABASE_FILENAME, std::ios::binary);
    if (!outputFile.is_open())
    {
        std::cout << "Ошибка открытия файла " << DATABASE_FILENAME << std::endl;
        return;
    }

    outputFile.write(reinterpret_cast<const char*>(&numStudents), sizeof(int));
    outputFile.write(reinterpret_cast<const char*>(students), sizeof(Student) * numStudents);

    outputFile.close();
}

void StudD::printDatabase()
{
    for (int i = 0; i < numStudents; i++)
    {
        students[i].print();
        std::cout << std::endl;
    }
}

void StudD::searchStudentById(int studentId)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getid() == studentId)
        {
            students[i].print();
            return;
        }
    }

    std::cout << "Студент с ID " << studentId << " не найден в базе данных." << std::endl;
}

void StudD::clear()
{
    delete[] students;
    students = nullptr;
    numStudents = 0;
}

void StudD::copyFrom(const StudD& other)
{
    students = new Student[other.numStudents];
    for (int i = 0; i < other.numStudents; i++)
    {
        students[i] = other.students[i];
    }
    numStudents = other.numStudents;
}

void StudD::moveFrom(StudD&& other)
{
    students = other.students;
    numStudents = other.numStudents;

    other.students = nullptr;
    other.numStudents = 0;
}
