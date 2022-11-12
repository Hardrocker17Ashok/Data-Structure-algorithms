#include <bits/stdc++.h>
using namespace std;
class binary
{
public:
    int data;
    binary *left;
    binary *right;
};
class info
{
public:
    int ans;
    int size;
    int mmin;
    int mmax;
    bool isbst;
};
binary *genrate_node(int val)
{
    binary *n1 = new binary();
    n1->data = val;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}

info Find_largest_BST(binary *node)
{
    if (node == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (node->left == NULL && node->right == NULL)
    {
        return {1, node->data, node->data, 1, true};
    }
    info leftinfo = Find_largest_BST(node->left);
    info rightinfo = Find_largest_BST(node->right);
    info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);
    if (leftinfo.isbst && rightinfo.isbst && leftinfo.mmax < node->data && rightinfo.mmin > node->data)
    {
        curr.mmin = min(leftinfo.mmin, node->data);
        curr.mmax = max(rightinfo.mmax, node->data);
        curr.ans = leftinfo.ans + rightinfo.ans + 1;
        curr.isbst = true;
        return curr;
    }
    else
    {
        curr.ans = max(leftinfo.ans, rightinfo.ans);
        curr.isbst = false;
        return curr;
    }
}
int main()
{
    binary *p1, *p2, *p3, *p4, *p5, *p6, *p7;
    // generating node of tree
    p1 = genrate_node(10);
    p2 = genrate_node(20);
    p3 = genrate_node(30);
    p4 = genrate_node(10);
    p5 = genrate_node(25);
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
     10  25 60  70
    */
    cout << "the largest BST size thats available in this tree is = " << Find_largest_BST(p1).ans << endl;
    return 0;
}