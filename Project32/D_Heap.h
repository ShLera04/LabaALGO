#pragma once
class D_Heap
{
public:
    int d, n, currentsize; //�������� d, n � ������������ ������ d-����, currentsize � ������� ������
    int* key;             //������ ������ (�����)
    int* name;           //������ ������

public:
    D_Heap() {

    }
    D_Heap(int n);  //����������� �������������
    ~D_Heap();     //����������
    int firstChild(int i); //��������� ������� ������� ������� ����
    int lastChild(int i); //��������� ������� ���������� ������� ����
    int minChild(int i); //��������� ������������ ������� ����
    int maxChild(int i);//��������� ������������� ������� ����
    int father(int i); //��������� ���� ����
    void sinking(int i);//����������
    void bubbling(int i); //��������
    void formQeue(); //����������� �������!
    int getMinimum(); //��������� ��������
    void insert(int tmp, int tmp_name); //������� ����
    int remove(int index); //�������� ����
    void input_D_Heap();  //���� d-����
    void output_D_Heap();//����� d-����
    bool isEmpty();     //�������� �� �������
    bool findVertex(int name); //�������� �� ����������� �������� � ����
}; 
#pragma once
