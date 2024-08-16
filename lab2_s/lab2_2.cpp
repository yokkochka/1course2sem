//-------------------------------------------------//
//              L2 Task 2.03 (static)              //
//  Develop a function that takes an array of real //
//  numbers of size N. If the sequence contains at //
//  least one positive number that follows a       //
//  negative number, create a new array that       //
//  includes all elements from the original array, //
//  excluding the minimum element.                 //
//-------------------------------------------------//

#include <cmath>
#include <iostream>
using namespace std;

void enter(int* mas, int n);
void output(int* mas2, int n);
int solution(int* mas, int n, int* mas2);
int proverka(int* mas, int n);

int main() {
    setlocale(LC_ALL, "ru");
    int flag = 0;
    while (flag != 1) {
        cout << "Сколько элементов вы хотите в массиве(меньше 100)" << endl;
        int n;
        cin >> n;
        while (n > 100) {
            cout << "Ваша размерность массива больше предусмотренной, введите повторно" << endl;
            cin >> n;
        }

        int mas[100];

        enter(mas, n);
        output(mas, n);
        int mas2[100];
        if (solution(mas, n, mas2) == 1) {
            output(mas2, n - 1);
        } else
            cout << "В массиве нет случая, когда положительное число следует за отрицательным" << endl;

        cout << "Повторить программу? (Yes - 0 / No - 1)\n";
        cin >> flag;
    }
}

void enter(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
}

void output(int* mas2, int n) {
    for (int i = 0; i < n; i++) {
        cout << mas2[i] << " ";
    }
}

int solution(int* mas, int n, int* mas2) {
    if (proverka(mas, n) == 1) {
        int index_i = 0;
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
        return 1;
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