#include <bits/stdc++.h>
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
int height(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh, rh) + 1;
}

// its take o(n^n) time complexity
bool balance(binary *node)
{
    if (node == NULL)
    {
        return true;
    }
    if (balance(node->left) == false)
    {
        return false;
    }
    if (balance(node->right) == false)
    {
        return false;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// its take o(n) time complexity
bool balance1(binary *node, int *height)
{
    if (node == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (balance1(node->left, &lh) == false)
    {
        return false;
    }
    if (balance1(node->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    binary *p1, *p2, *p3, *p4, *p5, *p6, *p7;
    // generating node of tree
    p1 = genrate_node(10);
    p2 = genrate_node(20);
    p3 = genrate_node(30);
    p4 = genrate_node(40);
    p5 = genrate_node(50);
    p6 = genrate_node(60);
    p7 = genrate_node(70);
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

    /*
    balance tree=>  1>       when difference between all node of left and all node of right are 1 and less than 1
                             than it's call balance tree other wise call non balance tree
    */

    //   this is function take o(n^n) time complexity
    // if (balance(p1))
    // {
    //     cout << "yes it's binary tree" << endl;
    // }
    // else
    // {
    //     cout << "Not it's not binary tree" << endl;
    // }

    // now this function take o(n) time complexity
    int height = 0;
    if (balance1(p1, &height))
    {
        cout << "yes it's binary tree" << endl;
    }
    else
    {
        cout << "Not it's not binary tree" << endl;
    }
    return 0;
}