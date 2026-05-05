#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool proverka(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1')
            return false;
    }
    return true;
}

string privestiKVosmibitam(string s) {
    if (s.length() > 8)
        return "";

    while (s.length() < 8) {
        s = "0" + s;
    }
    return s;
}

string kon(const string& a, const string& b) {
    string result = "";

    for (int i = 0; i < 8; i++) {
        if (a[i] == '1' && b[i] == '1')
            result += '1';
        else
            result += '0';
    }

    return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
    string a, b;

    ifstream fin("input.txt");

    if (fin.is_open()) {
        fin >> a >> b;
        fin.close();
        cout << "Данные прочитаны из файла\n";
    }
    else {
        cout << "Файл не найден. Введите данные:\n";
        cout << "Введите первую строку: ";
        cin >> a;
        cout << "Введите вторую строку: ";
        cin >> b;
    }

    if (!proverka(a) || !proverka(b)) {
        cout << "Ошибка: строки должны содержать только 0 и 1\n";
        return 0;
    }

    a = privestiKVosmibitam(a);
    b = privestiKVosmibitam(b);

    if (a == "" || b == "") {
        cout << "Ошибка: длина строки больше 8 бит\n";
        return 0;
    }

    cout << "Строка 1: " << a << endl;
    cout << "Строка 2: " << b << endl;

    string result = kon(a, b);

    cout << "Результат AND: " << result << endl;

    ofstream fout("output.txt");
    if (fout.is_open()) {
        fout << "Результат AND: " << result;
        fout.close();
    }

    return 0;
}