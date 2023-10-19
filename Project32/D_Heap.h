#pragma once
class D_Heap
{
public:
    int d, n, currentsize; //параметр d, n – максимальный размер d-кучи, currentsize – текущий размер
    int* key;             //массив ключей (весов)
    int* name;           //массив вершин

public:
    D_Heap() {

    }
    D_Heap(int n);  //конструктор инициализации
    ~D_Heap();     //деструктор
    int firstChild(int i); //получение индекса первого потомка узла
    int lastChild(int i); //получение индекса последнего потомка узла
    int minChild(int i); //получение минимального потомка узла
    int maxChild(int i);//получение максимального потомка узла
    int father(int i); //получение отца узла
    void sinking(int i);//погружение
    void bubbling(int i); //всплытие
    void formQeue(); //образование очереди!
    int getMinimum(); //получение минимума
    void insert(int tmp, int tmp_name); //вставка узла
    int remove(int index); //удаление узла
    void input_D_Heap();  //ввод d-кучи
    void output_D_Heap();//вывод d-кучи
    bool isEmpty();     //проверка на пустоту
    bool findVertex(int name); //проверка на присутствие элемента в куче
}; 
#pragma once
