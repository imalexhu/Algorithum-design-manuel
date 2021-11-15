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
        Node* temp = new Node(val, nullptr,B);
        prev->next = temp;
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
        while (node != nullptr )
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
                cout << head->location << "\t";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    AdjacencyList graph = AdjacencyList(3);
    graph.insertEdge(0, 1, 3);
    graph.insertEdge(0, 2, 1);
    graph.insertEdge(1, 0, 2);
    graph.print();
    graph.removeEdge(2, 3, 3);
    graph.print();
    return 0;
}