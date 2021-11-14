#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    vector<int> heap;

    int getLeft(int i)
    {
        int index = 2 * i + 1;
        if (index < heap.size())
            return index;
        else
            return -1;
    }
    int getRight(int i)
    {
        int index = 2 * i + 2;
        if (index < heap.size())
            return index;
        else
            return -1;
    }
    int getParent(int i)
    {
        int index = (i - 1) / 2;
        if (index >= 0)
            return index;
        else
            return -1;
    }

    void bubbleDown()
    {
        int index = 0;
        int smallestIndex = getLeft(index);
        while (smallestIndex != -1 && heap[index] > heap[smallestIndex])
        {
            // cout<< " left index " << smallestIndex <<endl;

            int rightIndex = getRight(index);
            // cout<< " Right index " << rightIndex <<endl;
            if (rightIndex != -1 && heap[rightIndex] < heap[smallestIndex])
            {
                // cout << "Why are you running " << endl;
                smallestIndex = rightIndex;
            }
            // cout << "SmallestIndex : " << smallestIndex << "  "
            //      << "index : " << index << endl;
            // cout << " smallestIndex val : " << heap[smallestIndex] << " : "
            //      << "Index Val : " << heap[index] << endl;
            swap(heap[smallestIndex], heap[index]);
            index = smallestIndex;
            smallestIndex = getLeft(index);
        }
    }

    int pop()
    {
        if(heap.size()==1){
            int val = heap.back();
            heap.pop_back();
            return val;
        }
        int val = heap[0];
        heap.erase(heap.begin());
        int temp = heap.back();
        heap.pop_back();
        heap.insert(heap.begin(), temp);
        bubbleDown();
        return val;
    }

    void bubbleUp()
    {
        int index = heap.size() - 1;
        int parentIndex = getParent(index);
        while (heap[index] < heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = getParent(index);
            // cout << "parentIndex : " << parentIndex << "  "
            //      << "index : " << index << endl;
            // cout << " Parent val : " << heap[parentIndex] << " : "
            //      << "Index Val : " << heap[index] << endl;
        }
    }

    void add(int val)
    {
        heap.push_back(val);
        bubbleUp();
    }

    void print()
    {
        for (auto i : heap)
        {
            cout << i << endl;
        }
    }

    void heapSort(vector<int> &nums)
    {
        for (auto i : nums)
        {
            add(i);
        }
        nums.clear();
        print();
        cout << "new " << endl;
        while (!heap.empty())
        {
            int temp = pop();
            nums.push_back(temp);
        }
    }
};

int main()
{

    vector<int> nums = {5, 4, 3, 2};

    Heap *h = new Heap();
    // h->add(1);
    // h->add(2);
    // h->add(3);
    // h->add(4);
    // h->add(5);
    // h->print();
    // h->pop();
    // h->print();
    // h->add(1);
    // h->pop();
    // h->print();

    h->heapSort(nums);

    for (auto i : nums)
    {
        cout << i << endl;
    }

    return 0;
}