#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include "FileSystem.hpp"
#include "AVL.hpp"
#include "BST.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

class FileExplorer
{
private:
    BSTIndex *NameIndex;
    BSTIndex *DateIndex;
    FileSystem *fs;

public:
    FileExplorer(const string &type, const string &csv_file);
    void FindByName(const string &filename, const string &output_path);
    void FindByDate(const string &date, const string &output_path);
    void FindByNameAndDate(const string &filename, const string &date, const string &output_path);
    void FindByNameAndSize(const string &filename, const int size, const string &output_path);
    void FindFilesCreatedDuring(const string &date1, const string &date2, const string &output_path);
    ~FileExplorer();
};
