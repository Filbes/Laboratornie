#include "BitString.h"
#include <cstring>

using namespace std;

BitString::BitString()
{
    data = new char[9];
    strcpy_s(data, 9, "");
}

BitString::BitString(string s)
{
    data = new char[9];
    strcpy_s(data, 9, s.c_str());
}

BitString::BitString(const BitString& obj)
{
    data = new char[9];
    strcpy_s(data, 9, obj.data);
}

BitString::~BitString()
{
    delete[] data;
}

bool BitString::proverka(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
            return false;
    }

    return true;
}

string BitString::k8bit(string s)
{
    if (s.length() > 8)
        return "";

    while (s.length() < 8)
    {
        s = "0" + s;
    }

    return s;
}

string BitString::conjunction(string a, string b)
{
    string result = "";

    for (int i = 0; i < 8; i++)
    {
        if (a[i] == '1' && b[i] == '1')
            result += '1';
        else
            result += '0';
    }

    return result;
}

void BitString::setData(string s)
{
    strcpy_s(data, 9, s.c_str());
}

string BitString::getData()
{
    return data;
}