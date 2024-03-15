#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
#include "FileSystem.hpp"
#include "BST.hpp"
#include "AVL.hpp"
#include "FileExplorer.hpp"
using namespace std;


int main() {
    FileSystem fs;
    fs.LoadFilesFromCsv("input/Sample.csv");
    fs.PrintFileEntry();
    return 0;
}
