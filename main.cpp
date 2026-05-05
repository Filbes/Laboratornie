#include <iostream>
#include <fstream>
#include <Windows.h>

#include "BitString.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    setlocale(LC_ALL, "Russian");

    BitString bs;

    string a;
    string b;
    string result;

    int choice;

    cout << "Выберите режим работы:" << endl;

    cout << "1 - читать строки из файлов" << endl;

    cout << "2 - ввод строк с клавиатуры" << endl;

    cout << "3 - ввести строки и записать их в файлы" << endl;

    cout << "Ваш выбор: ";

    cin >> choice;

    if (choice == 1)
    {
        ifstream f1("input1.txt");
        ifstream f2("input2.txt");

        if (!f1 || !f2)
        {
            cout << "Ошибка: файл не найден" << endl;
            return 0;
        }

        getline(f1, a);
        getline(f2, b);

        cout << "Данные прочитаны из файлов" << endl;

        f1.close();
        f2.close();
    }

    else if (choice == 2)
    {
        cout << "Введите первую битовую строку: ";
        cin >> a;

        cout << "Введите вторую битовую строку: ";
        cin >> b;
    }

    else if (choice == 3)
    {
        cout << "Введите строку для input1.txt: ";
        cin >> a;

        cout << "Введите строку для input2.txt: ";
        cin >> b;

        ofstream f1("input1.txt");
        ofstream f2("input2.txt");

        f1 << a;
        f2 << b;

        cout << "Файлы успешно заполнены" << endl;

        f1.close();
        f2.close();
    }

    else
    {
        cout << "Неверный выбор" << endl;
        return 0;
    }

    if (!bs.proverka(a) || !bs.proverka(b))
    {
        cout << "Ошибка: строки должны содержать только 0 и 1" << endl;
        return 0;
    }

    a = bs.k8bit(a);
    b = bs.k8bit(b);

    if (a == "" || b == "")
    {
        cout << "Ошибка: длина строки больше 8 бит" << endl;
        return 0;
    }

    cout << "Строка 1: " << a << endl;
    cout << "Строка 2: " << b << endl;

    result = bs.conjunction(a, b);

    cout << "Результат AND: " << result << endl;

    ofstream fout("output.txt");

    fout << "Результат AND: " << result;

    fout.close();

    cout << "Результат записан в файл output.txt" << endl;

    return 0;
}