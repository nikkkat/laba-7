#include <iostream>
#include <string>
using namespace std;

void convert(string str, int i, bool check, bool neww, bool print) 
{
    if (check) 
    {
        if (str[i + 1] == '1') return convert(str, i, 0, 1, 0);
        if (i == 0) return convert(str, i, 0, 0, 1);
        else return convert(str, --i, 1, 0, 0);
    }
    if (neww)
    {
        if (i == 0) return convert(str, ++i, 0, 0, 1);
        else {
            str[i] == '1' ? str[i] = '0' : str[i] = '1';
            return convert(str, --i, 0, 1, 0);
        }
    }
    if (print)
    {
        if (str[i] == '\0') { cout << str; return; }
        else {
            str[i] == '1' ? str[i] = '0' : str[i] = '1';
            return convert(str, ++i, 0, 0, 1);
        }
    }
}

int main() {
    string str; 
    int size; 
    cout << "enter string: ";
    getline(cin,str); 
    size = str.length();

    cout << "result: ";
    if (str[0] == '0') { cout << str; return 0; }
    convert(str, size - 2, 1, 0, 0);

    return (0);
}