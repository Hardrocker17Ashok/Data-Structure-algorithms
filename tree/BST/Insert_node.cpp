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

// it use o(log n) time complexity
binary *Insert_node(binary *node, int number)
{
    if (node == nullptr)
    {
        binary *p = new binary(number);
        return p;
    }
    else if (number < node->data)
    {
        node->left = Insert_node(node->left, number);
    }
    else
    {
        node->right = Insert_node(node->right, number);
    }
    return node;
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
    built_binary_tree(p1, 75);

    cout << "before inserting" << endl;
    inorder(p1);
    Insert_node(p1, 65);
    cout << endl
         << "after inserting" << endl;
    inorder(p1);
    return 0;
}