#include <bits/stdc++.h>
#include <tuple>
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

class Edge
{
public:
    int weight;
    int start;
    int end;

    Edge(int weight, int start, int end)
    {
        this->weight = weight;
        this->start = start;
        this->end = end;
    }
};

void addEdges(bool *visited, Node *node, vector<Edge> &edges)
{
    int start = node->val;
    node = node->next;
    while (node)
    {
        int weight = node->val;
        int to = node->location;
        if (!visited[to])
        {
            cout << "inserting edge" << start << " : " << to << " for " << weight << endl;
            edges.push_back(Edge(weight, start, to));
        }
        node = node->next;
    }
}

vector<int> dijstras(AdjacencyList graph, int start)
{

    bool visited[graph.size] = {false};
    vector<int> shortestPath(graph.size, INT_MAX);
    int sum = 0;

    queue<int> queue;
    queue.push(start);
    shortestPath[start] = 0;
    visited[start] = true;

    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        Node *cur = graph.edges[node];
        visited[node] = true;
        cur = cur->next;
        int minLocation;
        int min = INT_MAX;
        while (cur)
        {
            if (!visited[cur->location])
            {
                if (cur->val + shortestPath[node] < shortestPath[cur->location])
                {
                    shortestPath[cur->location] = cur->val + shortestPath[node];
                }

                if (cur->val + shortestPath[node] < min)
                {
                    min = cur->val + shortestPath[node];
                    minLocation = cur->location;
                }
                cout << "location : " << cur->location << " weight " << cur->val << endl;
            }
            cur = cur->next;
        }
        cout << "Added : " << minLocation << endl;
        if (!visited[minLocation])
        {
            queue.push(minLocation);
        }
        getchar();
    }
    return shortestPath;
}

int main()
{
    AdjacencyList graph = AdjacencyList(4);
    graph.insertEdge(0, 1, 10);
    graph.insertEdge(0, 2, 1);
    graph.insertEdge(2, 1, 3);

    vector<int> ret = dijstras(graph, 0);

    for (auto i : ret)
    {
        cout << i << "\t";
    }
    cout << endl;
    return 0;
}