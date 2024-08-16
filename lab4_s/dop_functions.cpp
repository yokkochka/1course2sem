#include <cmath>
#include <iostream>

using namespace std;

int condition(float mas[][10], int m, int n) {
    int flag = 0;
    int count = m * n;
    float sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += mas[i][j];
        }
    }
    if (sum / count < 0) {
        flag = 1;
    }
    return flag;
}

void perenos(float mas[][10], int m, int n, float res_mas[][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res_mas[i][j] = mas[i][j];
        }
    }
}

void result(float mas[][10], int m, int n, float res_mas[][10]) {
    if (condition(mas, m, n) == 1) {
        cout << "Создеатся новая матрица" << endl;
        perenos(mas, m, n, res_mas);
        float min_ch = res_mas[0][0];
        int ind1 = 0;
        int ind2 = 0;
        float el;

        for (int i = 0; i < m; i++) {
            el = res_mas[i][i];
            for (int j = 0; j < n; j++) {
                if (min_ch > res_mas[i][j]) {
                    min_ch = res_mas[i][j];
                    ind1 = i;
                    ind2 = j;
                }
            }
            res_mas[i][i] = min_ch;
            res_mas[ind1][ind2] = el;
        }

    } else
        cout << "Матрица не изменилась" << endl;
}
