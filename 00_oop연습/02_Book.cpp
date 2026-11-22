
#include <cstdint>
#include <cstring>
#include <iostream>

class Book
{
public:
    Book()
        : Title("")
    , Author("")
    , Publisher("")
    , Price(0)
    {
    }

    ~Book()
    {
    }

    void SetTitle(const char* title)
    {
        size_t length = strlen(title);
        strncpy(Title, title, length);
        Title[length] = '\0';
    }

    char* GetTitle()
    {
        return Title;
    }

    void SetAuthor(const char* author)
    {
        size_t length = strlen(author);
        strncpy(Author, author, length);
        Author[length] = '\0';
    }

    char* GetAuthor()
    {
        return Author;
    }

    void SetPublisher(const char* publisher)
    {
        size_t length = strlen(publisher);
        strncpy(Publisher, publisher, length);
        Publisher[length] = '\0';
    }

    char* GetPublisher()
    {
        return Publisher;
    }

    void SetPrice(double price)
    {
        Price = price;
    }

    double GetPrice()
    {
        return Price;
    }

    void Introduce()
    {
        std::cout << "[Book]\n";
        std::cout << "Title: \"" << Title << "\"\n";
        std::cout << "Author: \"" << Author << "\"\n";
        std::cout << "Publisher: \"" << Publisher << "\"\n";
        std::cout << "Price: $" << Price << "\n";
    }

private:
    char Title[256];
    char Author[256];
    char Publisher[256];
    double Price;
};

int main()
{
    Book book;
    book.SetTitle("1984");
    book.SetAuthor("George Orwell");
    book.SetPublisher("Penguin");
    book.SetPrice(15.99);

    book.Introduce();
    return 0;
}