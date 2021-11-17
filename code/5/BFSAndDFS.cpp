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
class Node
{
public:
    int val;
    int location;
    Node *next;
    Node()
    {
    }
    Node(int val, Node *next, int location)
    {
        this->val = val;
        this->next = next;
        this->location = location;
    }
};
// this implimentation has been addapted to produce a undirected graph
class AdjacencyList
{
public:
    int size;
    vector<Node *> edges;

    AdjacencyList(int size)
    {
        this->size = size - 1;
        for (int i = 0; i < size; i++)
        {
            edges.push_back(new Node(i, nullptr, i));
        }
    }

    void insertEdge(int A, int B, int val)
    {
        if (A > size || B > size)
        {
            cout << "invalid" << endl;
            return;
        }
        Node *node = edges[A];
        Node *prev = NULL;
        while (node)
        {
            prev = node;
            node = node->next;
        }
        prev->next = new Node(val, nullptr, B);

        node = edges[B];
        prev = NULL;
        while (node)
        {
            prev = node;
            node = node->next;
        }
        prev->next = new Node(val, nullptr, A);
    }

    void removeEdge(int A, int B, int val)
    {
        if (A > size || B > size)
        {
            cout << "invalid" << endl;
            return;
        }

        Node *node = edges[A];
        Node *prev = NULL;
        while (node != nullptr)
        {
            cout << "Runing forever" << endl;
            prev = node;
            node = node->next;

            if (node->val == val)
            {
                prev->next = node->next;
                delete node;
                return;
            }
            getchar();
        }

        cout << " Doesnt Exist" << endl;
        return;
    }

    void print()
    {
        for (int i = 0; i < edges.size(); i++)
        {
            cout << " Node " << i << " : ";
            Node *head = edges[i];
            head = head->next;
            while (head)
            {
                cout << head->val << "\t";
                head = head->next;
            }
            cout << endl;
        }
    }
};

void bfs(AdjacencyList graph, int start)
{
    bool visited[graph.size] = {false};
    queue<int> queue;
    vector<int> visitedOrder;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty())
    {
        int cur = queue.front();
        queue.pop();
        visited[cur] = true;
        Node *head = graph.edges[cur];
        while (head)
        {
            int val = head->location;
            if (!visited[val])
            {
                queue.push(val);
                visited[val] = true;
            }
            head = head->next;
        }
        visitedOrder.push_back(cur);
    }
    cout << "BFS : ";
    for (auto i : visitedOrder)
    {
        cout << i << " \t";
    }
    cout << endl;
}

void dfs(AdjacencyList graph, int start)
{
    bool visited[graph.size] = {false};
    stack<int> stack;
    vector<int> visitedOrder;
    stack.push(start);
    visited[start] = true;

    while (!stack.empty())
    {
        int cur = stack.top();
        stack.pop();
        visited[cur] = true;
        Node *head = graph.edges[cur];
        while (head)
        {
            int val = head->location;
            if (!visited[val])
            {
                stack.push(val);
                visited[val] = true;
            }
            head = head->next;
        }
        visitedOrder.push_back(cur);
    }
    cout << "DFS : ";

    for (auto i : visitedOrder)
    {
        cout << i << " \t";
    }
    cout << endl;
}

int main()
{
    AdjacencyList graph = AdjacencyList(6);
    graph.insertEdge(5, 0, 2);
    graph.insertEdge(1, 0, 2);
    graph.insertEdge(0, 4, 2);
    graph.insertEdge(4, 1, 2);
    graph.insertEdge(4, 3, 2);
    graph.insertEdge(3, 2, 2);
    graph.insertEdge(2, 1, 2);

    bfs(graph, 0);
    dfs(graph, 0);
    return 0;
}