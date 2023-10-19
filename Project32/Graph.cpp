#include <iostream>
#include <fstream>
#include <clocale>
#include "Graph.h"
#include "D_Heap.h"

using namespace std;

Graph::Graph(int _n)
{
	n = _n;
	len = 0;
	dist = new int[n];
	up = new int[2 * n];
	h = new int[n];
	array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}
}

Graph :: ~Graph()
{
	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	delete[] dist;
	delete[] up;
	delete[] h;
}

void Graph::LDG_DIJKSTRA_MARK(int index_start, int index_end)
{
	len = 0;
	int* upp = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
		upp[i] = -1;
		h[i] = 0;
	}
	dist[index_start] = 0;

	for (int i = 0; i < n - 1; i++) {
		int u = minDist(dist, h);
		h[u] = 1;

		for (int j = 0; j < n; j++)
		{
			if (!h[j] && array[u][j] && dist[u] != INT_MAX && dist[u] + array[u][j] < dist[j])
			{
				dist[j] = dist[u] + array[u][j];
				upp[j] = u;
			}

		}
	}
	int current = index_end;
	while (current != -1) {
		up[len] = current;
		len++;
		current = upp[current];
	}
}

int Graph::minDist(int dist[], int h[])
{
	int min = INT_MAX, minIndex;

	for (int i = 0; i < n; i++)
	{
		if (h[i] == 0 && dist[i] <= min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int Graph::inputFile()
{
	int elemstr;
	ifstream inputFile("file1.txt"); // Открываем файл для чтения
	if (!inputFile) {
		cout << "Произошла ошибка при открытии файла!" << endl;
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inputFile >> array[i][j];
		}
	}
	inputFile.close(); // Закрываем файл
	return 0;
}

void Graph::LDG_DIJKSTRA_D_Heap(int index_start, int index_end)
{
	len = 0;
	int* upp = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
		upp[i] = -1;
		h[i] = 0;
	}
	dist[index_start] = 0;
	D_Heap A(n);
	A.insert(0, index_start);
	while (!A.isEmpty())
	{
		int currentVertex = A.remove(0);
		h[currentVertex] = 1;
		for (int j = 0; j < n; j++)
		{
			if (array[currentVertex][j] != 0 && dist[currentVertex] != INT_MAX && dist[currentVertex] + array[currentVertex][j] < dist[j])
			{
				if (A.findVertex(j))
				{
					A.key[j] = dist[currentVertex] + array[currentVertex][j];
					dist[j] = dist[currentVertex] + array[currentVertex][j];
					upp[j] = currentVertex;
				}
				else
				{
					dist[j] = dist[currentVertex] + array[currentVertex][j];
					A.insert(dist[j], j);
					upp[j] = currentVertex;
				}
			}

		}
	}
	int current = index_end;
	while (current != -1) {
		up[len] = current;
		len++;
		current = upp[current];
	}
}

//void Graph::generateGraph(int _n, int _m, int q, int r)
//{
//	int vertex1, vertex2, weight;
//	srand(time(NULL));
//
//	for (int i = 0; i < _n; i++)
//	{
//		for (int j = 0; j < _n; j++)
//			array[i][j] = 0;
//	}
//
//	for (int i = 0; i < _m; i++)
//	{
//		vertex1 = 0 + rand() % (_n);
//		vertex2 = 0 + rand() % (_n);
//		if (vertex1 != vertex2)
//		{
//			weight = q + rand() % (r - q + 1);
//			array[vertex1][vertex2] = weight;
//			array[vertex2][vertex1] = weight;
//		}
//	}
//}

void Graph::generateGraph(int _n, int _m, int q, int r)
{
	int weight, countEdge = 0;
	srand(time(NULL));
	double p = 0.5;
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
			array[i][j] = 0;
	}
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			weight = q + rand() % (r - q + 1);
			if (weight < p * r && countEdge <= _m)
			{
				array[i][j] = weight;
				array[j][i] = weight;
				countEdge++;
			}
		}
	}
}
void Graph::outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::outputResult(int index_start, int index_end)
{
	std::cout << endl << "Вершина \t Кратчайшее расстояние\n";
	for (int i = 0; i < n; i++)
		std::cout << i << "\t\t" << dist[i] << "\n";
	std::cout << "Кратчайший путь от " << index_start <<" вершины до " << index_end << " вершины: ";
	for (int i = len - 1; i >=0; i--)
		std::cout << up[i] << " ";
}

void Graph::outputFile(int tmp)
{
	ofstream out;
	ofstream outt;
	if (tmp == 0)
	{
		out.open("fileRes1.txt", std::ios::out);
		outt.open("fileRes2.txt", std::ios::out);
	}
	else
	{
		out.open("fileRes3.txt", std::ios::out);
		outt.open("fileRes4.txt", std::ios::out);
	}
	for (int i = 0; i < n; i++)
	{
		if (out.is_open())
			out << dist[i] << " ";
	}
	for (int i = len-1; i >= 0; i--)
	{
		if (outt.is_open())
			outt << up[i] << " ";
	}
	out.close();
	outt.close();
}