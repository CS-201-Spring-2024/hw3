#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

struct FileSystemEntry
{
    string Filename;
    int Size;
    string accessedOn;
    string modifiedOn;
    string Type;
    string path;
};

class FileSystem
{

public:
    vector<FileSystemEntry> entries;

    void LoadFilesFromCsv(const string &csv_file);
    string ParseTimestamp(const string &timestampStr);
    void PrintFileEntry();
};