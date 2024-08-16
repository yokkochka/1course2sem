//-------------------------------------------------//
//              L4 Task 4.17 (static)              //
//  Develop a program that receives a matrix A of  //
//  size m * n. If the arithmetic mean of the      //
//  elements in matrix A is less than 0, the       //
//  program creates a matrix B. Matrix B is formed //
//  by swapping the smallest element in each row   //
//  of matrix A with its diagonal element.         //
//-------------------------------------------------//

#include <iostream>

using namespace std;

void vvod(float mas[], int n);
void vvod_dv_mas(float mas[][10], int m, int n);
void vivod_res(float res_mas[][10], int m, int n);

int condition(float mas[][10], int m, int n);
void result(float mas[][10], int m, int n, float res_mas[][10]);
void perenos(float mas[][10], int m, int n, float res_mas[][10]);

int main() {
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag == 1) {
        float mas[10][10];

        int m, n;
        cout << "Введите размерность матрицы (m*n) ";
        cin >> m >> n;
        while (m > 10 || m <= 0 || n <= 0 || n > 10) {
            cout << "Введенные значение(я) больше предусмотренных, оно(и) должно(ы) быть меньше/равно 10"
                 << endl;
            cin >> m >> n;
        }

        cout << "Введите массив (n*n) " << endl;
        ;
        vvod_dv_mas(mas, m, n);
        float res_mas[10][10];

        cout << "Исходная матрица:" << endl;
        vivod_res(mas, m, n);

        result(mas, m, n, res_mas);
        if (condition(mas, m, n) == 1) {
            cout << "Конечная матрица:" << endl;
            vivod_res(res_mas, m, n);
        }
        cout << "Хотите повторить программу? (1 - да/ 0 - нет)" << endl;
        cin >> flag;
    }
}
