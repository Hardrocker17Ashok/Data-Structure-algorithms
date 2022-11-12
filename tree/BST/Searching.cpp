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
// itrative method
binary *Searching(binary *node, int key)
{
    if (node == NULL)
    {
        return nullptr;
    }
    if (node->data == key)
    {
        return node;
    }
    else if (key < node->data)
    {
        return Searching(node->left, key);
    }
    else
    {
        return Searching(node->right, key);
    }
}

// searching irative way
bool itretive(binary *node, int key)
{
    while (node != NULL)
    {
        if (node->data == key)
        {
            return true;
        }
        else if (node->data > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
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
    if (itretive(p1, 200))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}