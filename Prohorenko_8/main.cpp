#include <iostream>
#include <iomanip>

using namespace std;

//������� ����
void write_mas(double* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(8) << setprecision(4) << m[i] << " ";
	}
	cout << "\n";
}

//������� ����
void read_weights(double* weights, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "������� ��� " << i << "-�� ��������: ";
		cin >> weights[i];
	}
}

//���������� ������ 1 ���
void rotate_once(double* weights, int size)
{
	double last = weights[size - 1];//���������� ��������� �������
	//������� � �����, ����� �� �������� ������ �������������
	for (int i = size - 1; i > 0; --i)
	{
		weights[i] = weights[i - 1];
	}
	weights[0] = last;//� ������ ������������ ����� ��������� �������
}

//���������� ������ count ���
void rotate_multiple(double* weights, int size, int count)
{
	for (int i = 0; i < count; ++i)
	{
		//count ��� ���������� �� 1
		rotate_once(weights, size);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "��������� ������� ���������� ������ ��������� ������� ������ ���-111\n";
	cout << "��������� ��� ������� ������� ���������\n";

	int count;
	cout << "������� ���������� ���������: ";
	cin >> count;

	double* weights = new double[count];
	read_weights(weights, count);

	cout << "�� ��������� � ��������: \n";
	write_mas(weights, count);

	int k;
	cout << "������� ���������� ����� K: ";
	cin >> k;

	rotate_multiple(weights, count, k);

	cout << "����� �������������: \n";
	write_mas(weights, count);

	system("pause");

	return 0;
}
