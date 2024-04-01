#pragma once
#include "BST.hpp"

class AVLIndex : public BSTIndex
{
public:
    // Class methods
    AVLIndex() : BSTIndex() {
        std::cout << "AVLIndex constructor" << std::endl;
    }
    virtual ~AVLIndex() {
        std::cout << "AVLIndex destructor" << std::endl;
    }
    void add(int i, string key) override;
    // Helper functions
    TreeNode *rebalance(TreeNode *node, string key);
    TreeNode *rotateRight(TreeNode *y);
    TreeNode *rotateLeft(TreeNode *y);
    int getBalance(TreeNode *node);
    TreeNode *_add(TreeNode *node, int i, string key) override;
};
