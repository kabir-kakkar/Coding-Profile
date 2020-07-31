#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef struct node Node;

struct node
{
    long int data;
    int pos;
    Node *left, *right;
};

Node* insert_number (Node *root, long int num, int pos)
{
    if (root == NULL)
    {
        cout << pos << "\n";
        Node *new_node = new node();
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->data = num;

        new_node->pos = pos;

        return new_node;
    }

    if (root->data > num)
    {
        root->left = insert_number (root->left, num, 2*pos);
    }

    else
    {
        root->right = insert_number (root->right, num, 2*pos + 1);
    }

    return root;
};

Node* delete_number (Node* root, long int data)
{
    if (!root)
    {
        return root;
    }
    if (root->data > data)
    {
        root->left = delete_number (root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete_number (root->right, data);
    }
    else if (root->data == data)
    {
        Node* temp;
        cout << root->pos << "\n";

        if (root->left == NULL && root->right == NULL)
        {
            free (root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            temp = root->right;
            free (root);
            return temp;
        }

        else if (root->right == NULL)
        {
            temp = root->left;
            free (root);
            return temp;
        }

        else
        {
            temp = root->right;
            while (temp && temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_number (root->right, temp->data);
            return root;
        }
    }
    return root;
}

int main()
{
    int cases;
    cin >> cases;

    char option;
    long int num;

    Node *root = NULL;
    while (cases--)
    {
        cin >> option >> num;
        if (option == 'i')
        {
            root = insert_number (root, num, 1);
        }
        else if (option == 'd')
        {
            root = delete_number (root, num);
        }
    }
}
