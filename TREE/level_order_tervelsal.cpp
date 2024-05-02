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
// Normal Level order traversal
/*
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;

    // Push the root in queue
    q.push(root);

    // Run the loop until queue becomes empty

    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        // left child exists
        if (temp->left)
        {
            q.push(temp->left);
        }

        // right child exists
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
*/
// to print the tree lavel wise 
void levelOrderTraversal(Node *root)
{
    // empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;

    // push root node in the queue
    q.push(root);
    q.push(NULL); // sapreater k liye

    // run loop until queue does not become empty
    while (!q.empty())
    {
        // fetch front element
        Node *temp = q.front();
        q.pop();
        //cout << temp->data << " ";

        if (temp = NULL)
        { // PURANA LAVEL COMPLETE HO CHUKA HAI
            cout << endl;

            if (!q.empty())
            { // queue staill has child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exit or not
            if (temp->left)
            {
                // push left child
                q.push(temp->left);
            }

            // right child exit or not
            if (temp->right)
            {
                // push right child
                q.push(temp->right);
            }
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

    cout << "Level order traversal is as follows" << endl;
    levelOrderTraversal(root);

    return 0;
}