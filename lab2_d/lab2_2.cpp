//-------------------------------------------------//
//              L2 Task 2.03 (dynamic)             //
//  Draw up a function that receives an array of   //
//  real numbers of size N. If there is at least   //
//  one positive number in this sequence that      //
//  follows a negative number, the function should //
//  create a new array by copying all elements     //
//  from the original array except for its minimum //
//  element.                                       //
//-------------------------------------------------//

#include <cmath>
#include <iostream>
using namespace std;

int* enter(int n);
void output(int* mas2, int n);
int* solution(int* mas, int n);
int proverka(int* mas, int n);

int main() {
    setlocale(LC_ALL, "ru");
    int flag = 0;
    while (flag != 1) {
        cout << "Сколько элементов вы хотите в массиве" << endl;
        int n;
        cin >> n;
        while (n > 100) {
            cout << "Ваша размерность массива больше предусмотренной, введите повторно" << endl;
            cin >> n;
        }
        int* mas;
        mas = enter(n);
        cout << "Вывод исходного массива" << endl;
        output(mas, n);
        int* mas2;
        mas2 = solution(mas, n);
        if (mas2 != 0) {
            cout << endl << "Вывод конечного массива:" << endl;
            output(mas2, n - 1);
            delete[] mas2;
        } else
            cout << "В массиве нет случая, когда положительное число следует за отрицательным" << endl;
        delete[] mas;

        cout << endl << "Повторить программу? (Yes - 0 / No - 1)\n";
        cin >> flag;
    }
}

int* enter(int n) {
    cout << "Введите элементы массива" << endl;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    return mas;
}

void output(int* mas2, int n) {
    for (int i = 0; i < n; i++) {
        cout << mas2[i] << " ";
    }
}

int* solution(int* mas, int n) {
    if (proverka(mas, n) == 1) {
        int* mas2 = new int[n - 1];
        int index_i;
        float min_ch = mas[0];
        for (int i = 0; i < n; i++) {
            if (mas[i] < min_ch) {
                min_ch = mas[i];
                index_i = i;
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i != index_i) {
                mas2[j] = mas[i];
                j++;
            }
        }
        return mas2;
    }
    return 0;
}

int proverka(int* mas, int n) {
    int flag2 = 0;

    for (int i = 0; i < (n - 1); i++) {
        if (mas[i] < 0) {
            if (mas[i + 1] > 0) {
                flag2 = 1;
            }
        }
    }
    return flag2;
}