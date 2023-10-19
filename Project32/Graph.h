#pragma once
class Graph
{
	int** array; //матрица смежности
	int n, len; //размеры
	int* dist; //массив кратчайших расстояний
	int* up;  //массив кратчайшего пути
	int* h;  //массив меток
public:
	Graph(int n); //конструктор инициализации
	~Graph();    //деструктор
	int minDist(int dist[], int h[]); //получение минимального расстояния
	int inputFile(); //чтение из файла
	void generateGraph(int n, int m, int q, int r); //генерация графа
	void outputGraph(); //вывод графа
	void outputResult(int index_start, int index_end);//вывод результатов 
	void LDG_DIJKSTRA_D_Heap(int index_start, int index_end);//алгоритм Дейкстры на d-куче
	void LDG_DIJKSTRA_MARK(int index_start, int index_end);//алгоритм Дейкстры на метках
	void outputFile(int s);//вывод полученных результатов в файлы
};
