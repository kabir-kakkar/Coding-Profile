#include<bits/stdc++.h>
#define N 12
using namespace std;

/* A tree node structure */
struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *middle;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data){
    struct node *temp = new struct node;

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->middle = NULL;

    return temp;
}

int dfs(node *root, int &c){
    if(!root)
       return 0;
    int l=dfs(root->left,c);
    int m=dfs(root->middle,c);
    int r=dfs(root->right,c);

    if( (l+m+r+1)%2==0 ){
        ++c;
        return 0;
    }
    return l+m+r+1;
}

/* Driver function to test above functions */
int main() {
    struct node *root = NULL;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(1);
    root->left = newNode(2);
    root->middle = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->middle->left = newNode(6);
    root->right->left = newNode(7);
    root->right->middle = newNode(8);
    root->left->left->left = newNode(9);
    root->left->left->middle = newNode(10);

    int c=0;
    dfs(root,c);

    // c-1 edges can be removed to create c trees
    cout<<c-1<<endl;
}
