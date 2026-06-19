#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* n = new Node();
    n->data = x;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insert(Node* root, int x)
{
    if (!root)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        cout << "Duplicate value " << x << " not inserted\n";

    return root;
}

Node* findMin(Node* root)
{
    while (root->left)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int x)
{
    if (!root)
    {
        cout << "Value " << x << " not found in tree\n";
        return nullptr;
    }

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (!root->left)
        {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (!root->right)
        {
            Node* t = root->left;
            delete root;
            return t;
        }
        else
        {
            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    return root;
}

bool search(Node* root, int x)
{
    if (!root)
        return false;

    if (x == root->data)
        return true;
    else if (x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

void inorder(Node* n)
{
    if (!n) return;
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}

void preorder(Node* n)
{
    if (!n) return;
    cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

void postorder(Node* n)
{
    if (!n) return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << " ";
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 5); // duplicate

    cout << "Inorder:   "; inorder(root);   cout << "\n";
    cout << "Preorder:  "; preorder(root);  cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";

    cout << "Search 4: " << (search(root, 4) ? "Found" : "Not Found") << "\n";
    cout << "Search 8: " << (search(root, 8) ? "Found" : "Not Found") << "\n";

    root = deleteNode(root, 3);
    cout << "After deleting 3 - Inorder: "; inorder(root); cout << "\n";

    root = deleteNode(root, 99); // not found
    return 0;
}
