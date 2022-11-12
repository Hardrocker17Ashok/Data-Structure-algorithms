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

//   check both tree is identical
bool check_Identical(binary *node1, binary *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    else if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = node1->data == node2->data;
        bool cond2 = check_Identical(node1->left, node2->left);
        bool cond3 = check_Identical(node1->right, node2->right);
        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
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
    binary *p2 = nullptr;

    // generating first binary tree
    p1 = built_binary_tree(p1, 70);
    built_binary_tree(p1, 20);
    built_binary_tree(p1, 80);
    built_binary_tree(p1, 10);
    built_binary_tree(p1, 30);
    built_binary_tree(p1, 100);
    built_binary_tree(p1, 90);
    built_binary_tree(p1, 80);

    // generating second binary tree
    p2 = built_binary_tree(p2, 70);
    built_binary_tree(p2, 20);
    built_binary_tree(p2, 80);
    built_binary_tree(p2, 10);
    built_binary_tree(p2, 30);
    built_binary_tree(p2, 1);
    built_binary_tree(p2, 90);
    built_binary_tree(p2, 80);

    cout << "this is inorder of genreating first tree " << endl;
    inorder(p1);
    cout << endl
         << "this is inorder of genreating second tree " << endl;
    inorder(p2);
    cout << endl;
    if (check_Identical(p1, p2))
    {
        cout << "yes both binary search tree is identical" << endl;
    }
    else
    {
        cout << "Not both binary search tree is Not identical" << endl;
    }
    return 0;
}