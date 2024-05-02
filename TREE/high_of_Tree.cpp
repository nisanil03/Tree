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
int hightofTree(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0; // 0 is height of empty tree
    }
    // left subtree height
    int leftHeight = hightofTree(root->left);

    // right subtree height
    int rightHeight = hightofTree(root->right);

    // max of both the height of tree
    int ans = max(leftHeight,rightHeight) + 1;

    // hight should be returned
    return ans;
}
int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);

    cout << "Height of Binary Tree = " << hightofTree(root) << endl;
    //hightofTree(root);
    return 0;
}