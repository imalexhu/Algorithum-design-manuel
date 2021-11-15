#include <bits/stdc++.h>
using namespace std;

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