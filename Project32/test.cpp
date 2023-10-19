#include <iostream>
#include <fstream>
#include "Graph.h"
#include "test.h"
#include <ctime>

using namespace std;
void test1()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 1; i <= 10001; i += 150)
	{
		Graph A(i);
		A.generateGraph(i, i, 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0, 1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0, 1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}
void test2()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 1; i <= 10001; i += 150)
	{
		Graph A(i);		
		A.generateGraph(i, (i*i)/10, 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}

void test3()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 1; i <= 10001; i += 100)
	{
		Graph A(i);
		A.generateGraph(i, (i * i), 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}

void test4()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 101; i <= 10001; i += 100)
	{
		Graph A(i);
		A.generateGraph(i, 100 * i, 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}

void test5()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 101; i <= 10001; i += 100)
	{
		Graph A(i);
		A.generateGraph(i, 1000 * i, 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}
void test6()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 0; i <= 10000000; i += 10000)
	{
		Graph A(10001);
		A.generateGraph(10001, i, 1, 1000000);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}

void test7()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 1; i <= 200; i++)
	{
		Graph A(10001);
		A.generateGraph(10001, 10001 * 10001, 1, i);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}

void test8()
{
	ofstream out;
	ofstream outt;
	out.open("fileTest1.txt", std::ios::out);
	outt.open("fileTest2.txt", std::ios::out);
	for (int i = 1; i <= 200; i++)
	{
		Graph A(10001);
		A.generateGraph(10001, 10001 * 1000, 0, i);
		unsigned int start_time = clock();//начальное время
		A.LDG_DIJKSTRA_D_Heap(0,1);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time1 = end_time - start_time; // искомое время
		if (out.is_open())
		{
			out << i << " " << search_time1 << std::endl;
		}
		start_time = clock();//начальное время
		A.LDG_DIJKSTRA_MARK(0,1);
		end_time = clock(); // конечное время
		search_time1 = end_time - start_time; // искомое время
		if (outt.is_open())
		{
			outt << i << " " << search_time1 << std::endl;
		}
	}
	out.close();
	outt.close();
}