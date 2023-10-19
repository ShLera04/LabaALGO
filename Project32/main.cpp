#include <iostream>
#include <fstream>
#include <clocale>
#include "Graph.h"
#include "D_Heap.h"
#include "test.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m = 0, ans = 0, answer=0;
	do
	{
		system("cls");
		std::cout << "\tПоиск кратчайшего пути в графе\t" << endl;
		std::cout << "Меню" << endl;
		do
		{
			std::cout << "1. Алгоритм Дейкстры на небольшом графе\n2. Тестирование алгоритмов\nВаш выбор: ";
			std::cin >> ans;
			if (ans <= 0 || ans >= 3)
				std::cout << "Ошибка! Повторите ввод заново!" << endl;
		} while (ans <= 0 || ans >= 3);
		switch (ans)
		{
		case 1:
		{
			system("cls");
			int s, ss;
			std::cout << "\tПоиск кратчайшего пути в графе\t" << endl;
			do
			{
				std::cout << "Число вершин: ";
				std::cin >> n;
				if (n <= 0)
					std::cout << "Введенные данные некорректны! Повторите ввод!" << endl;
			} while (n <= 0);
			Graph A(n);
			A.inputFile();
			std::cout << "Введите вершину, от которой необходимо найти кратчайшие расстояния: ";
			std::cin >> s;
			std::cout << "Введите вершину, до которой необходимо найти кратчайшие расстояния: ";
			std::cin >> ss;
			A.LDG_DIJKSTRA_D_Heap(s,ss);
			std::cout << "\tАлгоритм Дейкстры, основанный на d-куче\t" << endl;
			A.outputResult(s,ss);
			A.outputFile(0);
			A.LDG_DIJKSTRA_MARK(s, ss);
			std::cout << "\n\tАлгоритм Дейкстры на метках\t" << endl;
			A.outputResult(s,ss);
			A.outputFile(1);
			break;
		}
		case 2:
		{
			system("cls");
			int s;
			std::cout << "\tПоиск кратчайшего пути в графе. Тестирование алгоритмов.\t" << endl;
			do
			{
				std::cout << "Введите номер теста: ";
				std::cin >> s;
				if (s <= 0 || s >= 8)
					std::cout << "Ошибка! Повторите ввод заново!" << endl;

			} while (s <= 0 || s >= 8);
			switch (s)
			{
			case 1:
			{
				test1();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 2:
			{
				test2();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 3:
			{
				test3();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 4:
			{
				test4();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 5:
			{
				test5();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 6:
			{
				test6();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			case 7:
			{
				test7();
				std::cout << "Выполнение теста завершено!" << endl;
				break;
			}
			}
		}
		}
		std::cout << "\nЕсли вы хотите продолжить - 1, в противном случае - любая клавиша!\nВаш выбор: ";
		std::cin >> answer;
	} while (answer);
}