//--------------------------------------------------//
//                 Task 3.21                        //
//  Functions for processing strings with numeric   //
//  substrings. The program includes the following  //
//  functionalities:                                //
//   - Checking if a character is a digit.          //
//   - Finding the first numeric substring in a     //
//     string and returning its address and length. //
//   - Removing the first `n` characters from a     //
//     string.                                      //
//   - Inserting a substring at the beginning of    //
//     another string.                              //
//   - Replacing all numeric substrings in a string //
//     with a given substring and counting the      //
//     number of replacements.                      //
//--------------------------------------------------//

#include <iostream>
using namespace std;

int isNumber(char symb);
char* poiskNumberPstr(char* str, int& len);
void delNsymbl(char* str, int n);
void vstavkaPstr(char* str, char* pstr);
int dlina(char* str);
char* zamenaNumber(char* str, char* pstr, int& kol);

int main() {
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag) {
        char* str = new char[100];
        char* pstr = new char[20];

        cout << "input str: " << endl;
        cin >> str;
        cout << "input pstr: " << endl;
        cin >> pstr;

        cout << "\nВведенная строка 1: " << str << endl;
        cout << "\nВведенная строка 2: " << pstr << endl;
        int kol = 0;

        str = zamenaNumber(str, pstr, kol);
        if (kol == 0) {
            cout << " \nВ строке str нет числовых подстрок, замены нет " << endl;
        } else
            cout << " \nРезультат замен: " << str << endl << "Количество замен: " << kol << endl;
        ;

        delete[] str;
        delete[] pstr;

        cout << " \nrepeat? 1/0";
        cin >> flag;
    }
}
