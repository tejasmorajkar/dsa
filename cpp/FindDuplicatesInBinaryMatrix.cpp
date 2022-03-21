#include <iostream>
#include <vector>

using namespace std;

struct Trie
{
    bool is_leaf;
    Trie *children[2];
};

Trie *create_new_node()
{
    Trie *node = new Trie;
    node.is_leaf = false;
    node.children[0] = node.children[1] = NULL;
    return node;
}

bool insert(Trie *head, vector<int> row)
{
    Trie *current = head;
    for (int i = 0; i < row.size(); i++)
    {
        if (current->children[row[i]] == NULL)
            current->children[row[i]] = create_new_node();

        current = current->children[row[i]];
    }
    if (current->is_leaf)
        return false;
    return current->is_leaf = true;
}

vector<int> solve(vector<vector<int>> &A)
{
    Trie *head = create_new_node();
    vector<int> result;
    for (int i = 0; i < A.size(); i++)
    {
        if (!insert(head, A[i]))
            result.push_back(i+1);
    }
    return result;
}

int main()
{
    vector<vector<int>> A{
        {1, 0, 0},
        {0, 1, 0},
        {0, 1, 0}};

    vector<int> result = solve(A);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    cout << endl;
    return 0;
}