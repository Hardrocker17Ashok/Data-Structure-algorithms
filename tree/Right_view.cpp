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
void right_view(binary *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<binary *> qu;
    qu.push(node);
    while (!qu.empty())
    {
        int num = qu.size();
        for (int i = 0; i < num; i++)
        {
            binary *head = qu.front();
            qu.pop();

            if (i == num - 1)
            {
                cout << head->data << " ";
            }
            if (head->left != NULL)
            {
                qu.push(head->left);
            }
            if (head->right != NULL)
            {
                qu.push(head->right);
            }
        }
    }
}
// preorder displaying
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
    binary *p1, *p2, *p3, *p4, *p5, *p6;
    // generating node of tree
    p1 = genrate_node(10);
    p2 = genrate_node(20);
    p3 = genrate_node(30);
    p4 = genrate_node(40);
    p5 = genrate_node(50);
    p6 = genrate_node(60);
    // creating a tree by genrating node
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    // its degined as below
    /*
           10
           /\
          /  \
         20  30
       /\     /
      /  \   /
     40  50 60
    */

    cout << "The tree in inorder" << endl;
    inorder(p1);
    cout<<endl;
    cout << "the node that visible from right side" << endl;
    right_view(p1);

    return 0;
}