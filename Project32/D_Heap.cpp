#include <iostream>
#include <fstream>
#include "D_Heap.h"
using namespace std;


D_Heap::D_Heap(int _n)
{
    n = _n;
    d = 3;
    currentsize = 0;
    key = new int[n];
    name = new int[n];
}

D_Heap :: ~D_Heap()
{
    delete[] key;
    delete[] name;
}


int D_Heap::firstChild(int i) {
    int k = i * d + 1;
    if (k > (currentsize - 1))
        return -1;
    else
        return k;
}

int D_Heap::lastChild(int i)
{
    int k = i * d + d;
    if (k > (currentsize - 1))
        return -1;
    else return k;
}

int D_Heap::minChild(int i) {
    int first = firstChild(i);
    if (first == -1)//? провера на то есть ли потомки
        return i;
    else {
        int last = lastChild(i);
        int min_key = key[first];
        int minchild = first;
        for (int j = first + 1; j <= last; j++) {
            if (key[j] < min_key) {
                min_key = key[j];
                minchild = j;
            }
        }
        return minchild;
    }
}

int D_Heap::father(int i) {
    return ((i - 1) / d);
}

void D_Heap::bubbling(int i)
{
    int p = father(i);
    while (i != 0 && key[i] < key[p])
    {
        swap(key[i], key[p]);
        swap(name[i], name[p]);
        i = p;
        p = father(i);
    }
}

void D_Heap::sinking(int i)
{
    int p = minChild(i);
    while (p != i && key[i] > key[p])//p!=i
    {
        swap(key[i], key[p]);
        swap(name[i], name[p]);
        i = p;
        p = minChild(i);
    }
}

int D_Heap::maxChild(int i)
{
    int first = firstChild(i);
    if (first == -1)
        return i;
    else {
        int last = lastChild(i);
        int max_key = key[first];
        int maxchild = first;
        for (int j = first + 1; j <= last; j++) {
            if (key[j] > max_key) {
                max_key = key[j];
                maxchild = j;
            }
        }
        return maxchild;
    }

}

void D_Heap::insert(int tmp, int tmp_name)
{
    if (currentsize < n)
    {
        key[currentsize] = tmp;
        name[currentsize] = tmp_name;
        bubbling(currentsize);
        currentsize++;
    }
}

void D_Heap::formQeue()
{
    for (int i = n; i >= 0; i--)
        sinking(i);
}

int D_Heap::getMinimum() {
    int name1 = name[0];
    int key1 = key[0];
    name[0] = name[n - 1];
    key[0] = key[n - 1];
    name[n - 1] = name1;
    key[n - 1] = key1;
    currentsize--;
    if (currentsize > 1)
        sinking(0);
    return name1;
}

void D_Heap::input_D_Heap()
{
    for (int i = currentsize; i < n; i++)
    {
        cin >> key[i];
        currentsize++;
    }
}

int D_Heap::remove(int i)
{
    int tmp, name_tmp = 0;
    if (currentsize != 0)
    {
        tmp = key[i];
        name_tmp = name[i];
        key[i] = key[currentsize - 1];
        name[i] = name[currentsize - 1];
        currentsize--;
        if (i != 0 && key[i] > key[father(i)])
            bubbling(i);
        else
            sinking(i);
    }
    return name_tmp;
}

void D_Heap::output_D_Heap()
{
    for (int i = 0; i < currentsize; i++)
    {
        cout << name[i] << "." << key[i] << endl;
    }
}

bool D_Heap::isEmpty()
{
    bool res = false;
    if (currentsize == 0)
        res = true;
    return res;
}

bool D_Heap::findVertex(int _name)
{
    bool res = false;
    if (name[_name] == _name)
        res = true;
    return res;

}