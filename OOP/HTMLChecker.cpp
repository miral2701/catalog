#include <iostream>

#include <fstream>

using namespace std;

int main()
{
    ifstream is("index.html", ios::in);
    if (!is.is_open())
    {
        cout << "Open file error\n";
    }

    char str[200];
    bool error = 1;
   
    do
    {
        is.getline(str, 200);
        string a = str;
        if (a.find('<') != 18446744073709551615 && a.find('>') == 18446744073709551615) {
            cout << "Error";
            error = 0;
        }
        else if (a.find('>') != 18446744073709551615 && a.find('<') == 18446744073709551615) {
            cout << "Error";
            error = 0;
        }

    } while (!is.eof());
    if (error) {
        is.seekg(0, ios::beg);
        while (!is.eof()) {
            is.getline(str, 200);
            cout << str<<endl;
        }
    }

    is.close();
}