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
int minimum_val(binary *node)
{
    int min = node->data;
    while (node->left != nullptr)
    {
        min = node->left->data;
        node = node->left;
    }
    return min;
}

binary *delete_node(binary *node, int key)
{
    if (node == NULL)
    {
        return node;
    }
    if (key < node->data)
    {
        return delete_node(node->left, key);
    }
    else if (key > node->data)
    {
        return delete_node(node->right, key);
    }
    else
    {
        if (node->left == nullptr)
        {
            return node->right;
        }
        else if (node->right == nullptr)
        {
            return node->left;
        }
        else
        {
            node->data = minimum_val(node->right);
            node->right = delete_node(node->right, node->data);
        }
    }
    return node;
}

void inorder(binary *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
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

    // recrsive method
    // if(Searching(p1,1)!=nullptr){
    //     cout<<"yes the element is available in this tree"<<endl;
    // }
    // else{
    //     cout<<"not the element is not available in this tree"<<endl;
    // }

    // itrative method
    cout << "before deleting element from this tree" << endl;
    inorder(p1);
    delete_node(p1, 20);
    cout << endl
         << "after deleting element from this tree" << endl;
    inorder(p1);
    return 0;
}