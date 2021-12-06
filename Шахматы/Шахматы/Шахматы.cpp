#include <iostream>
#include <fstream>
#include <Windows.h>
#include<conio.h>

using namespace std;

class Field
{ 
public:
    int x, y;
    void input()
    {
        cout << "Введите координату x: ";
        cin >> x;
        
            while ((x>8) || (x<1))
            {
                cout << "Введите в диапазоне [1; 8]" << endl;
                cout << "Введите координату x: ";
                cin >> x;
            }
      
        
        cout << "Введите координату y: ";
        cin >> y;     
        while ((y > 8) || (y < 1))
            {
                cout << "Введите в диапазоне [1; 8]" << endl;
                cout << "Введите координату y: ";
                cin >> y;
            }
    }
};

bool white(Field A, Field B)
{
    if ((((A.x % 2 == 1) & (A.y % 2 == 0)) || ((A.x % 2 == 0) & (A.y % 2 == 1))) &
        (((B.x % 2 == 1) & (B.y % 2 == 0)) || ((B.x % 2 == 0) & (B.y % 2 == 1)))) /// поля белого цвета
        return true;
}

bool black(Field A, Field B)
{
    if ((((A.x % 2 == 0) & (A.y % 2 == 0)) || ((A.x % 2 == 1) & (A.y % 2 == 1))) &
        (((B.x % 2 == 0) & (B.y % 2 == 0)) || ((B.x % 2 == 1) & (B.y % 2 == 1)))) /// поля черного цвета
        return true;
}

void queen(Field A, Field B) // Ферзь
{
    if (((abs(A.x - B.x) <= 1) & (abs(A.y - B.y) <= 1)) || (A.x == B.x || A.y == B.y))
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void rook(Field A, Field B) // Ладья
{
    if (A.x == B.x || A.y == B.y)
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void bishop(Field A, Field B) // Слон
{
    if (abs(A.x - B.x) == abs(A.y - B.y))
        cout << "б)Угрожает" << endl;
    else
        cout << "б)Не угрожает" << endl;
}

void knight(Field A, Field B) // Конь
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
    
    bool check_queen(Field A, Field B) ///Ферзь
    {
        int d;
        int g;
        d = B.x;
        g = B.y;
        if (((abs(A.x - d) <= 1) & (abs(A.y - g) <= 1)) || (A.x == d || A.y == g))
            return true;
    }
    bool check_bishop(Field A, Field B) // Слон
    {
        int d;
        int g;
        d = B.x;
        g = B.y;
        if (abs(A.x - d) == abs(A.y - g))
            return true;
    }

    bool check_rook(Field A, Field B) // Ладья
    {
        int d;
        int g;
        d = B.x;
        g = B.y;
        if (A.x == d || A.y == g)
            return true;
    }

    int main()
    {
        ofstream file;
        file.open("C:\\Users\\Татьяна\\Desktop\\Учёба\\ПП\\Laba8-9\\Шахматы\\log.txt",ios::app);//Создаёт файл.Добавляет новую запись в файл.
        
        SYSTEMTIME st;//Обращение к структуре времени в С++.
        GetLocalTime(&st);//Функция.Обращение к адресу переменной структуры(st).
        if (file.is_open() == true)//Если адрес правильный - записываем. 
        {
            file << st.wYear << "/" << st.wMonth << "/" << st.wDay << endl;
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Начало программы." << endl;
        }
        else//Если где то ошибка выводится сообщение об ошибки в консоль.
        {
            file << "Файл не записался." << endl;
        }
        
        chess_board();
        setlocale(LC_ALL, "Rus");
        cout << "Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит восьми:" << endl;
        cout << "\nПоле 1:" << endl;
        Field A;
        A.input();
        if ((A.x < 9) & (A.x > 0) & (A.y < 9) & (A.y > 0))
        {
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Ввод поля 1 выполнен успешно:" << "(" << A.x << ", " << A.y << ")" << endl;
        }
        else
        {
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Ввод поля 1 выполнен c ошибкой" << endl;
        }

        cout << "\nПоле 2:" << endl;
        Field B;
        B.input();
        if ((B.x < 9) & (B.x > 0) & (B.y < 9) & (B.y > 0))
        {
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Ввод поля 2 выполнен успешно:" << "(" << B.x << ", " << B.y << ")" << endl;
        }
        else
        {
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Ввод поля 2 выполнен c ошибкой" << endl;
        }

        if ((white(A, B) == true) || (black(A, B) == true))
            cout << "\na)Поля одного цвета" << endl;
        else cout << "\na)Поля разных цветов" << endl;
        GetLocalTime(&st);
        file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Проверка полей выполнена успешно." << endl;

        cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон, 3-конь." << endl;
        int s;
        cin >> s;
        if ((s == 0) || (s == 1) || (s == 2) || (s == 3))
        {           
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Выбор фигуры выполнен успешно." << endl;            
        }
        else
        {
            while ((s != 0) & (s != 1) & (s != 2) & (s != 3))
            {
                cout << "Неверный ввод" << endl;
                cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон, 3-конь." << endl;
                cin >> s;
            }
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Обработка ошибки: неправильный ввод фигуры" << endl;
        }
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
        GetLocalTime(&st);
        file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Проверка " << endl;

        cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон." << endl;
        int t;
        cin >> t;
        if ((t == 0) || (t == 1) || (t == 2))
        {
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Выбор фигуры выполнен успешно." << endl;            
        }
        else
        {
            while ((t != 0) & (t != 1) & (t != 2))
            {
                cout << "Неверный ввод" << endl;
                cout << "\nВыберите фигуру на поле " << "(" << A.x << ", " << A.y << ")" << ": 0-ферзь, 1-ладья, 2-слон." << endl;
                cin >> t;
            }
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Обработка ошибки: неправильный ввод фигуры" << endl;
        }
        
        switch (t)
        {
        case 0:
            if (check_queen(A, B) == true)
                cout << "С поля 1 на поле 2 можно попасть одним ходом." << endl;
            else           
                 cout << "За два хода можно попасть через поле " << "(" << B.x << ", " << A.y << ")" << endl;        
            break;
        case 1: if (check_rook(A, B) == true)
               cout << "С поля 1 на поле 2 можно попасть одним ходом." << endl;
             else
               cout << "За два хода можно попасть через поле " << "(" << B.x << ", " << A.y << ")" << endl;
            break;
                //////////////////////// Со слоном не получается :(
        case 2: 
            if (check_bishop(A, B) == true)
                cout << "С поля 1 на поле 2 можно попасть одним ходом." << endl;
            else if (((A.x < B.x) & (A.y < B.y)) & ((white(A, B) == true) || (black(A, B) == true)))
                cout << "За два хода можно попасть через поле " << "(" << B.x + 1 << ", " << B.y - 1 << ")" << endl;
            else if (((A.x > B.x) & (A.y > B.y)) & ((white(A, B) == true) || (black(A, B) == true)))
                cout << "За два хода можно попасть через поле " << "(" << (B.x + B.y)/2 << ", " << (B.x + B.y) / 2 << ")" << endl;
            else if (((A.x < B.x) & (A.y > B.y)) & (A.y-B.y < 5) & ((white(A, B) == true) || (black(A, B) == true)))
                cout << "За два хода можно попасть через поле " << "(" << A.x - 1 << ", " << A.y - 1 << ")" << endl;
            else cout << "За два хода невозможно дойти до поля 2" << endl;
            break;
            GetLocalTime(&st);
            file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Вычисления..." << endl;
        }

        GetLocalTime(&st);//Функция .
        file << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " Конец программы." << endl;
        file.close();//Закрываем файл.
        return 0;
    }

