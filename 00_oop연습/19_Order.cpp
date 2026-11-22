#include <cstring>
#include <iostream>

void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Product
{
public:
    Product()
    {
    }

    ~Product()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetPrice(int price)
    {
        Price = price;
    }

    void SetQuantity(int quantity)
    {
        Quantity = quantity;
    }

    void SetDiscountRate(int rate)
    {
        DiscountRate = rate;
    }

    void Print()
    {
        std::cout << "- " << Name << ": $" << Price << " x " << Quantity << " (Discount " << DiscountRate << "%) -> $" << GetFinalPrice() << "\n";
    }

    int GetFinalPrice()
    {
        return Price * Quantity * (100 - DiscountRate) / 100;
    }
private:
    char Name[256] = "";
    int Price = 0;
    int Quantity = 0;
    int DiscountRate = 0;
};

class Order
{
public:
    Order()
    {
    }

    ~Order()
    {
    }

    void SetOwnerName(const char* name)
    {
        SetCharMember(OwnerName, name);
    }

    void SetOrderDate(const char* date)
    {
        SetCharMember(OrderDate, date);
    }

    void AddProduct(Product *product)
    {
        Products.push_back(product);
    }

    void Print()
    {
        std::cout << "Order by: " << OwnerName << " | Date: " << OrderDate << "\n";
        std::cout << "Items: \n";
        int totalPrice = 0;
        for (int i = 0; i < Products.size(); i++)
        {
            Products[i]->Print();
            totalPrice += (*Products[i]).GetFinalPrice();
        }
        std::cout << "Total: $" << totalPrice << "\n";
    }
private:
    char OwnerName[256] = "";
    char OrderDate[256] = "";
    std::vector<Product*> Products;
};

int main()
{
    Product Keyboad;
    Keyboad.SetName("Keyboard");
    Keyboad.SetPrice(50);
    Keyboad.SetQuantity(1);
    Keyboad.SetDiscountRate(0);

    Product Mouse;
    Mouse.SetName("Mouse");
    Mouse.SetPrice(20);
    Mouse.SetQuantity(2);
    Mouse.SetDiscountRate(10);

    Order order;
    order.SetOwnerName("Alice");
    order.SetOrderDate("2024-05-18");
    order.AddProduct(&Keyboad);
    order.AddProduct(&Mouse);

    order.Print();
    return 0;
}