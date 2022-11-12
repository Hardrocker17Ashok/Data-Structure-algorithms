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
        left = nullptr;
        right = nullptr;
    }
};
binary *built_BST_from_sorted_array(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    binary *root = new binary(arr[mid]);

    root->left = built_BST_from_sorted_array(arr, start, mid - 1);
    root->right = built_BST_from_sorted_array(arr, mid + 1, end);
    return root;
}
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
    int arr[] = {10, 20, 30, 40, 50};
    binary *root = built_BST_from_sorted_array(arr, 0, 4);
    cout << "this is inorder of genreating tree " << endl;
    inorder(root);
    return 0;
}