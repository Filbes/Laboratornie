#include <string>

using namespace std;

class BitString
{
private:
    char* data;

public:
    BitString();
    BitString(string s);
    BitString(const BitString& obj);
    ~BitString();

    bool proverka(string s);

    string k8bit(string s);

    string conjunction(string a, string b);

    void setData(string s);

    string getData();
};