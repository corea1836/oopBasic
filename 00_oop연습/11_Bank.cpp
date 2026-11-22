

#include <cstring>
#include <iostream>
#include <vector>

struct History
{
    enum class HistoryType
    {
        Deposit,
    };

    HistoryType Type;
    int Amount;

    History() = default;

    History(HistoryType type, int amount)
    {
        Type = type;
        Amount = amount;
    }
};

class BankAccount
{
public:
    BankAccount()
    {
    }

    ~BankAccount()
    {
    }

    void SetAccount(const char* account)
    {
        SetCharMember(Account, account);
    }

    void SetBank(const char* bank)
    {
        SetCharMember(Bank, bank);
    }

    void SetType(const char* type)
    {
        SetCharMember(BankingType, type);
    }

    void SetBalance(int balance)
    {
        Balance = balance;
    }

    void Deposit(int amount)
    {
        if (amount < 0)
        {
            return;
        }

        Histories.push_back(History(History::HistoryType::Deposit, amount));
    }

    void PrintHistories()
    {
        std::cout << "Balance: $" << Balance << " -> ";
        int final = Balance;
        for (int i = 0; i < Histories.size(); i++)
        {
            if (Histories[i].Type == History::HistoryType::Deposit)
            {
                std::cout << "Deposit $" << Histories[i].Amount << " -> ";
                final += Histories[i].Amount;
            }
        }

        std::cout << "Balance: $" << final << "\n";
    }

    void Print()
    {
        std::cout << "Account: " << Account << " | Bank: " << Bank << " | Type: " << BankingType << "\n";
        PrintHistories();
    }
private:
    void SetCharMember(char* dest, const char* input)
    {
        size_t length = strlen(input);
        strncpy(dest, input, length);
        dest[length] = '\0';
    }

    char Account[256] = "";
    char Bank[256] = "";
    char BankingType[256] = "";
    int Balance = 0;
    std::vector<History> Histories;
};

class Customer
{
public:
    Customer()
    {
    }

    ~Customer()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetPhone(const char* phone)
    {
        SetCharMember(Phone, phone);
    }

    void SetAge(int age)
    {
        Age = age;
    }

    void SetAccount(BankAccount *account)
    {
        Account = account;
    }

    void Print()
    {
        std::cout << "Customer: " << Name << " | Phone: " << Phone << " | Age: " << Age << "\n";
        (*Account).Print();
    }

private:
    void SetCharMember(char* dest, const char* input)
    {
        size_t length = strlen(input);
        strncpy(dest, input, length);
        dest[length] = '\0';
    }

    char Name[256] = "";
    char Phone[256] = "";
    int Age = 0;
    BankAccount* Account;
};

int main()
{
    BankAccount account;
    account.SetAccount("123-456");
    account.SetBank("Hana");
    account.SetType("Saving");
    account.SetBalance(1500);

    Customer customer;
    customer.SetName("Alice");
    customer.SetPhone("010-1234-5678");
    customer.SetAge(27);
    customer.SetAccount(&account);

    account.Deposit(200);

    customer.Print();

    return 0;
}