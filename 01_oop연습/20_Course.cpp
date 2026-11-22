#include <cstring>
#include <iostream>

void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Student
{
public:
    Student()
    {
    }

    ~Student()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetSerial(const char* serial)
    {
        SetCharMember(Serial, serial);
    }

    void SetGrade(const char* grade)
    {
        SetCharMember(Grade, grade);
    }

    void SetClass(const char* name)
    {
        SetCharMember(Class, name);
    }

    void Print()
    {
        std::cout << "- " << Name << " (" << Class << ", " << Grade << " year)\n";
    }

private:
    char Name[256] = "";
    char Serial[256] = "";
    char Grade[256] = "";
    char Class[256] = "";
};

class Course
{
public:
    Course()
    {
    }

    ~Course()
    {
    }

    void SetTitle(const char* title)
    {
        SetCharMember(Title, title);
    }

    void SetInstructor(const char* instructor)
    {
        SetCharMember(Instructor, instructor);
    }

    void SetCapacity(int cap)
    {
        Capacity = cap;
    }

    void AddStudent(Student* student)
    {
        Students.push_back(student);
    }

    void Print()
    {
        std::cout << "Course: " << Title << " | Instructor: " << Instructor << " | Capacity: " << Capacity << "\n";
        std::cout << "Students:\n";
        for (int i = 0; i < Students.size(); i++)
        {
            (*Students[i]).Print();
        }
    }
private:
    char Title[256] = "";
    char Instructor[256] = "";
    int Capacity = 0;
    std::vector<Student*> Students;
};

int main()
{
    Student a;
    a.SetName("Alice");
    a.SetGrade("2nd");
    a.SetClass("CS");
    a.SetSerial("A");

    Student b;
    b.SetName("Bob");
    b.SetGrade("1st");
    b.SetClass("EE");
    b.SetSerial("B");

    Student c;
    c.SetName("Charlie");
    c.SetGrade("3rd");
    c.SetClass("CS");
    c.SetSerial("C");

    Course course;
    course.SetTitle("Programming 101");
    course.SetInstructor("Dr. Kim");
    course.SetCapacity(30);
    course.AddStudent(&a);
    course.AddStudent(&b);
    course.AddStudent(&c);

    course.Print();

    return 0;
}