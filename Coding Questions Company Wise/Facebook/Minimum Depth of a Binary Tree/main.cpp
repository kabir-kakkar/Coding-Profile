#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode (int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


/*You are required to complete this method*/
int minDepth(Node *root) {
    // Your code here
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    if (!root->left){
        return minDepth(root->right) + 1;
    }

    if (!root -> right) {
        return minDepth (root->left) + 1;
    }

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


Node* buildTree (string str) {

    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode -> left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }

        i++;
    }
    return root;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);

        cout << minDepth(root) << endl;
    }
    return 0;
}