// Шахматы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Field
{ 
public:
    int x, y;
    void input()
    {
        cout << "Введите координату x: ";
        cin >> x;
        cout << "Введите координату y: ";
        cin >> y;
    }
};

//////// для пункта а)

bool white(Field A, Field B)
{
    if (((A.x % 2 == 1 & A.y % 2 == 0) || (A.x % 2 == 0 & A.y % 2 == 1)) &
        ((B.x % 2 == 1 & B.y % 2 == 0) || (B.x % 2 == 0 & B.y % 2 == 1))) /// поля белого цвета
        return true;
}

bool black(Field A, Field B)
{
    if (((A.x % 2 == 0 & A.y % 2 == 0) || (A.x % 2 == 1 & A.y % 2 == 1)) &
        ((B.x % 2 == 0 & B.y % 2 == 0) || (B.x % 2 == 1 & B.y % 2 == 1))) /// поля черного цвета
        return true;
}

/////// пункт б) описание фигур

void queen(Field A, Field B)
{
    if ((abs(A.x - B.x) <= 1 & abs(A.y - B.y) <= 1) || (A.x == B.x || A.y == B.y))
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void rook(Field A, Field B)
{
    if (A.x == B.x || A.y == B.y)
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void bishop(Field A, Field B)
{
    if (abs(A.x - B.x) == abs(A.y - B.y))
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void knight(Field A, Field B)
{
    if ((A.x - 1 == B.x || A.x + 1 == B.x) & (A.y - 2 == B.y || A.y + 2 == B.y))
        cout << "б)Угрожает" << endl;
    else if ((A.x - 2 == B.x || A.x + 2 == B.x) & (A.y - 1 == B.y || A.y + 1 == B.y))
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}


    void chess_board()
    {
        cout << "  1 2 3 4 5 6 7 8   x\n";
        for (int row = 0; row < 8; row++)
        {
            cout << 8 - row;
            for (int col = 0; col < 8; col++)
            {
                if ((col + row) % 2 == 0) cout << (char)219 << (char)219;
                else cout << "  ";
            }
            cout << "\n";
        }
        cout << "\n" << "y\n" << endl;
    }
    
int main()
{
    chess_board();
    setlocale(LC_ALL, "Rus");
    cout << "Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит восьми:" << endl;
    cout << "\nПоле 1:" << endl;
    Field A;
    A.input();
    cout << "\nПоле 2:" << endl;
    Field B;
    B.input();    

    if ((white(A, B) == true) || (black(A, B) == true))
        cout << "\na)Поля одного цвета" << endl;
    else cout << "\na)Поля разных цветов" << endl;

    cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон, 3-конь." << endl;
    int s;
    cin >> s;
    cout << endl;
    switch (s)
    {
    case 0: queen(A, B);
        break;
    case 1: rook(A, B);
        break;
    case 2: bishop(A, B);
        break;
    case 3: knight(A, B);
        break;
    }

    cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон." << endl;
    int t;
    cin >> t;
    switch (t)
    {
    case 0: queen(A, B);
        break;
    case 1: rook(A, B);
        break;
    case 2: bishop(A, B);
        break;

    return 0;
}


