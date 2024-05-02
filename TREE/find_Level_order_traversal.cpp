#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // create the construte
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// create the function
Node *buildTree(int data)
{
    // 1-data indicates that we have arrived at the leaf node & hence return NULL.
    // depands on the question
    if (data == -1)
    {
        return NULL;
    }
    // create root node(solve one case )
    Node *root = new Node(data);

    // recussion handle for left & right subtree
    int leftData;

    cout << "Enter data of left of" << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    int rightData;
    cout << "Enter data right of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    return root;
}
Node *buildoflevelOder(Node *root)
{
    queue<Node *> q;
    cout << "Enter data a data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->left);
        }
    }
}
int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);

    buildoflevelOder(root);
    return 0;
}