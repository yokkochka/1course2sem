/*
Задача 2.03
Составить функцию, которая получив массив действительных чисел размером N.
Если в данной последовательности чисел есть хотя бы одно положительное
число, которое следует после отрицательного числа, то создает новый массив,
записав в него все элементы исходного массива исключая его минимальный
элемент.
*/


#include <iostream>
#include <cmath>
using namespace std;

int *enter(int n);
void output(int* mas2, int n);
int *solution(int* mas, int n);
int proverka(int* mas, int n);



int main() {
    setlocale(LC_ALL, "ru");
    int flag = 0;   // Флаг для повтора программы 
    while (flag != 1) {
        
        cout << "Сколько элементов вы хотите в массиве" << endl;
        int n;
        cin >> n;
        while (n > 100)
        {
            cout << "Ваша размерность массива больше предусмотренной, введите повторно" << endl;
            cin >> n;
        }
        int* mas;
        mas = enter(n);
        cout << "Вывод исходного массива" << endl;
        output(mas, n);
        int* mas2;    //Конечный массив
        mas2 = solution(mas, n);   // Формирование конечного массива
        if (mas2 != 0)
        {
            cout <<endl<<"Вывод конечного массива:" << endl;
            output(mas2, n-1);    // Вывод массиа
            delete[] mas2;
        }
        else cout << "В массиве нет случая, когда положительное число следует за отрицательным" << endl;
        delete[] mas;
        
        cout << endl << "Повторить программу? (Yes - 0 / No - 1)\n";
        cin >> flag;
    }
}


// Ввод
int *enter(int n)
{
    cout << "Введите элементы массива" << endl;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    return mas;
}


// Вывод
void output(int* mas2, int n)
{
    for (int i = 0; i < n; i++) {
        cout << mas2[i] << " ";
    }
}

/* Функция определяет выполняется ли условие, если да, находит минимальный эелемент, его индекс.
   Формирует конечный массив в соответствии с условием. На вход получает исходный и конечный массивы, 
   количство элементов в первом массиве и флаг, отслеживающий выполнение условия. Формирует конечный масвив
 */

int *solution(int* mas, int n)
{

    if (proverka(mas, n) == 1)
    {
        int* mas2 = new int[n - 1];
        int index_i;
        float min_ch = mas[0];    // Переменная для минимального числа в массиве
        for (int i = 0; i < n; i++)
        {
            if (mas[i] < min_ch)
            {
                min_ch = mas[i];
                index_i = i;
                
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) 
        {
            if (i != index_i)
            { 
                mas2[j] = mas[i]; 
                j++; 
            }
        }
        return mas2;
    }
    return 0;
}

int proverka(int* mas, int n)
{
    int flag2 = 0;

    for (int i = 0; i < (n - 1); i++) {

        if (mas[i] < 0)
        {
            if (mas[i + 1] > 0)
            {
                flag2 = 1;
            }
        }
    }
    return flag2;
}