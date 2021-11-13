#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *arr[26];
    Node *next;
    bool finish = false;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            arr[i] = nullptr;
        }
    }
};

class TrieNode
{
public:
    Node *head;

    TrieNode()
    {
        this->head = new Node();
    }
};

void insert(Node *n, int i, string s)
{
    if (i == s.size())
    {
        n->finish = true;
        return;
    }

    int index = (int)s[i] % 32;
    if (n->arr[index])
    {
        insert(n->arr[index], ++i, s);
    }
    else
    {
        cout << s[i] << " : " << index << endl;
        Node *temp = new Node();
        n->arr[index] = temp;
        insert(n->arr[index], ++i, s);
    }
}

string findTrie(Node *cur, string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        int index = (int)s[i] % 32;
        if (!cur->arr[index])
        {
            return "not found";
        }
        else
        {
            cur = cur->arr[index];
        }
    }

    if (cur->finish == true)
    {
        return "Found word " + s;
    }
    else
    {
        return "found substring";
    }
}

int main()
{
    TrieNode *Trie = new TrieNode();

    insert(Trie->head, 0, "helloworld");


    cout << findTrie(Trie->head, "hell") << endl;
    cout << findTrie(Trie->head, "bob") << endl;
    cout << findTrie(Trie->head, "helloworld") << endl;
    return 0;
}