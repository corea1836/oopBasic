#include <cstring>
#include <iostream>

void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Engine
{
public:
    Engine()
    {
    }

    ~Engine()
    {
    }

    void SetHorsePower(int horsePower)
    {
        HorsePower = horsePower;
    }

    void SetFuelType(const char* fuelType)
    {
        SetCharMember(FuelType, fuelType);
    }

    void SetType(const char* type)
    {
        SetCharMember(Type, type);
    }

    void Print()
    {
        std::cout << "Engine: " << HorsePower << "HP | Fuel: " << FuelType << " | Type: " << Type << "\n";
    }
private:
    int HorsePower = 0;
    char FuelType[256] = "";
    char Type[256] = "";
};

class Car
{
public:
    Car()
    {
    }

    ~Car()
    {
    }

    void SetBrand(const char* brand)
    {
        SetCharMember(Brand, brand);
    }

    void SetModel(const char* model)
    {
        SetCharMember(Model, model);
    }

    void SetYear(int year)
    {
        Year = year;
    }

    void SetEngine(Engine *engine)
    {
        Engine = engine;
    }

    void Print()
    {
        std::cout << "Car: " << Brand << " " << Model << "(" << Year << ")\n";
        (*Engine).Print();
    }
private:
    char Brand[256] = "";
    char Model[256] = "";
    int Year = 0;
    Engine* Engine;
};

int main()
{
    Engine V8;
    V8.SetHorsePower(450);
    V8.SetFuelType("Gasoline");
    V8.SetType("V8");

    Car Mustang;
    Mustang.SetBrand("Ford");
    Mustang.SetModel("Mustang");
    Mustang.SetYear(2022);
    Mustang.SetEngine(&V8);

    Mustang.Print();
    return 0;
}