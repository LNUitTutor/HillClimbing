#include <iostream>
#include <set>
#include <Windows.h>

using word = unsigned short;

int main()
{
	SetConsoleOutputCP(1251);    // ������������ ��������
	const int N = 5;  // ���������� ������ � �'����� ������
	// ������� ���������
	word C[N][N] = { { 65535, 1, 2, 7, 5 },
					 { 1, 65535, 4, 4, 3 },
					 { 2, 4, 65535, 1, 2 },
					 { 7, 4, 1, 65535, 3 },
					 { 5, 3, 2, 3, 65535 } };
	std::cout << "������ ����� ����������� ����: ";
	int town;
	std::cin >> town;

	int tour[N + 1] = { town }; // ��� ���������� � ������ ���
	int current = town - 1;              // ������� ����
	std::set<int> visited = { current }; // ������� �������� ���
	word cost = 0;                       // ������� ����

	for (int k = 1; k < N; ++k)
	{
		int index_of_min;                      // ������ ����������� ����
		word min_value = C[current][current];  // � ��������� �������
		for (int i = 0; i < N; ++i)            // ����� ���������� ���
			if (visited.count(i) == 0 && C[current][i] < min_value)
			{
				min_value = C[current][i];
				index_of_min = i;
			}
		tour[k] = index_of_min + 1;            // �������� � ���� ����
		cost += C[current][index_of_min];
		visited.insert(index_of_min);
		current = index_of_min;
	}
	// ��� ����������� � ������ ���
	tour[N] = town;
	cost += C[current][town - 1];

	std::cout << "���������� �������:\n";
	for (int i = 0; i < N; ++i)
		std::cout << tour[i] << " --> " << tour[i + 1] << '\n';
	std::cout << "������� ����: " << cost << '\n';
	return 0;
}