/*

Задача 4.17
Составить программу, которая получает матрицу А размером m *n.
Если среднеарифметическое элементов матрицы А меньше 0, то программа
формирует матрицу В, получаемую из исходной А перестановкой в каждой
строке наименьшего элемента с ее диагональным.

 */

#include <iostream>

using namespace std;

void vvod(float mas[], int n);
void vvod_dv_mas(float mas[][10], int m, int n);
void vivod_res(float res_mas[][10], int m, int n);

int condition(float mas[][10], int m, int n);
void result(float mas[][10], int m, int n, float res_mas[][10]);
void perenos(float mas[][10], int m, int n, float res_mas[][10]);


int main() 
{
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag == 1) {


        float mas[10][10];
        

        int m, n;
        cout << "Введите размерность матрицы (m*n) ";
        cin >> m >> n;
        while (m > 10 || m<=0 || n<=0 || n > 10)
        {
            cout << "Введенные значение(я) больше предусмотренных, оно(и) должно(ы) быть меньше/равно 10" << endl;
            cin >> m >> n;
        }

        cout << "Введите массив (n*n) " << endl;;
        vvod_dv_mas(mas, m, n);
        float res_mas[10][10];

        cout << "Исходная матрица:" << endl;
        vivod_res(mas, m, n);

        
        result(mas, m, n, res_mas);
        if (condition(mas, m, n) == 1)
        {
            cout << "Конечная матрица:" << endl;
            vivod_res(res_mas, m, n);
        }
        cout << "Хотите повторить программу? (1 - да/ 0 - нет)" << endl;
        cin >> flag;
    }
}
