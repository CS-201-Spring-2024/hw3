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
    BSTIndex *nameIndex;
    BSTIndex *dateIndex;
    FileSystem *fs;

public:
    FileExplorer(string type, string csv_file);
    void FindByName(string filename, string output_path);
    void FindByDate(string date, string output_path);
    void FindByNameAndDate(string filename, string date, string output_path);
    void FindByNameAndSize(string filename, int size, string output_path);
    void FindFilesCreatedDuring(string date1, string date2, string output_path);
    ~FileExplorer();
};
