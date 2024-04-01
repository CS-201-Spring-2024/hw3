#include "AVL.hpp"

int AVLIndex::getBalance(TreeNode *node)
{
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode *AVLIndex::rebalance(TreeNode *node, string key)
{
    if (!node)
        return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

TreeNode *AVLIndex::rotateRight(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode *AVLIndex::rotateLeft(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

void AVLIndex::add(int i, string key)
{

    root = _add(root, i, key);
}

TreeNode *AVLIndex::_add(TreeNode *node, int i, string key)
{
    if (!node)
    {
        TreeNode *new_node = new TreeNode(key, i);
        this->total_nodes_count++;
        return new_node;
    }

    if (key < node->key)
    {

        node->left = _add(node->left, i, key);
    }
    else if (key > node->key)
    {

        node->right = _add(node->right, i, key);
    }
    else
        node->index.push_back(i);

    return rebalance(node, key);
}
