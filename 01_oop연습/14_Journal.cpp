
#include <cstring>
#include <iostream>

static void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}


class Author
{
public:
    Author()
    {
    }

    ~Author()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetEmail(const char* email)
    {
        SetCharMember(Email, email);
    }

    void SetField(const char* field)
    {
        SetCharMember(Field, field);
    }

    void Print()
    {
        std::cout << "Author: " << Name << " | Email: " << Email << " | Field: " << Field << "\n";
    }

private:
    char Name[256] = "";
    char Email[256] = "";
    char Field[256] = "";
};

class Article
{
public:
    Article()
    {
    }

    ~Article()
    {
    }

    void SetTitle(const char* title)
    {
        SetCharMember(Title, title);
    }

    void SetWrittenDate(const char* writtenDate)
    {
        SetCharMember(WrittenDate, writtenDate);
    }

    void SetWordCounts(int wordCounts)
    {
        WordCounts = wordCounts;
    }

    void SetAuthor(Author author)
    {
        Author = author;
    }

    void Print()
    {
        std::cout << "Article: \"" << Title << "\" (" << WordCounts << " chars)\n";
        Author.Print();
    }
private:
    char Title[256] = "";
    char WrittenDate[256] = "";
    int WordCounts = 0;
    Author Author;
};

int main()
{
    Author author;
    author.SetName("Alice Kim");
    author.SetEmail("alice@domain.com");
    author.SetField("Computer Science");

    Article article;
    article.SetTitle("Rise of AI");
    article.SetWordCounts(1240);
    article.SetAuthor(author);

    article.Print();

    return 0;
}