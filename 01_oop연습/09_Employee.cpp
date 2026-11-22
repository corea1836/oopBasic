

#include <iostream>

class Employee
{
public:
    Employee()
    {
    }

    ~Employee()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetDepartment(const char* department)
    {
        SetCharMember(Department, department);
    }

    void SetYear(int year)
    {
        Year = year;
    }

    void SetBaseSalary(int salary)
    {
        BaseSalary = salary;
    }

    void SetBonusRate(int rate)
    {
        BonusRate = rate;
    }

    int GetTotalSalary()
    {
        return BaseSalary * (100 + BonusRate) / 100;
    }

    void Print()
    {
        std::cout << "Employee: " << Name << " | Department: " << Department << " | Years: " << Year << "\n";
        std::cout << "Base: " << BaseSalary << ", Bonus: " << BonusRate << "%\n";
        std::cout << "Total Salary: " << GetTotalSalary() << "\n";
    }
private:
    void SetCharMember(char* dest, const char* input)
    {
        size_t length = strlen(input);
        strncpy(dest, input, length);
        dest[length] = '\0';
    }

    char Name[256] = "";
    char Department[256] = "";
    int Year = 0;
    int BaseSalary = 0;
    int BonusRate = 0;
};

int main()
{
    Employee employee;
    employee.SetName("Jane");
    employee.SetDepartment("HR");
    employee.SetYear(5);
    employee.SetBaseSalary(3000);
    employee.SetBonusRate(15);

    employee.Print();
    return 0;
}
