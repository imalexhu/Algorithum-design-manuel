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
    int size;
    vector<UnionNode *> nodes;
    Union(int n)
    {
        this->size = n;
        for (int i = 0; i < n; i++)
        {
            nodes.push_back(new UnionNode(i));
        }
    }

    void createUnion(int a, int b)
    {
        if (nodes[a]->parents[0] == nodes[b]->parents[0])
        {
            cout << "Already in a union" << endl;
            return;
        }

        if (nodes[a]->parents.size() >= nodes[b]->parents.size())
        {
            nodes[b]->parents.insert(nodes[b]->parents.begin(), nodes[a]->parents[0]);
        }
        else
        {
            nodes[a]->parents.insert(nodes[a]->parents.begin(), nodes[b]->parents[0]);
        }
    }

    bool find(int a, int b)
    {
        return nodes[a]->parents[0] == nodes[b]->parents[0];
    }

    void print()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << i << " : ";
            for (int j = 0; j < nodes[i]->parents.size(); j++)
            {
                cout << nodes[i]->parents[j] << "\t";
            }
            cout << endl;
        }
    }
};
int main()
{
    Union u = Union(5);
    u.createUnion(1, 2);
    u.createUnion(2, 3);
    u.createUnion(3, 4);

    cout << u.find(1, 3) << endl;

    u.print();
}
