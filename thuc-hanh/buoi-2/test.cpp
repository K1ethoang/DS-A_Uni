#include <iostream>
#include <cmath>
using namespace std;

struct Item
{
    int key;
    float value;
};

struct Node
{
    Item data;
    Node *left;
    Node *right;

    Node()
    {
        data.key = -1;
        data.value = -1;
        left = right = NULL;
    }

    Node(const int &_key)
    {
        data.key = _key;
        data.value = sqrt(_key);
        left = right = NULL;
    }
};

void createBST(Node *&root);
void add(Node *&root, const int &key);
void display(Node *root);
int sumInLeaf(Node *root);
float searchValue(Node *root, const int &key);

int main()
{
    int a[100];
    int n;
    do
    {
        cout << "\nNhap so phan tu cua mang: ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "\n\tNhap lai\n";
    } while (n < 1 || n > 100);
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "\n\t\t\tMang vua nhap\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // BST
    Node *root = new Node();
    createBST(root);
    for (int i = 0; i < n; i++)
        add(root, a[i]);
    cout << "\n\n\t\tGia tri cua mang vua nhap vao cay nhi phan tim kiem\n";
    cout << "\nKey"
         << " Value" << endl;
    display(root);
    cout << "\n\n\tTong cac khoa o nut la: " << sumInLeaf(root);
    cout << endl;
    int key;
    cout << "\n\tNhap so nguyen x de tim can ban 2: ";
    cin >> key;
    float value = searchValue(root, key);
    if (value == 0)
        cout << "\n\t\tKhong co can bac 2 cua so nguyen " << key << endl;
    else
        cout << "\n\n\tCan bac 2 cua so nguyen " << key << " la: " << value;
    delete root;
    return 0;
}

void createBST(Node *&root)
{
    root = NULL;
}

void add(Node *&root, const int &key)
{
    if (root == NULL)
    {
        Node *p = new Node(key);
        root = p;
    }
    else
    {
        if (key < root->data.key)
            add(root->left, key);
        else if (key > root->data.key)
            add(root->right, key);
    }
}

void display(Node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << root->data.key << " : " << root->data.value << endl;
        display(root->right);
    }
}

int sumInLeaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data.key;
    return sumInLeaf(root->left) + sumInLeaf(root->right);
}

float searchValue(Node *root, const int &key)
{
    if (root == NULL)
        return 0;
    else
    {
        if (key > root->data.key)
            return searchValue(root->right, key);
        else if (key < root->data.key)
            return searchValue(root->left, key);
        return root->data.value;
    }
}