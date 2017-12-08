#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct NOTE
{
	string name;
	string surname; 
	string telephone; 
	int b_date[3]; 
};

void input_NOTE(NOTE& n)
{
	cout << "Введите фамилию имя телефон (телефон без пробелов): ";
	cin >> n.surname >> n.name >> n.telephone;
	cout << "Введите дату рождения в формате DD MM YY: ";
	cin >> n.b_date[0] >> n.b_date[1] >> n.b_date[2];
}

void output_NOTE(NOTE& n)
{
	cout << endl << "Фамилия = " << n.surname
		<< endl << "Имя = " << n.name
		<< endl << "Номер телефона = " << n.telephone
		<< endl << "Дата рождения:"
		<< endl << "День = " << n.b_date[0]
		<< endl << "Месяц = " << n.b_date[1]
		<< endl << "Год = " << n.b_date[2] << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int n = 8;
	string surname;
	NOTE note[n];
	for (int i = 0; i < n; ++i)
		input_NOTE(note[i]);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (note[j].surname > note[j + 1].surname)
			{
				NOTE temp = note[j];
				note[j] = note[j + 1];
				note[j + 1] = temp;
			}
			else
				if (note[j].surname == note[j + 1].surname)
				{
					if (note[j].name > note[j + 1].name)
					{
						NOTE temp = note[j];
						note[j] = note[j + 1];
						note[j + 1] = temp;
					}
				}
		}
	}

	cout << "Отсортированный по алфавиту массив структур: " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << endl << i + 1 << ")" << endl;
		output_NOTE(note[i]);
	}
	int month;
	cout << endl << "Введите месяц: ";
	cin >> month;
	bool find = false;
	for (int i = 0; i < n; ++i)
	{
		if (month == note[i].b_date[1])
		{
			output_NOTE(note[i]);
			find = true;
		}
	}
	if (!find) 
		cout << "Не найдено людей, чьи дни рождения приходятся на месяц " << month << endl;
	system("pause");
	return 0;
}
