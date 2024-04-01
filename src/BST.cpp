#include "BST.hpp"

void BSTIndex::createIndex(vector<FileSystemEntry> &data, string indexType)
{
    
    int size = static_cast<int>(data.size());
    for (int i = 0; i < size ; i++)
    {
        if (indexType == "Filename")
        {
            add(i, data[i].Filename);
        }

        else if (indexType == "Date") {
            add(i, data[i].createdOn);
        
        }
        if (i % 1000 == 0)
            std::cout << "Processed " << i << " records" << std::endl;
    }
   
};

void BSTIndex::add(int i, string key)
{
    root = _add(root, i, key);
}

TreeNode *BSTIndex::_add(TreeNode *node, int i, string key)
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

   

    updateHeight(node);
    return node;
}

void BSTIndex::print()
{
    _print(root);
}

void BSTIndex::_print(TreeNode *node)
{
    if (node)
    {
        _print(node->left);
        cout << node->key << " : " << node->height << endl;
        _print(node->right);
    }
}

int BSTIndex::getHeight(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

void BSTIndex::updateHeight(TreeNode *node)
{
    if (node == nullptr)
        return;
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

std::pair<std::vector<int>, int> BSTIndex::search(string key)
{

    int nodes_traversed = 0;
    std::vector<int> records_found;
    _search(root, key, nodes_traversed, records_found);
    return std::make_pair(records_found, nodes_traversed);
}

void BSTIndex::_search(TreeNode *node, const std::string &key, int &nodes_traversed, std::vector<int> &records_found)
{
    if (node == nullptr)
        return;

    nodes_traversed++; // Increment nodes traversed for each node visited

    if (node->key == key)
    {
        for (const auto &record : node->index)
        {
            records_found.push_back(record); // Store the records found
        }
        return;
    }
    else if (key < node->key)
    {
        _search(node->left, key, nodes_traversed, records_found);
    }
    else
    {
        _search(node->right, key, nodes_traversed, records_found);
    }
}