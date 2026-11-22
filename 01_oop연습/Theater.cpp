
#include <cstring>
#include <iostream>

void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Movie
{
public:
    Movie()
    {
    }

    ~Movie()
    {
    }

    void SetTitle(const char* title)
    {
        SetCharMember(Title, title);
    }

    void SetRunningTime(int runningTime)
    {
        RunningTime = runningTime;
    }

    void SetGenre(const char* genre)
    {
        SetCharMember(Genre, genre);
    }

    void SetGrade(const char* grade)
    {
        SetCharMember(Grade, grade);
    }

    int GetRunningTime()
    {
        return RunningTime;
    }

    void Print()
    {
        std::cout << "- \"" << Title << " \" (" << RunningTime << " min, " << Grade << ")\n";
    }
private:
    char Title[256] = "";
    int RunningTime = 0;
    char Genre[256] = "";
    char Grade[256] = "";
};

class Theater
{
public:
    Theater()
    {
    }

    ~Theater()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetLocation(const char* location)
    {
        SetCharMember(Location, location);
    }

    void AddMovie(Movie movie)
    {
        Movies.push_back(movie);
    }

    void Print()
    {
        std::cout << "Theater: " << Name << " | Location: " << Location << "\n";
        std::cout << "Now Showing:\n";
        int totalRunning = 0;
        for (int i = 0; i < Movies.size(); i++)
        {
            Movies[i].Print();
            totalRunning += Movies[i].GetRunningTime();
        }
        std::cout << "Total: " << totalRunning << " minutes\n";
    }
private:
    char Name[256] = "";
    char Location[256] = "";
    std::vector<Movie> Movies;
};

int main()
{
    Movie Avatar;
    Avatar.SetTitle("Avatar");
    Avatar.SetRunningTime(162);
    Avatar.SetGrade("Adventure");
    Avatar.SetGrade("12+");

    Movie Titanic;
    Titanic.SetTitle("Titanic");
    Titanic.SetRunningTime(195);
    Titanic.SetGenre("Romance");
    Titanic.SetGrade("ALL");

    Theater theater;
    theater.SetName("CGV Gangnam");
    theater.SetLocation("Seoul");
    theater.AddMovie(Avatar);
    theater.AddMovie(Titanic);

    theater.Print();
    return 0;
}