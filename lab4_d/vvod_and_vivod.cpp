#include <iostream>

using namespace std;

int** vvod(int m, int n) {
    int** mas;
    mas = new int*[m];
    for (int i = 0; i < m; i++) {
        mas[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> *(*(mas + i) + k);
        }
    }
    return mas;
}

void vivod_res(int m, int n, int** res_mas) {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            cout << *(*(res_mas + i) + k) << " ";
        }
        cout << endl;
    }
}