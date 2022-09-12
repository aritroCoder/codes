#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createnode(int val)
{
    node *root = new node;
    root->data = val;
    root->left = NULL;
    root->right = NULL;
}

void search(node *&curr, int val, node *&parent)
{
    while (curr != NULL || curr->data != val)
    {
        parent = curr;
        if (curr->data < val)
        {
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
}

node *findmin(node *root)
{
    if (root->left == NULL)
        return root;
    else
        return findmin(root->left);
}

node *insert(node *root, int val)
{
    if (root == NULL)
        return createnode(val);
    if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    else
        root->left = insert(root->left, val);
}

void deleted(node *root, int val)
{
    node *curr = root;
    node *parent = NULL;
    search(curr, val, parent);
    if (curr == NULL)
        return;
    if (curr->left == NULL && curr->right == NULL) // leaf node
    {
        if (curr == root)  // function called using leaf node
            root = NULL;
        else
        {
            if (parent->left == curr)
            {
                parent->left = NULL;
            }
            else
                parent->right = NULL;
        }
        free(curr);
    }
    else if (curr->left != NULL && curr->right != NULL) // double child node
    {
        node *suc = findmin(curr->right);
        int data = suc->data;
        deleted(suc, data);
        curr->data = data;
        // free(curr);
    }

    else  // single child node
    {
        node *curr_child = (curr->right == NULL) ? curr->left : curr->right;
        if (parent->right == curr)
        {
            parent->right = curr_child;
        }
        else
            parent->left = curr_child;
        free(curr);
    }
}

int main()
{
    int val;
    cin >> val;
    node *root = NULL;
    root = insert(root, val);
    node *temp = root;
    node *parent = NULL;
    search(temp, val, parent);

    return 0;
}