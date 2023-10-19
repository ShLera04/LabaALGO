#pragma once
class Graph
{
	int** array; //������� ���������
	int n, len; //�������
	int* dist; //������ ���������� ����������
	int* up;  //������ ����������� ����
	int* h;  //������ �����
public:
	Graph(int n); //����������� �������������
	~Graph();    //����������
	int minDist(int dist[], int h[]); //��������� ������������ ����������
	int inputFile(); //������ �� �����
	void generateGraph(int n, int m, int q, int r); //��������� �����
	void outputGraph(); //����� �����
	void outputResult(int index_start, int index_end);//����� ����������� 
	void LDG_DIJKSTRA_D_Heap(int index_start, int index_end);//�������� �������� �� d-����
	void LDG_DIJKSTRA_MARK(int index_start, int index_end);//�������� �������� �� ������
	void outputFile(int s);//����� ���������� ����������� � �����
};
