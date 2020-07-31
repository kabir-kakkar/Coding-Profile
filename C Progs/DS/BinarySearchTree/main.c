#include <stdio.h>
#include <stdlib.h>

typedef struct NODE node;

struct NODE
{
    int data;
    node *left;
    node *right;
};

node *createNode (int data)
{
    node* newNode = malloc (sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

node *insert (node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert (root->left, data);
    else if (data > root->data)
        root->right = insert (root->right, data);

    return root;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
node * minValueNode(node* root)
{
    node* current = root;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
node* deleteNode(node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->data)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->left == NULL)
		{
            node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
        node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}


void inOrder (node *root)
{
    if (root == NULL)
        return;
    inOrder (root->left);
    printf ("%d -> ", root->data);
    inOrder (root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    inOrder(root);

    root = deleteNode (root, 3);
    printf("\n");
    inOrder(root);
}
