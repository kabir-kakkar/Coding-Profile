#include <stdio.h>
#include <stdlib.h>

typedef struct NODE node;
int arr[100], s=0, size;
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
    ++size;
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

void inOrder (node *root)
{
    if (root == NULL)
        return;
    inOrder (root->left);
    printf ("%d -> ", root->data);
    arr[s++] = root->data;
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
    printf("\n");

    int m;
    scanf("%d", &m);

    printf("%d %d", arr[m-1], size);
}
