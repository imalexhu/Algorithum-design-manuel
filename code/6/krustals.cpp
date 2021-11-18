#include <bits/stdc++.h>
#include <tuple>
using namespace std;
class UnionNode
{
public:
    vector<int> parents;

    UnionNode(int parent)
    {
        parents.push_back(parent);
    }
};

class Union
{
public:
    vector<int> rank;
    vector<int> parents;
    vector<int> setSize;
    int numSets;

    Union(int n)
    {
        this->rank.assign(n, 0);
        this->setSize.assign(n, 1);
        this->parents.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }

        this->numSets = n;
    }

    int findSet(int n)
    {
        if (parents[n] == n)
        {
            return n;
        }
        return findSet(parents[n]);
    }

    bool isSameSet(int i, int j)
    {
        int x = findSet(i);
        int y = findSet(j);

        cout << "Set i : " << x << " Set j " << y << endl;
        return x == y;
    }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i);
            int y = findSet(j);

            if (rank[x] > rank[y])
            {
                parents[j] = x;
                setSize[i] += setSize[j];
            }
            else
            {
                parents[i] = y;
                setSize[j] += setSize[i];
                if (rank[x] == rank[y])
                {
                    rank[y]++;
                }
            }
        }
    }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
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

    static bool edgeCompare(Edge i, Edge j) { return (i.weight < j.weight); }
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

int krustals(AdjacencyList graph)
{

    vector<Edge> edges;
    for (int i = 0; i < graph.size; i++)
    {
        Node *head = graph.edges[i];
        int start = head->val;
        head = head->next;
        while (head)
        {
            edges.push_back(Edge(head->val, start, head->location));
            head = head->next;
        }
    }

    sort(edges.begin(), edges.end(), Edge::edgeCompare);

    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].start << " : " << edges[i].end << " = " << edges[i].weight << endl;
    }
    int sum = 0;

    Union U = Union(graph.size+1);
    int index = 0;
    while (U.numSets != 1 || index < edges.size())
    {
        cout << U.numSets << endl;
        if (!U.isSameSet(edges[index].start, edges[index].end))
        {
            sum += edges[index].weight;
            U.unionSet(edges[index].start, edges[index].end);
        }
        index++;
    }
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

    int krustalsVal = krustals(graph);

    cout << krustalsVal << endl;

    return 0;
}