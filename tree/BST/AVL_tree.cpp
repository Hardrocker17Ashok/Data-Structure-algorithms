// we can generate a tree
#include <bits/stdc++.h>
using namespace std;
class binary
{
public:
    int key, height;
    binary *left;
    binary *right;

    binary(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// find max value
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// find height
int height(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// work on leftrotation
binary *left_rotate(binary *x)
{
    binary *y = x->right;
    binary *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// work on rightrotation
binary *right_rotate(binary *y)
{
    binary *x = y->left;
    binary *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// find balance as well as
int get_balence(binary *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// insert any element with balencing
binary *insert(binary *node, int key)
{
    if (node == NULL)
    {
        binary *p = new binary(key);
        return p;
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balence = get_balence(node);

    if (balence > 1 && key < node->left->key)
    {
        return right_rotate(node);
    }
    if (balence < -1 && key > node->right->key)
    {
        return left_rotate(node);
    }
    if (balence > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balence < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}
void preorder(binary *node)
{
    if (node != NULL)
    {
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

int main()
{
    binary *p1 = NULL;
    // generating node of tree
    p1 = insert(p1, 10);
    p1 = insert(p1, 20);
    p1 = insert(p1, 30);
    p1 = insert(p1, 40);
    p1 = insert(p1, 50);
    p1 = insert(p1, 60);
    p1 = insert(p1, 70);

    // this tree will be as binary tree form
    /*
    10
       \
        20
         \
          30
           \
            40            it's preorder => 10-20-30-40-50-60-70
             \            But this is not a balencing BST
              50
               \
                60
                 \
                  70
    */
    //  And after change in AVL tree it's wiil be balencing
    //  And preorder will be 40-20-10-30-60-50-70
    cout << "this is preorder of creating AVL tree " << endl;
    preorder(p1);
    return 0;
}