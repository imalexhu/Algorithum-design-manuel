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

int prims(AdjacencyList graph)
{
    int sum = 0;

    bool visited[graph.size] = {false};
    vector<Edge> edges;
    Node *cur = graph.edges[0];
    visited[0] = true;
    int counter = graph.size;

    addEdges(visited, cur, edges);

    while (counter != 0)
    {
        int minTo;
        int min = INT_MAX;
        for (int i = 0; i < edges.size(); i++)
        {
            if (min > edges[i].weight && !visited[edges[i].end])
            {
                min = edges[i].weight;
                minTo = edges[i].end;
            }
        }

        cout << "went from " << cur->location << " to " << minTo << " for " << min << endl;
        cur = graph.edges[minTo];
        visited[minTo] = true;
        edges.erase(edges.begin() + minTo);
        sum += min;
        addEdges(visited, cur, edges);
        counter--;
    }

    return sum;
}

int krustals(AdjacencyList graph)
{
    int sum = 0;
    return sum;
}

int main()
{
    AdjacencyList graph = AdjacencyList(4);
    graph.insertEdge(0, 1, 1);
    graph.insertEdge(0, 2, 2);
    graph.insertEdge(0, 3, 3);
    graph.insertEdge(1, 2, 2);
    graph.insertEdge(1, 3, 1);
    graph.insertEdge(2, 3, 4);

    int primsVal = prims(graph);
    cout << primsVal << endl;
    // int krustalsVal = krustals(graph);

    return 0;
}