#include <iostream>

using namespace std;

int main() {
    char a[9];
    char b[9];

    int lenA = 0;
    int lenB = 0;

    cout << "Введите первую битовую строку: ";
    cin >> a;

    cout << "Введите вторую битовую строку: ";
    cin >> b;

    while (a[lenA] != '\0') {
        lenA++;
    }

    while (b[lenB] != '\0') {
        lenB++;
    }

    if (lenA > 8 || lenB > 8) {
        cout << "Ошибка: длина строки больше 8 бит" << endl;
        return 0;
    }

    for (int i = 0; i < lenA; i++) {
        if (a[i] != '0' && a[i] != '1') {
            cout << "Ошибка: первая строка некорректна" << endl;
            return 0;
        }
    }

    for (int i = 0; i < lenB; i++) {
        if (b[i] != '0' && b[i] != '1') {
            cout << "Ошибка: вторая строка некорректна" << endl;
            return 0;
        }
    }

    for (int i = 7; i >= 0; i--) {
        if (lenA > 0) {
            a[i] = a[lenA - 1];
            lenA--;
        }
        else {
            a[i] = '0';
        }
    }
    a[8] = '\0';

    for (int i = 7; i >= 0; i--) {
        if (lenB > 0) {
            b[i] = b[lenB - 1];
            lenB--;
        }
        else {
            b[i] = '0';
        }
    }
    b[8] = '\0';

    for (int i = 0; i < 8; i++) {
        if (a[i] == '1' && b[i] == '1')
            a[i] = '1';
        else
            a[i] = '0';
    }

    cout << "Результат AND: " << a << endl;

    return 0;
}