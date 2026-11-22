
#include <cstdint>
#include <cstring>
#include <iostream>

class Rectangle
{
public:
    Rectangle()
        : Width(0)
        , Height(0)
        , BorderThickness(0)
        , Color("")
        {
        }

    ~Rectangle()
    {
    }

    void SetWidth(int width)
    {
        Width = width;
    }

    int GetWidth()
    {
        return Width;
    }

    void SetHeight(int height)
    {
        Height = height;
    }

    int GetHeight()
    {
        return Height;
    }

    void SetBorderThickness(int thickness)
    {
        BorderThickness = thickness;
    }

    int GetBorderThickness()
    {
        return BorderThickness;
    }

    void SetColor(const char* color)
    {
        size_t length = std::strlen(color);
        strncpy(Color, color, length);
        Color[length] = '\0';
    }

    char* GetColor()
    {
        return Color;
    }

    int GetArea()
    {
        return Width * Height;
    }

    int GetPerimeter()
    {
        return 2 * (Width + Height);
    }

    void Introduce()
    {
        std::cout << "Color: " << Color << ", Border: " << BorderThickness << "px\n";
        std::cout << "Area: " << GetArea() << ", Perimeter: " << GetPerimeter() << "\n";
    }

private:
    int Width;
    int Height;
    int BorderThickness;
    char Color[256];
};

int main()
{
    Rectangle rectangle;
    rectangle.SetColor("Blue");
    rectangle.SetBorderThickness(2);
    rectangle.SetWidth(20);
    rectangle.SetHeight(10);

    rectangle.Introduce();

    return 0;
}
