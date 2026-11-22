
#include <cstring>
#include <iostream>

void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Item
{
public:
    Item()
    {
    }

    ~Item()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetDescription(const char* description)
    {
        SetCharMember(Description, description);
    }

    void SetWeight(double weight)
    {
        Weight = weight;
    }

    void SetAmount(int amount)
    {
        Amount = amount;
    }

    void Print()
    {
        std::cout << "Item: " << Name << " - " << Description << " (x" << Amount << ") | Weight: " << Weight << "\n";
    }
private:
    char Name[256] = "";
    char Description[256] = "";
    double Weight = 0.0;
    int Amount = 0;
};

class Inventory
{
public:
    Inventory()
    {
    }
    ~Inventory()
    {
    }

    void SetOwner(const char* owner)
    {
        SetCharMember(OwnerName, owner);
    }

    void AddItem(Item* item)
    {
        Items.push_back(item);
    }

    void Print()
    {
        std::cout << "Inventory of: " << OwnerName << "\n";
        for (int i = 0; i < Items.size(); i++)
        {
            (*Items[i]).Print();
        }
    }
private:
    char OwnerName[256] = "";
    std::vector<Item*> Items;
};

int main()
{
    Item A;
    A.SetName("Potion");
    A.SetDescription("Heals 50HP");
    A.SetAmount(5);
    A.SetWeight(0.5);

    Item B;
    B.SetName("Bomb");
    B.SetDescription("Deals 100 Damage");
    B.SetAmount(2);
    B.SetWeight(1.0);

    Inventory inventory;
    inventory.SetOwner("Player1");
    inventory.AddItem(&A);
    inventory.AddItem(&B);

    inventory.Print();
    return 0;
}