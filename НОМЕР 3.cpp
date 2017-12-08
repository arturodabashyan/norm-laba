#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int M = 4;
	const int N = 5;

	int m[M][N] = {
		{ 9, 5, 1, -3, -7 },
		{ 8, 4, 0, -4, -8 },
		{ 7, 3, -1, -5, -9 },
		{ 6, 2, -2, -6, 0 }
	};

	cout << "Выведем матрицу:" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << "	" << m[i][j];
		cout << "\n\n";
	}
	cout << endl;

	cout << "Введите величину сдвига" << endl;
	int n;
	cin >> n;
	int* p, t;
	for (p = &m[0][0]; p != &m[M - 1][N]; p += N)
		for (int i = 0; i < n; ++i)
		{
			t = *(p + (N - 1));
			for (int* r = p + (N - 1); r > p; --r)
				*r = *(r - 1);
			*p = t;
		}
	cout << "Выведем матрицу после сдвига вправо на " << n << " элементов: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << "	" << m[i][j];
		cout << "\n\n";
	}
	cout << endl;
	int* e = &m[M - 1][0];
	for (p = &m[0][0]; p != &m[0][N]; ++p, ++e)
		for (int i = 0; i < n; ++i)
		{
			t = *e;
			for (int* r = e; r > p; r -= N)
				*r = *(r - N);
			*p = t;
		}
	
	cout << "Выведем матрицу после сдвига вниз на " << n << " элементов: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << "	" << m[i][j];
		cout << "\n\n";
	}
	cout << endl;

	system("pause");
	return 0;
}
