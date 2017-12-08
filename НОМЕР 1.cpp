#include <iostream>
using namespace std;

double func(double a, double b, double c, double x)
{
	int ac = (int)a;
	int bc = (int)b;
	int cc = (int)c;
	double y;
	if ((x - 1 < 0) && (b - x != 0))
		y = a*x*x + b;
	else if ((x - 1 > 0) && (b + x == 0))
		y = (x - a) / x;
	else
		y = x / c;
	int yc = (int)y;
	if ((ac | bc) ^ (bc & cc))
		return y;
	else 
		return yc;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double xstart, xend, dx, a, b, c;
	cout << "Введите xнач: ";
	cin >> xstart;
	do {
		cout << "Введите xкон: ";
		cin >> xend;
	} while (xend < xstart);
	do {
		cout << "Введите шаг: ";
		cin >> dx;
	} while (dx <= 0 || dx > xend - xstart);
	cout << "Введите a, b, c: ";
	cin >> a >> b >> c;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Табулирование функции F, заданной " << endl;
	cout << "на интервале от " << xstart << " до " << xend << " с шагом " << dx << ":" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "| значение аргумента | значение функции |" << endl;
	cout << "------------------------------------------------------" << endl;
	double x = xstart;
	while (x <= xend)
	{
		cout << "| " << x << "                  | "
			<< func(a, b, c, x) << "         |             " << endl;
		x += dx;
	} 
	system("pause");
	return 0;
}
