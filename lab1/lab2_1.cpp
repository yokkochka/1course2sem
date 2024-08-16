//-------------------------------------------------//
//                 L1 Task 1.18                    //
//  Draw up a program that defines whether an      //
//  integer is a "perfect" number. A "perfect"     //
//  number is a natural number equal to the sum    //
//  of all its divisors (excluding the number      //
//  itself). Example of a "perfect" number:        //
//  28 = 1 + 2 + 4 + 7 + 14. In the main()         //
//  function, input two numbers n and N, where n   //
//  is less than N. The program should output all  //
//  perfect numbers in the interval from n to N    //
//  and count the number of such numbers. The      //
//  main() function should also check that n is    //
//  less than N when the input is given.           //
//-------------------------------------------------//

#include <iostream>
using namespace std;

void func(int i, int& res, int& cnt);

int main() {
    int flag = 0;
    setlocale(LC_ALL, "rus");
    while (flag != 1) {
        cout << "Введите промежуток от n до N" << endl;
        int n, N;
        cin >> n >> N;
        while (n >= N) {
            cout << "Промежуток не верный, введите повторно" << endl;
            cin >> n >> N;
        }

        int cnt = 0;
        for (int i = n; i != N; i++) {
            int res = 0;
            func(i, res, cnt);
            if (res != 0) {
                cout << "Совершенное число № " << cnt << ": " << res << endl;
            }
        }
        cout << "Количество таких чисел : " << cnt << endl;
        cout << "Хотите закончить программу? (Да - 1 / Нет - 0)" << endl;
        cin >> flag;
    }
}

void func(int i, int& res, int& cnt) {
    int a = 0;
    while (a < (i / 2)) {
        a++;
        if ((i % a) == 0) {
            res += a;
        }
    }

    if (i == res and i != 0 and i != 1) {
        cnt += 1;
    } else
        res = 0;
}
