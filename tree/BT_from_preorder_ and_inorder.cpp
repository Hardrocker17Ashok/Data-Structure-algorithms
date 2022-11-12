#include <iostream>
using namespace std;
// int ind=0;
class binary
{
public:
    int data;
    binary *left;
    binary *right;
    binary(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search_pos(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
binary *built_tree(int preorder[], int inorder[], int start, int end)
{
static int ind = 0;
    if (start > end)
    {
        return NULL;
    }   
    int curr = preorder[ind];
    ind++;
    binary *node = new binary(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search_pos(inorder, start, end, curr);
    node->left = built_tree(preorder, inorder, start, pos - 1);
    node->right = built_tree(preorder, inorder, pos + 1, end);
    return node;
}
void print_inorder(binary *node)
{
    if (node == NULL)
    {
        return;
    }
    print_inorder(node->left);
    cout << node->data << " ";
    print_inorder(node->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    int start=0;
    int end=4;
    binary*head=NULL;
    head = built_tree(preorder, inorder, start, end);
    print_inorder(head);
    return 0;
}