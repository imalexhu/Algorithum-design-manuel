#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    vector<int> heap;
    int getLeft(int i)
    {
        return 2 * i + 1;
    }
    int getRight(int i)
    {
        return 2 * i + 2;
    }
    int getParent(int i)
    {
        return (i - 1) / 2;
    }

    void bubbleDown(int i)
    {
        int index = i;
        while (getLeft(index) < heap.size() && heap[index] > heap[getLeft(index)])
        {
            int minI = getLeft(index);
            int min = heap[getLeft(index)];
            if (getRight(index) < heap.size() && heap[getRight(index)] < min)
            {
                min = heap[getRight(index)];
                minI = getRight(index);
            }
            swap(heap[minI], heap[index]);
        }
    }

    int pop()
    {
        int index = 0;
        int val = heap[index];
        heap.erase(heap.begin());
        int temp = heap.back();
        heap.pop_back();
        heap.insert(heap.begin(), temp);
        bubbleDown(index);
        return val;
    }

    void bubbleUp(int i)
    {
        int index = i;
        while (getParent(i) > 0 && heap[getParent(i)] > heap[index])
        {
            swap(heap[index], heap[getParent(i)]);
        }
    }

    void add(int val)
    {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }

    void print()
    {
        for (auto i : heap)
        {
            cout << i << endl;
        }
    }
};

int main()
{

    vector<int> nums = {5, 4, 3, 2, 1};

    Heap *h = new Heap();
    h->add(1);
    h->add(3);
    h->add(66);
    h->add(17);
    h->add(2);
    h->print();
    h->pop();
    h->print();
    h->pop();
    h->print();

    return 0;
}