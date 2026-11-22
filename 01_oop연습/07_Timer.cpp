

#include <iostream>

class Timer
{
public:
    Timer()
        : TotalSecond(0)
        , Started(0)
        , Elapsed(0)
        , Name("")
    {

    }

    ~Timer()
    {
    }

    void SetTime(int totalSecond, int started, int elapsed)
    {
        TotalSecond = totalSecond;
        Started = started;
        Elapsed = elapsed;
    }

    void SetName(const char* name)
    {
        size_t length = strlen(name);
        strncpy(Name, name, length);
        Name[length] = '\0';
    }

    void Print()
    {
        std::cout << "Timer \"" << Name << "\"" << " started.\n" ;
        std::cout << "Elapsed: " << Elapsed << "s / Total: " << TotalSecond << "s \n";
    }
private:
    int TotalSecond;
    int Started;
    int Elapsed;
    char Name[256];
};

int main()
{
    Timer timer;
    timer.SetName("Cooking");
    timer.SetTime(300, 0, 90);

    timer.Print();
    return 0;
}