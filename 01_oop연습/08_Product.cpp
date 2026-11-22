
#include <iostream>

class Product
{
public:
    Product()
        : Name("")
    , Price(0)
    , Quantity(0)
    , DiscountRate(0)
    {
    }

    ~Product()
    {
    }

    void SetName(const char* name)
    {
        size_t length = strlen(name);
        strncpy(Name, name, length);
        Name[length] = '\0';
    }

    void SetPrice(double price)
    {
        Price = price;
    }

    void SetQuantity(int quantity)
    {
        Quantity = quantity;
    }

    void SetDiscountRate(double rate)
    {
        DiscountRate = rate;
    }

    double GetFinalPrice()
    {
        return Price * Quantity * (1 - DiscountRate);
    }
    void Print()
    {
        std::cout << "Product: " << Name << " | Price: $" << Price << " | Quantity: " << Quantity << " | Discount: " << DiscountRate * 100 << "%\n";
        std::cout << "Total after discount: $" << GetFinalPrice();
    }
private:
    char Name[256];
    double Price;
    int Quantity;
    double DiscountRate;
};

int main()
{
    Product product;
    product.SetName("Pen");
    product.SetPrice(2.0);
    product.SetQuantity(10);
    product.SetDiscountRate(0.1);

    product.Print();
    return 0;
}
