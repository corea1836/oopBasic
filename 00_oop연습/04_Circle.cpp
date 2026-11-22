
#include <cstring>
#include <iostream>

class Circle
{
public:
    Circle()
        : Radius(0)
        , Color("")
        , Filled(false)
        , Opacity(0)
    {
    }

    ~Circle()
    {
    }

    void SetRadius(int radius)
    {
        Radius = radius;
    }

    int GetRadius()
    {
        return Radius;
    }

    void SetColor(const char* color)
    {
        size_t length = strlen(color);
        strncpy(Color, color, length);
        Color[length] = '\0';
    }

    char* GetColor()
    {
        return Color;
    }

    void SetFilled(bool filled)
    {
        Filled = filled;
    }

    bool GetFilled()
    {
        return Filled;
    }

    void SetOpacity(double opacity)
    {
        Opacity = opacity;
    }

    double GetOpacity()
    {
        return Opacity;
    }

    double GetArea()
    {
        return Radius * Radius * 3.14;
    }

    double GetCircumference()
    {
        return 2 * Radius * 3.14;
    }

    void Introduce()
    {
        std::cout << "Circle\n";
        std::cout << "Radius: " << Radius << "\n";
        std::cout << "Color: " << Color << "\n";
        std::cout << "Filled: " << (Filled ? "Yes\n" : "No\n");
        std::cout << "Opacity: " << Opacity << "\n";
        std::cout << "Area: " << GetArea() << "\n";
        std::cout << "Circumference: " << GetCircumference() << "\n";
    }

private:
    int Radius;
    char Color[256];
    bool Filled;
    double Opacity;
};

int main()
{
    Circle circle;
    circle.SetRadius(5);
    circle.SetColor("Red");
    circle.SetFilled(true);
    circle.SetOpacity(0.75);

    circle.Introduce();

    return 0;
}