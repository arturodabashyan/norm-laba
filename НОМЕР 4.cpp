#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Point
{
	double x, y;
};

struct Circle
{
	double x, y, r;
};

bool intersect(Point a, Point b, Circle c)
{
	double s = abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)
	double ab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double h = s / ab;
	return (h < c.r);
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / (RAND_MAX + 1.0);
	return fMin + f * (fMax - fMin);
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество точек: " << endl;
	int n;
	cin >> n;
	Point* points = new Point[n];
	for (int i = 0; i < n; i++)
	{
		points[i].x = fRand(-10, 10);
		points[i].y = fRand(-10, 10);
	}
	cout << endl;
	cout << "Введите количество окружностей: " << endl;
	int m;
	cin >> m;
	Circle* circles = new Circle[m];
	for (int i = 0; i < m; i++)
	{
		circles[i].x = fRand(-5, 5);
		circles[i].y = fRand(-5, 5);
		circles[i].r = fRand(1, 5);
	}
	cout << endl;
	cout << "Координаты точек: " << endl;
	for (int i = 0; i < n; i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
	cout << endl;
	cout << "Параметры окружностей: " << endl;
	for (int i = 0; i < m; i++)
		cout << "(" << circles[i].x << ", " << circles[i].y << "), радиус = " << circles[i].r << endl;
	int mx = 0;
	int imx = 0;
	int jmx = 0;
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n - 1; j++)
	{
		int k = 0;
		for (int p = 0; p < m; p++)
			if (intersect(points[i], points[j], circles[p]))
				k++;
		if (k > mx)
		{
			mx = k;
			imx = i;
			jmx = j;
		};
	}
	cout << endl;
	if (mx == 0)
		cout << "Нет пересекающихся прямых и окружностей" << endl;
	else
	{
		cout << "Максимальное число пересечений прямой с окружностями = " << mx << endl;
		cout << endl;
		cout << "Прямая проходит через точки (" << points[imx].x << ", " << points[imx].y
			<< ") и (" << points[jmx].x << ", " << points[jmx].y << ")" << endl;
	}

	system("pause");
	return 0;
}
