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

void enter(int* mas, int n);
void output(int* mas2, int n);
int solution(int* mas, int n, int* mas2);
int proverka(int* mas, int n);


int main() {
    setlocale(LC_ALL, "ru");
    int flag = 0;    // Флаг для повтора программы 
    while (flag != 1) {
        
        cout << "Сколько элементов вы хотите в массиве(меньше 100)" << endl;
        int n; 
        cin >> n;
        while (n > 100)
        {
            cout << "Ваша размерность массива больше предусмотренной, введите повторно" << endl;
            cin >> n;
        }
        
        int mas[100];    // Исходный статический массив

        enter(mas, n);    // Ввод массива
        output(mas, n);
        int mas2[100];    // Конечный массв
        if (solution(mas, n, mas2) == 1)
        {
            output(mas2, n-1);    //Вывод массива
        }
        else cout << "В массиве нет случая, когда положительное число следует за отрицательным" << endl;
       
        cout << "Повторить программу? (Yes - 0 / No - 1)\n";
        cin >> flag;
    }
}


// Ввод
void enter(int* mas, int n)
{
    for (int i = 0; i < n; i++) { 
        cin >> mas[i];
    }
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
int solution(int* mas, int n, int* mas2)
{
    
    if (proverka(mas, n) == 1)
    {
        int index_i = 0;
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
        return 1;
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