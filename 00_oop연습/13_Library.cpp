
#include <cstring>
#include <iostream>
#include <vector>

static void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Book
{
public:
    Book()
    {
    }
    ~Book()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetAuthor(const char* author)
    {
        SetCharMember(Author, author);
    }

    void SetGenre(const char* genre)
    {
        SetCharMember(Genre, genre);
    }

    void SetPages(int pages)
    {
        Pages = pages;
    }

    void Print()
    {
        std::cout << "- \"" << Name << "\" by " << Author << " (" << Genre << ", " << Pages << "p)\n" ;
    }
private:
    char Name[256] = "";
    char Author[256] = "";
    char Genre[256] = "";
    int Pages = 0;
};

class Library
{
public:
    Library()
    {
    }

    ~Library()
    {
    }

    void SetManager(const char* name)
    {
        SetCharMember(ManagerName, name);
    }

    void SetLocation(const char* location)
    {
        SetCharMember(Location, location);
    }

    void AddBook(Book book)
    {
        books.push_back(book);
    }

    void Print()
    {
        std::cout << "Library: " << Location << " Library | Manager: " << ManagerName << "\n";
        std::cout << "Books:\n";
        for (int i = 0; i < books.size(); i++)
        {
            books[i].Print();
        }
    }
private:
    char ManagerName[256] = "";
    char Location[256] = "";
    std::vector<Book> books; // 책은 복사되니까
};

int main()
{
    Book A;
    A.SetName("1984");
    A.SetAuthor("Orwell");
    A.SetGenre("Dystopia");
    A.SetPages(320);

    Book B;
    B.SetName("Dune");
    B.SetAuthor("Herbert");
    B.SetGenre("Sci-Fi");
    B.SetPages(500);

    Library library;
    library.SetLocation("Central");
    library.SetManager("Ms. Kim");
    library.AddBook(A);
    library.AddBook(B);

    library.Print();

    return 0;
}