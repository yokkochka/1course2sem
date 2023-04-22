/*Задача 3.21
Функция int isNumber(char symb) получает символ и определяет, является ли он цифровым символом.
Функция char* poiskNumberPstr(char* str, int& len) получает строку и находит в ней первую цифровую подстроку 
    и возвращает ее адрес через возвращаемое значение и через параметр по ссылке ее длину. Если такая подстрока 
    не найдена, то функция возвращает 0.
Функция void delNsymbl(char* str, int n) получает строку,  число  n и удаляет из строки первые n символов.
Функция void vstavkaPstr(char* str, char* pstr) получает строки str  и pstr и вставляет строку pstr в начало строки str.
Функция char* zamenaNumber(char* str, char* pstr , int& kol) получает строки str и pstr, ищет в строке str все цифровые 
    подстроки и заменяет каждую из них на строку pstr.  Функция возвращает через возвращаемое значение адрес строки str, 
    если произошла хотя одна замена, в противном случае функция возвращает адресный 0. Функция через параметр по ссылке 
    возвращает количество замен в строке. Используйте при разработке алгоритма  функции   функции  poiskNumberPstr, 
    delNsymbl и vstavkaPstr.

Программа вводит строки str и pstr, для каждой str производит замену цифровых подстрок  на подстроку, равную строке pstr
    и выводит результат, если строка подверглась изменению. Программа подсчитывает количество строк, подвергшихся изменению.
*/


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
        if (kol == 0)
        {
            cout << " \nВ строке str нет числовых подстрок, замены нет " << endl;
        }
        else cout << " \nРезультат замен: " << str << endl << "Количество замен: " << kol << endl;;

        delete[] str;
        delete[] pstr;

        cout << " \nrepeat? 1/0";
        cin >> flag;
    }
}

