#include <cstring>
#include <iostream>
#include <vector>

static void SetCharMember(char* dest, const char* input)
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

    void SetScore(int score)
    {
        Score = score;
    }

    void SetGrade(const char* grade)
    {
        SetCharMember(Grade, grade);
    }

    void SetClass(const char* className)
    {
        SetCharMember(Class, className);
    }

    void Print()
    {
        std::cout << "- " << Name << " (Grade " << Grade << ", Class " << Class << "): " << Score << "\n";
    }

private:
    char Name[256] = "";
    int Score = 0;
    char Grade[256] = "";
    char Class[256] = "";
};

class Teacher
{
public:
    Teacher()
    {
    }

    ~Teacher()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetSubject(const char* subject)
    {
        SetCharMember(Subject, subject);
    }

    void SetYears(int years)
    {
        Years = years;
    }

    void AddStudent(Student student)
    {
        students.push_back(student);
    }

    void Print()
    {
        std::cout << "Teacher: " << Name << " (" << Subject << ", " << Years << " years)\n";
        for (int i = 0; i < students.size(); i++)
        {
            students[i].Print();
        }
    }
private:
    char Name[256] = "";
    char Subject[256] = "";
    int Years = 0;
    std::vector<Student> students;
};

int main()
{
    Student A;
    A.SetName("Tom");
    A.SetGrade("2");
    A.SetClass("A");
    A.SetScore(85);

    Student B;
    B.SetName("Jane");
    B.SetGrade("2");
    B.SetClass("A");
    B.SetScore(90);

    Student C;
    C.SetName("Sam");
    C.SetGrade("2");
    C.SetClass("A");
    C.SetScore(75);

    Teacher teacher;
    teacher.SetName("Mr. Lee");
    teacher.SetSubject("Math");
    teacher.SetYears(10);
    teacher.AddStudent(A);
    teacher.AddStudent(B);
    teacher.AddStudent(C);

    teacher.Print();
    return 0;
}