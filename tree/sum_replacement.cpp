// we can generate a tree
#include <iostream>
#include <queue>
using namespace std;
class binary
{
public:
    int data;
    binary *left;
    binary *right;
};
binary *genrate_node(int val)
{
    binary *n1 = new binary();
    n1->data = val;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}
// sum replacement of tree
void sum_and_replacement(binary *node)
{
    if (node == NULL)
    {
        return;
    }
    sum_and_replacement(node->left);
    sum_and_replacement(node->right);
    if (node->left != NULL)
    {
        node->data += node->left->data;
    }
    if (node->right != NULL)
    {
        node->data += node->right->data;
    }
}
void preorder(binary *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
int main()
{
    binary *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11;
    // generating node of tree
    p1 = genrate_node(1);
    p2 = genrate_node(2);
    p3 = genrate_node(3);
    p4 = genrate_node(4);
    p5 = genrate_node(5);
    p6 = genrate_node(6);
    p7 = genrate_node(7);
    p8 = genrate_node(8);
    p9 = genrate_node(9);
    p10 = genrate_node(10);
    p11 = genrate_node(11);
    // creating a tree by genrating node
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    p4->left = p8;
    p4->right = p9;

    p5->left = p10;
    p5->right = p11;

    cout << "preorder of actual tree" << endl;
    preorder(p1);
    cout << endl
         << "preorder of tree after replacement with sum " << endl;
    sum_and_replacement(p1);
    preorder(p1);
    return 0;
}