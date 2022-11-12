// we can generate a tree
#include <iostream>
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
void print(binary *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        print(node->left);
        print(node->right);
    }
}
int sum_nodes(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return sum_nodes(node->left) + sum_nodes(node->right) + node->data;
}
int main()
{
    binary *p1, *p2, *p3, *p4, *p5, *p6, *p7;
    // generating node of tree
    p1 = genrate_node(1);
    p2 = genrate_node(2);
    p3 = genrate_node(3);
    p4 = genrate_node(4);
    p5 = genrate_node(5);
    p6 = genrate_node(6);
    p7 = genrate_node(7);
    // creating a tree by genrating node
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;
    // its degined as below
    /*
           10
           /\
          /  \
         20  30
       /\     /\
      /  \   /  \
     40  50 60  70
    */
    print(p1);
    cout << endl;
    int val = sum_nodes(p1);
    cout << "the sum of all nodes in tree = " << val << endl;
    return 0;
}