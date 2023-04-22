/*

Задача 4.17
Составить программу, которая получает матрицу А размером m *n.
Если среднеарифметическое элементов матрицы А меньше 0, то программа
формирует матрицу В, получаемую из исходной А перестановкой в каждой
строке наименьшего элемента с ее диагональным.

 */

#include <iostream>

using namespace std;

int **vvod(int m, int n);
void vivod_res(int m, int n, int **res_mas);

int condition(float mas[][10], int m, int n);
int **result(int m, int n, int** mas);
void perenos(float mas[][10], int m, int n, float res_mas[][10]);


int main()
{
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag == 1) {
        int m, n;
        cout << "Введите размерность массива (m*n) ";
        cin >> m >> n;
        while (m > 10 or n > 10)
        {
            cout << "Введенные значение(я) больше предусмотренных, оно(и) должно(ы) быть меньше/равно 10" << endl;
            cin >> m >> n;
        }

        cout << "Введите исходную матрицу" << endl;
        int** mas;
        mas = vvod(m, n);

        cout << "Исходная матрица:" << endl;
        vivod_res(m, n, mas);
        int** res_mas;
        res_mas = result(m, n, mas);
        if (res_mas != 0)
        {
            vivod_res(m, n, res_mas);
            delete[] res_mas;
        }
        delete[] mas;
        cout << "Хотите повторить программу? (1 - да/ 0 - нет)" << endl;
        cin >> flag;
    }
}
