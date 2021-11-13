#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node()
    {
    }
    Node(int x)
    {
        this->val = x;
    }
};

void inOrder(Node *n)
{
    if (!n)
        return;
    inOrder(n->left);
    cout << n->val << endl;
    inOrder(n->right);
}

Node *insert(Node *n, int t)
{
    if (n == nullptr)
    {
        return new Node(t);
    }
    else
    {
        if (t > n->val)
        {
            n->right = insert(n->right, t);
        }
        else if (n->val == t)
        {
            return NULL;
        }
        else if (t < n->val)
        {
            n->left = insert(n->left, t);
        }
    }
    return n;
}

int main()
{

    vector<int> nums = {5, 4, 3, 2, 1};

    Node *head = nullptr;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
        head = insert(head, nums[i]);
    }
    getchar();

    inOrder(head);

    return 0;
}