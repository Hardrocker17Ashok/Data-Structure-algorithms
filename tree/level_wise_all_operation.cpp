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

// print tree with level wise
void print_node_level_wise(binary *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<binary *> q;
    q.push(node);
    q.push(NULL);
    while (!q.empty())
    {
        binary *p = q.front();
        q.pop();
        if (p != NULL)
        {
            cout << p->data << " ";
            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

// print some of same level_node in tree
int sum_of_given_Kth_level(binary *node, int k)
{
    if (node == NULL)
    {
        return -1;
    }
    queue<binary *> q1;
    q1.push(node);
    q1.push(NULL);
    int level = 0, sum = 0;
    while (!q1.empty())
    {
        binary *p1 = q1.front();
        q1.pop();
        if (p1 != NULL)
        {
            if (level == k)
            {
                sum += p1->data;
            }
            if (p1->left)
            {
                q1.push(p1->left);
            }
            if (p1->right)
            {
                q1.push(p1->right);
            }
        }
        else if (!q1.empty())
        {
            q1.push(NULL);
            level++;
        }
    }
    return sum;
}

// count totle node in tree
int count_level(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_height = count_level(node->left);
    int right_height = count_level(node->right);
    return max(left_height, right_height) + 1;
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

    cout << "print all tree node with level wise" << endl;
    print_node_level_wise(p1);
    cout << endl;
    int val = sum_of_given_Kth_level(p1, 2);
    cout << "the sum of given level nodes in tree = " << val << endl;
    int to = count_level(p1);
    cout << "the totle level in tree is = " << to << endl;
    return 0;
}