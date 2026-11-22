
#include <iostream>

char FindLastWord(char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    return str[length - 1];
}

int Q1()
{
    char arr[3][10] = {};
    std::cin >> arr[0];
    std::cin >> arr[1];
    std::cin >> arr[2];

    std::cout << FindLastWord(arr[0]) << FindLastWord(arr[1]) << FindLastWord(arr[2]);
    return 0;
}

int FindCharCount(char str[4][4], char input)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (str[i][j] == input)
                count++;
        }
    }

    return count;
}

int Q2()
{
    char arr[4][4] =
    {
        { 'A', 'B', 'K', 'T' },
        { 'K', 'F', 'C', 'F' },
        { 'B', 'B', 'Q', 'Q' },
        { 'T', 'P', 'Z', 'F' }
    };

    char a;
    char b;
    std::cin >> a;
    std::cin >> b;

    std::cout << FindCharCount(arr, a) + FindCharCount(arr, b);
    return 0;
}

void AddWord(char arr[6], int idx)
{
    int length = 0;
    while (arr[length] != '\0')
    {
        length++;
    }

    for (int i = length - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
        arr[i] = '\0';
    }
    arr[idx] = 'A';

    std::cout << arr << std::endl;
}

int Q3()
{
    char arr[6] = {};
    int input = 0;
    std::cin >> arr;
    std::cin >> input;

    AddWord(arr, input);
    return 0;
}

int Q4()
{
    int A[4] = {};
    int B[4] = {};

    for (int i = 0; i < 4; i++)
    {
        std::cin >> A[i];
    }

    for (int i = 0; i < 4; i++)
    {
        std::cin >> B[i];
    }

    int result[4] = {};

    for (int i = 0; i < 4; i++)
    {
        result[i] = A[i] + B[3 - i];
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}


void RemoveWord(char arr[256], int idx)
{
    int length = 0;
    while (arr[length] != '\0')
    {
        length++;
    }

    for (int i = idx; i < length; i++)
    {
        arr[i] = arr[i + 1];
        arr[i + 1] = '\0';
    }

    std::cout << arr;
}

int Q5()
{
    char arr[256] = {};
    int input = 0;
    std::cin >> arr;
    std::cin >> input;

    RemoveWord(arr, input);
    return 0;
}

bool isExist(char arr[256])
{
    int length = 0;
    while (arr[length] != '\0')
    {
        if (arr[length] == 'M')
        {
            return true;
        }
        length++;
    }

    return false;
}

int Q6()
{
    char A[256] = {};
    char B[256] = {};
    char C[256] = {};

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    bool exist = isExist(A) || isExist(B) || isExist(C);

    if (exist)
        std::cout << "M이 존재합니다";
    else
        std::cout << "M이 존재하지 않습니다";
    return 0;
}

bool Q7IsExist(char arr[4], char target)
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == target)
            return true;
    }

    return false;
}

int Q7()
{
    char arr[4] = { 'M', 'T', 'K', 'C' };
    char input = '0';
    std::cin >> input;

    if (Q7IsExist(arr, input))
    {
        std::cout << "발건\n";
    }
    else
    {
        std::cout << "미발건\n";
    }

    return 0;
}

void Q8IsExist(char arr[2][3], char A, char B)
{
    int findA = 0;
    int findB = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == A)
                findA = 1;

            if (arr[i][j] == B)
                findB = 1;
        }
    }

    if (findA && findB)
    {
        std::cout << "대발견\n";
    }
    else if (findA || findB)
    {
        std::cout << "중발견\n";
    }
    else
    {
        std::cout << "미발견\n";
    }
}

int Q8()
{
    char arr[2][3] =
    {
        { 'G', 'K', 'T' },
        { 'P', 'A', 'C' }
    };

    char A = '0';
    char B = '0';
    std::cin >> A;
    std::cin >> B;

    Q8IsExist(arr, A, B);
    return 0;
}

void PrefixSum(int arr[6], int i, int j)
{
    arr[j] = arr[i] + arr[j];
}

int Q9()
{
    int arr[6] = {};
    for (int i = 0; i < 6; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        PrefixSum(arr, i, i + 1);
    }

    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
    return 0;
}

static void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Wheel
{
public:
    Wheel()
    {
    }

    ~Wheel()
    {
    }

    void SetIndex(int index)
    {
        _index = index;
    }

    void SetSize(int size)
    {
        _size = size;
    }

    void SetRadius(int radius)
    {
        _radius = radius;
    }

    void PrintData()
    {
        std::cout << "wheel[" << _index << "]: size " << _size << "inch radius " << _radius << "cm\n";
    }
private:
    int _index = 0;
    int _size = 0;
    int _radius = 0;
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

    void SetName(const char* name)
    {
        SetCharMember(_name, name);
    }

    void SetSpeed(int speed)
    {
        _speed = speed;
    }

    void SetFuel(int fuel)
    {
        _fuel = fuel;
    }

    void SetWheel(Wheel* wheel, int idx)
    {
        _wheels[idx] = wheel;
        (*_wheels[idx]).SetIndex(idx);
    }

    void PrintData()
    {
        std::cout << _name << "\n";
        std::cout << "speed: " << _speed << "km\n";
        std::cout << "fuel: " << _fuel << "l\n";
        for (int i = 0; i < 4; i++)
        {
            (*_wheels[i]).PrintData();
        }
    }
private:
    char _name[256] = "";
    int _speed = 0;
    int _fuel = 0;
    Wheel* _wheels[4] = {};
};

int Q10()
{
    Wheel a;
    a.SetSize(5);
    a.SetRadius(20);
    Wheel b;
    b.SetSize(5);
    b.SetRadius(20);
    Wheel c;
    c.SetSize(5);
    c.SetRadius(20);
    Wheel d;
    d.SetSize(5);
    d.SetRadius(20);

    Car feraril;
    feraril.SetName("feraril");
    feraril.SetSpeed(200);
    feraril.SetFuel(100);
    feraril.SetWheel(&a, 0);
    feraril.SetWheel(&b, 1);
    feraril.SetWheel(&c, 2);
    feraril.SetWheel(&d, 3);

    feraril.PrintData();

    Wheel e;
    e.SetSize(3);
    e.SetRadius(20);
    Wheel f;
    f.SetSize(3);
    f.SetRadius(20);
    Wheel g;
    g.SetSize(3);
    g.SetRadius(20);
    Wheel h;
    h.SetSize(3);
    h.SetRadius(20);

    Car avante;
    avante.SetName("avante");
    avante.SetSpeed(100);
    avante.SetFuel(10);
    avante.SetWheel(&e, 0);
    avante.SetWheel(&f, 1);
    avante.SetWheel(&g, 2);
    avante.SetWheel(&h, 3);

    avante.PrintData();

    return 0;
}

void PrintNum(int from, int to, int repeat)
{
    for (int st = 0; st < repeat; st++)
    {
        int i = from;
        for (i; i <= to; i++)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}

int RQ1()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    PrintNum(a, b, c);
    return 0;
}

int RQ2()
{
    char arr[6][3] = {};
    char st = 'A';

    for (int i = 2; i >= 0; i--)
    {
        for (int j = 5; j >= 0; j--)
        {
            arr[j][i] = st++;
        }
    }

    int i = 0;
    int j = 0;
    std::cin >> i;
    std::cin >> j;

    std::cout << arr[i][j];
    return 0;
}

void getMin(int arr[2][3], int* x, int* y)
{
    int min = INT_MAX;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                *x = i;
                *y = j;
            }
        }
    }
}

void getMax(int arr[2][3], int* x, int* y)
{
    int max = INT_MIN;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                *x = i;
                *y = j;
            }
        }
    }
}

int RQ3()
{
    int arr[2][3] = {};
    for (int i = 0; i < 3; i++)
    {
        std::cin >> arr[0][i];
    }

    for (int i = 0; i < 3; i++)
    {
        std::cin >> arr[1][i];
    }

    int minX = 0;
    int minY = 0;
    int maxX = 0;
    int maxY = 0;

    getMin(arr, &minX, &minY);
    getMax(arr, &maxX, &maxY);

    std::cout << "(" << maxX << "," << maxY << ")\n";
    std::cout << "(" << minX << "," << minY << ")\n";
    return 0;
}

int getComplexMulti(int arr[6])
{
    for (int i = 2; i < 6; i++)
    {
        arr[i] = arr[i - 1] * arr[i - 2];
    }

    return arr[5];
}

int RQ4()
{
    int arr[6] = {};
    std::cin >> arr[0];
    std::cin >> arr[1];

    std::cout << getComplexMulti(arr) << "\n";

    return 0;
}

void switchChar(char arr[256], char from, char to)
{
    int length = 0;
    while (arr[length] != '\0')
    {
        if (arr[length] == from)
        {
            arr[length] = to;
        }

        length++;
    }
}
int RQ5()
{
    char arr[256] = {};
    std::cin >> arr;

    char a = '0';
    char b = '0';
    std::cin >> a;
    std::cin >> b;

    switchChar(arr, a, b);

    std::cout << arr;
    return 0;
}

int findMinIdx(char arr[10])
{
    int length = 0;
    int idx = 0;
    while (arr[length] != '\0')
    {
        if (arr[length] < arr[idx])
        {
            idx = length;
        }
        length++;
    }

    return idx;
}

int findMaxIdx(char arr[10])
{
    int length = 0;
    int idx = 0;
    while (arr[length] != '\0')
    {
        if (arr[length] > arr[idx])
        {
            idx = length;
        }
        length++;
    }

    return idx;
}

int RQ6()
{
    char arr[10] = {};
    std::cin >> arr;

    int minIdx = findMinIdx(arr);
    int maxIdx = findMaxIdx(arr);

    std::cout << maxIdx << std::endl;
    std::cout << minIdx << std::endl;
}

void fillZero(int arr[7][4], int line)
{
    for (int i = 0; i < 4; i++)
    {
        arr[line][i] = 0;
    }
}

int RQ7()
{
    int arr[7][4] = {};

    int st = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = st++;
        }
    }

    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    fillZero(arr, a);
    fillZero(arr, b);
    fillZero(arr, c);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

bool RQ8IsExist(char arr[2][6], char target)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

int RQ8()
{
    char arr[2][6] =
    {
        { 'A', '7', '9', 'T', 'K', 'Q' },
        { 'M', 'I', 'N', 'C', 'O', 'D' }
    };

    char a = '0';
    char b = '0';
    std::cin >> a;
    std::cin >> b;

    bool aExist = RQ8IsExist(arr, a);
    bool bExist = RQ8IsExist(arr, b);

    std::cout << "A : " << (aExist ? "존재" : "없음") << std::endl;
    std::cout << "B : " << (bExist ? "존재" : "없음") << std::endl;

    return 0;
}

int RQ9()
{
    int a = 0;
    int b = 0;
    char input = '0';
    std::cin >> a;
    std::cin >> b;
    std::cin >> input;

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                std::cout << input;
            }
            std::cout << "\n";
        }
    }


    return 0;
}

class Weapon
{
public:
    Weapon()
    {
    }

    ~Weapon()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(_name, name);
    }

    void PrintInfo()
    {
        std::cout << "weapon: " << _name << "\n";
    }
private:
    char _name[256] = "";
};

struct Class
{
    char _name[256] = "";
    int _classHpBonus = 0;

    Class(const char* name, int hpBonus)
    {
        SetCharMember(_name, name);
        _classHpBonus = hpBonus;
    }
};

class Player
{
public:
    Player()
    {
    }
    ~Player()
    {
    }
    void SetClass(Class* inputClass)
    {
        _class = inputClass;
    }

    void SetHp(int hp)
    {
        _hp = hp;
    }

    int GetHp()
    {
        return _hp + (*_class)._classHpBonus;
    }

    void EquipWeapon(Weapon* weapon)
    {
        _myWeapon = weapon;
    }

    Weapon* GetMyWeapon()
    {
        return _myWeapon;
    }

    void PrintInfo()
    {
        std::cout << (*_class)._name << "\n";
        std::cout << "hp : " << GetHp() << "\n";
        (*GetMyWeapon()).PrintInfo();
    }
private:
    Class* _class;
    int _hp = 0;
    Weapon* _myWeapon;
};

int main()
{
    Weapon sword;
    sword.SetName("sword");
    Class warriorClass("warrior", 100);
    Player p1;
    p1.SetClass(&warriorClass);
    p1.SetHp(100);
    p1.EquipWeapon(&sword);

    Weapon bow;
    bow.SetName("bow");
    Class archerClass("archer", 0);
    Player p2;
    p2.SetClass(&archerClass);
    p2.SetHp(100);
    p2.EquipWeapon(&bow);

    p1.PrintInfo();
    p2.PrintInfo();

    return 0;
}