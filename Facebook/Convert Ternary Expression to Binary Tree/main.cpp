#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
    freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}

Node *convertExpression(string str,int i) {

    if (i >= str.size())
        return NULL;

    Node *root = new Node(str[i]);

    if (i+1 < str.size() && str[i+1] == '?') {
        root ->left = convertExpression(str, i+2);
    }
    if (i+1 < str.size () && str[i+1] == ':') {
        root -> right = convertExpression (str, i+2);
    }
    return root;
}
