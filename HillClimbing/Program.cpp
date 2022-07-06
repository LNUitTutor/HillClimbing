#include <iostream>
#include <set>
#include <Windows.h>

using word = unsigned short;

int main()
{
	SetConsoleOutputCP(1251);    // налаштування кирилиці
	const int N = 5;  // розглянемо задачу з п'ятьма містами
	// матриця вартостей
	word C[N][N] = { { 65535, 1, 2, 7, 5 },
					 { 1, 65535, 4, 4, 3 },
					 { 2, 4, 65535, 1, 2 },
					 { 7, 4, 1, 65535, 3 },
					 { 5, 3, 2, 3, 65535 } };
	std::cout << "Введіть номер початкового міста: ";
	int town;
	std::cin >> town;

	int tour[N + 1] = { town }; // тур починається в рідному місті
	int current = town - 1;              // поточне місто
	std::set<int> visited = { current }; // множина відвіданих міст
	word cost = 0;                       // вартість туру

	for (int k = 1; k < N; ++k)
	{
		int index_of_min;                      // шукаємо продовження туру
		word min_value = C[current][current];  // з найменшою вартістю
		for (int i = 0; i < N; ++i)            // серед невідвіданих міст
			if (visited.count(i) == 0 && C[current][i] < min_value)
			{
				min_value = C[current][i];
				index_of_min = i;
			}
		tour[k] = index_of_min + 1;            // переїхали в нове місто
		cost += C[current][index_of_min];
		visited.insert(index_of_min);
		current = index_of_min;
	}
	// тур завершується в рідному місті
	tour[N] = town;
	cost += C[current][town - 1];

	std::cout << "Прокладено маршрут:\n";
	for (int i = 0; i < N; ++i)
		std::cout << tour[i] << " --> " << tour[i + 1] << '\n';
	std::cout << "Вартість туру: " << cost << '\n';
	return 0;
}