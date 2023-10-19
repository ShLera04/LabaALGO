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
		std::cout << "\t����� ����������� ���� � �����\t" << endl;
		std::cout << "����" << endl;
		do
		{
			std::cout << "1. �������� �������� �� ��������� �����\n2. ������������ ����������\n��� �����: ";
			std::cin >> ans;
			if (ans <= 0 || ans >= 3)
				std::cout << "������! ��������� ���� ������!" << endl;
		} while (ans <= 0 || ans >= 3);
		switch (ans)
		{
		case 1:
		{
			system("cls");
			int s, ss;
			std::cout << "\t����� ����������� ���� � �����\t" << endl;
			do
			{
				std::cout << "����� ������: ";
				std::cin >> n;
				if (n <= 0)
					std::cout << "��������� ������ �����������! ��������� ����!" << endl;
			} while (n <= 0);
			Graph A(n);
			A.inputFile();
			std::cout << "������� �������, �� ������� ���������� ����� ���������� ����������: ";
			std::cin >> s;
			std::cout << "������� �������, �� ������� ���������� ����� ���������� ����������: ";
			std::cin >> ss;
			A.LDG_DIJKSTRA_D_Heap(s,ss);
			std::cout << "\t�������� ��������, ���������� �� d-����\t" << endl;
			A.outputResult(s,ss);
			A.outputFile(0);
			A.LDG_DIJKSTRA_MARK(s, ss);
			std::cout << "\n\t�������� �������� �� ������\t" << endl;
			A.outputResult(s,ss);
			A.outputFile(1);
			break;
		}
		case 2:
		{
			system("cls");
			int s;
			std::cout << "\t����� ����������� ���� � �����. ������������ ����������.\t" << endl;
			do
			{
				std::cout << "������� ����� �����: ";
				std::cin >> s;
				if (s <= 0 || s >= 8)
					std::cout << "������! ��������� ���� ������!" << endl;

			} while (s <= 0 || s >= 8);
			switch (s)
			{
			case 1:
			{
				test1();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 2:
			{
				test2();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 3:
			{
				test3();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 4:
			{
				test4();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 5:
			{
				test5();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 6:
			{
				test6();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			case 7:
			{
				test7();
				std::cout << "���������� ����� ���������!" << endl;
				break;
			}
			}
		}
		}
		std::cout << "\n���� �� ������ ���������� - 1, � ��������� ������ - ����� �������!\n��� �����: ";
		std::cin >> answer;
	} while (answer);
}