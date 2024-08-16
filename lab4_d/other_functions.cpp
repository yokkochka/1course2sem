#include <iostream>

using namespace std;

int condition(int **mas, int m, int n) {
    int flag = 0;
    int count = m * n;
    float sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += *(*(mas + i) + j);
        }
    }
    if (sum / count < 0) {
        flag = 1;
    }
    return flag;
}

int **perenos(int m, int n, int **mas) {
    int **res_mas = new int *[m];
    for (int i = 0; i < m; i++) {
        res_mas[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(res_mas + i) + j) = *(*(mas + i) + j);
        }
    }
    return res_mas;
}

int **result(int m, int n, int **mas) {
    if (condition(mas, m, n) == 1) {
        cout << "Создается новая матрица" << endl;
        int **res_mas;
        res_mas = perenos(m, n, mas);

        float min_ch = *(*(res_mas + 0) + 0);
        int ind1 = 0;
        int ind2 = 0;
        float el;

        for (int i = 0; i < m; i++) {
            el = *(*(res_mas + i) + i);
            for (int j = 0; j < n; j++) {
                if (min_ch > *(*(res_mas + i) + j)) {
                    min_ch = *(*(res_mas + i) + j);
                    ind1 = i;
                    ind2 = j;
                }
            }
            *(*(res_mas + i) + i) = min_ch;
            *(*(res_mas + ind1) + ind2) = el;
            return res_mas;
        }
    } else
        cout << "Матрица не изменилась" << endl;

    return 0;
}
