#include <iostream>

using namespace std;


void vvod(float mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
}

void vvod_dv_mas(float mas[][10], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		vvod(mas[i], n);
	}
}

void vivod_res(float res_mas[][10], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res_mas[i][j] << " ";
		}
		cout << endl;
	}
}