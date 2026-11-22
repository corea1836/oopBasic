#include <iostream>
#include <cstring>

//Q: getter 만들 때 char* 를 반환타입으로 받았는데 이건 배열의 맨 앞 아닌가? 왜 cout 하면 이름 전체가 다 나올까?
//Q: 특정 소수점자리수까지만 반환하는 방법?


class Person
{
public:
    Person()
        : mName("")
        , mAge(0)
        , mGender("")
        , mNationality("")
    {
    }

    ~Person() {}

    void SetName(const char* name)
    {
        size_t length = std::strlen(name);
        std::strncpy(mName, name, length);
        mName[length] = '\0';
    }

    char* GetName()
    {
        return mName;
    }

    void SetAge(const int age)
    {
        mAge = age;
    }

    int GetAge()
    {
        return mAge;
    }

    void SetGender(const char* gender)
    {
        size_t length = strlen(gender);
        strncpy(mGender, gender, length);
        mGender[length] = '\0';
    }

    char* GetGender()
    {
        return mGender;
    }

    void SetNationality(const char* nationality)
    {
        size_t length = strlen(nationality);
        strncpy(mNationality, nationality, length);
        mNationality[length] = '\0';
    }

    void Introduce()
    {
        std::cout << "My name is " << mName << ", " << mAge << "years old, " << mGender << ", from " << mNationality << "\n";
    }
private:
    char mName[256];
    int mAge;
    char mGender[256];
    char mNationality[256];
};

int main()
{
    Person person;
    person.SetName("Alice");
    person.SetAge(25);
    person.SetGender("Female");
    person.SetNationality("Canada");

    person.Introduce();

    char* name = person.GetName();
    std::cout << name << std::endl;
    return 0;
}