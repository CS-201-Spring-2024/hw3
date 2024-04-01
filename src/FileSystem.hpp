#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;


struct FileSystemEntry {
    string Filename;
    int Size;
    string createdOn;
    string modifiedOn;
    string Type;
    string path;

};

class FileSystem {

public:



vector<FileSystemEntry> entries;

void load_files_from_csv(const string& csv_file);
string parse_timestamp(const string& timestampStr);



void print_file_entry();

};