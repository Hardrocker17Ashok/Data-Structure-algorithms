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

int cal_dis(binary *node, int k, int dist)
{
    if (node == NULL)
    {
        return -1;
    }
    if (node->data == k)
    {
        return dist;
    }
    int left = cal_dis(node->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    else
    {
        return cal_dis(node->right, k, dist + 1);
    }
}
binary *LCA(binary *node, int n1, int n2)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == n1 || node->data == n2)
    {
        return node;
    }
    binary *left = LCA(node->left, n1, n2);
    binary *right = LCA(node->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return node;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(node->left, n1, n2);
    }
    return LCA(node->right, n1, n2);
}

int find_distance(binary *node, int n1, int n2)
{
    binary *lca = LCA(node, n1, n2);
    int d1 = cal_dis(lca, n1, 0);
    int d2 = cal_dis(lca, n2, 0);
    return d1 + d2;
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

    // difference means how many egas between given two node
    cout << "difference of two node is " << endl;
    cout << find_distance(p1, 40, 30);
    return 0;
}