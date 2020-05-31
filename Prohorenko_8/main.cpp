#include <iostream>
#include <iomanip>

using namespace std;

//вывести веса
void write_mas(double* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(8) << setprecision(4) << m[i] << " ";
	}
	cout << "\n";
}

//считать веса
void read_weights(double* weights, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите вес " << i << "-го толстяка: ";
		cin >> weights[i];
	}
}

//провернуть массив 1 раз
void rotate_once(double* weights, int size)
{
	double last = weights[size - 1];//запоминаем последний элемент
	//вращаем с конца, чтобы не городить лишние переписывания
	for (int i = size - 1; i > 0; --i)
	{
		weights[i] = weights[i - 1];
	}
	weights[0] = last;//в начало переписываем самый последний элемент
}

//провернуть массив count раз
void rotate_multiple(double* weights, int size, int count)
{
	for (int i = 0; i < count; ++i)
	{
		//count раз провернуть на 1
		rotate_once(weights, size);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Прохоренко Полина Андреевна студент группы УТН-111\n";
	cout << "Программа для расчёта объёмов цилиндров\n";

	int count;
	cout << "Введите количество толстяков: ";
	cin >> count;

	double* weights = new double[count];
	read_weights(weights, count);

	cout << "Вы работаете с массивом: \n";
	write_mas(weights, count);

	int k;
	cout << "Введите количество часов K: ";
	cin >> k;

	rotate_multiple(weights, count, k);

	cout << "После пересаживаний: \n";
	write_mas(weights, count);

	system("pause");

	return 0;
}
