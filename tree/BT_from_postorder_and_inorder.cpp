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
binary *built_tree(int postrder[], int inorder[], int start, int end)
{
static int ind = end;
    if (start > end)
    {
        return NULL;
    }   
    int curr = postrder[ind];
    ind--;
    binary *node = new binary(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search_pos(inorder, start, end, curr);
    node->right = built_tree(postrder, inorder, pos + 1, end);
    node->left = built_tree(postrder, inorder, start, pos - 1);
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
    int postrder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    int start=0;
    int end=4;
    binary*head=NULL;
    head = built_tree(postrder, inorder, start, end);
    print_inorder(head);
    return 0;
}