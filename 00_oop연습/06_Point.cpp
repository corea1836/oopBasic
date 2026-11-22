
#include <iostream>

class Point
{
public:
    Point()
        : X(0)
    , Y(0)
    , Z(0)
    , Tag('0')
    {
    }

    ~Point()
    {
    }

    void SetTag(const char tag)
    {
        Tag = tag;
    }

    char GetTag()
    {
        return Tag;
    }

    void SetCoordinates(int x, int y, int z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    int GetX()
    {
        return X;
    }

    int GetY()
    {
        return Y;
    }

    int GetZ()
    {
        return Z;
    }

    void Print()
    {
        std::cout << "Point Tag: " << Tag << " | Coordinates: (" << X << ", " << Y << ", " << Z << ")\n";
    }
private:
    int X;
    int Y;
    int Z;
    char Tag;
};

int main()
{
    Point point;
    point.SetTag('A');
    point.SetCoordinates(3, 4, 7);

    point.Print();
    return 0;
}