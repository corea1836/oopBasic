
#include <iostream>

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

    void SetDuration(int duration)
    {
        Duration = duration;
    }

    void SetGenre(const char* genre)
    {
        SetCharMember(Genre, genre);
    }

    void SetRated(int rated)
    {
        Rated = rated;
    }

    void SetDirector(const char* director)
    {
        SetCharMember(Director, director);
    }

    void Print()
    {
        std::cout << "[Movie]\n";
        std::cout << "Title: " << Title << std::endl;
        std::cout << "Duration: " << Duration << " min" << std::endl;
        std::cout << "Genre: " << Genre << std::endl;
        std::cout << "Rated: " << Rated << "+" << std::endl;
        std::cout << "Directed by: " << Director << std::endl;
    }
private:
    void SetCharMember(char* dest, const char* input)
    {
        size_t length = strlen(input);
        strncpy(dest, input, length);
        dest[length] = '\0';
    }

    char Title[256] = "";
    int Duration = 0;
    char Genre[256] = "";
    int Rated = 0;
    char Director[256] = "";
};

int main()
{
    Movie movie;
    movie.SetTitle("Interstellar");
    movie.SetDuration(169);
    movie.SetGenre("Sci-Fi");
    movie.SetRated(12);
    movie.SetDirector("Nolan");

    movie.Print();

    return 0;
}
