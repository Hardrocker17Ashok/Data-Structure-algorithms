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
// calculate height in tree
int calculate_height(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_height = calculate_height(node->left);
    int right_height = calculate_height(node->right);
    return max(left_height, right_height) + 1;
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

    int to = calculate_height(p1);
    cout << "the totle level in tree is = " << to << endl;
    return 0;
}