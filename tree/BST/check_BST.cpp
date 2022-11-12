// we can generate a binary tree
#include <iostream>
using namespace std;
class binary
{
public:
    int data;
    binary *left;
    binary *right;

    binary(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
binary *built_binary_tree(binary *node, int num)
{
    if (node == nullptr)
    {
        binary *sp = new binary(num);
        return sp;
    }
    if (num < node->data)
    {
        node->left = built_binary_tree(node->left, num);
    }
    else
    {
        node->right = built_binary_tree(node->right, num);
    }
    return node;
}

bool check_BST(binary *node)
{
    if (node == NULL)
    {
        return true;
    }
    if (node->left != NULL && node->left->data > node->data)
    {
        return false;
    }
    if (node->right != NULL && node->right->data < node->data)
    {
        return false;
    }
    if (check_BST(node->left))
    {
        return true;
    }
    if (check_BST(node->right))
    {
        return true;
    }
    return false;
}
void inorder(binary *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}
int main()
{
    binary *p1 = nullptr;

    // generating a binary tree
    p1 = built_binary_tree(p1, 70);
    built_binary_tree(p1, 20);
    built_binary_tree(p1, 80);
    built_binary_tree(p1, 10);
    built_binary_tree(p1, 30);
    built_binary_tree(p1, 100);
    built_binary_tree(p1, 90);
    built_binary_tree(p1, 80);

    cout << "this is inorder of genreating tree " << endl;
    inorder(p1);
    cout << endl;
    if (check_BST(p1))
    {
        cout << "yes this is binary search tree" << endl;
    }
    else
    {
        cout << "no this is not binary search trree" << endl;
    }
    return 0;
}