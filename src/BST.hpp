#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "FileSystem.hpp"

struct TreeNode
{
    string key;
    vector<int> index; 
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(string k, int i) : key(k), left(nullptr), right(nullptr), height(1)
    {
        index.push_back(i);
    }
};

class BSTIndex
{
protected:
    TreeNode *root;
    int total_nodes_count;

public:
    BSTIndex() : root(nullptr), total_nodes_count(0) {
        std::cout << "BSTIndex constructor" << std::endl;
    }
    virtual ~BSTIndex() {
        std::cout << "BSTIndex destructor" << std::endl;
    }
    // Class methods
    void createIndex(vector<FileSystemEntry> &data, string key);
    virtual void add(int i, string key);
    std::pair<std::vector<int>, int> search(string key);
    
    // Helper functions
    virtual TreeNode* _add(TreeNode *node, int i, string key);
    void _print(TreeNode *node);
    
    void _search(TreeNode* node, const std::string& key, int& nodes_traversed, std::vector<int>& records_found);
    void updateHeight(TreeNode *node);
    int getHeight(TreeNode *node);
    int getRootHeight() {
        return getHeight(root);
    }

    int getTotalNodesCount() {
        return total_nodes_count;
    }
    void print();
};
