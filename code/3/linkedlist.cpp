#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

int RecSearch(Node *node, int t, int i)
{
    if (node == NULL)
    {
        return -1;
    }

    if (node->val == t)
    {
        return i;
    }

    return RecSearch(node->next, t, ++i);
}

void RecPrint(Node *node)
{
    if (node == NULL)
        return;
    cout << node->val << endl;
    RecPrint(node->next);
}

class LinkedList
{
public:
    Node *head;
    LinkedList(){};
    LinkedList(vector<int> nums)
    {
        reverse(nums.begin(), nums.end());
        Node *next = NULL;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            next = new Node(nums[i], next);
        }
        this->head = new Node(nums.back(), next);
    }

    void insert(int x)
    {
        Node *temp = new Node(x, head);
        head = temp;
    }

    void del(int t)
    {
        int pos = RecSearch(head, t, 0);

        if (pos == -1)
        {
            cout << "Non node" << endl;
            return;
        }

        Node *cur = head;
        Node *prev = NULL;
        while (pos != 0)
        {
            prev = cur;
            cur = cur->next;
            pos--;
        }
        Node *store = cur->next;
        prev->next = store;
        delete cur;
    }
};

main()
{

    vector<int> nums = {5, 4, 3, 2, 1};

    LinkedList l = LinkedList(nums);
    RecPrint(l.head);
    cout << "Found 1 at position " << RecSearch(l.head, 1, 0) << endl;
    l.del(3);
    RecPrint(l.head);

    return 0;
}