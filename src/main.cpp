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

void FindByName(const string &index, const string &filename, const string &output_path, const string &key) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByName(key, output_path);
    delete fe;
}
void FindByDate(const string &index, const string &filename, const string &output_path, const string &date) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByDate(date, output_path);
    delete fe;
}

void FindByNameAndDate(const string &index, const string &filename,const string &output_path,const string&key, const string& date) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByNameAndDate(key, date, output_path);
    delete fe;
}
void FindByNameAndSize(const string &index, const string &filename,const string &output_path,const string&key, int size) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindByNameAndSize(key, size, output_path);
    delete fe;
}

void FindFilesCreatedDuring(const string &index, const string &filename,const string &output_path,const string&date1, const string& date2) {
    FileExplorer *fe = new FileExplorer(index, filename);
    fe->FindFilesCreatedDuring(date1, date2, output_path);
    delete fe;
}
int main()
{
    
    
    FindByName("BST", "./input/Large.csv", "./output/output_bst_find_by_name_large.txt","372");
    FindByName("BST", "./input/Small.csv", "./output/output_bst_find_by_name_small.txt","372");
    FindByName("BST", "./input/Medium.csv", "./output/output_bst_find_by_name_medium.txt","372");
    FindByName("AVL", "./input/Large.csv", "./output/output_avl_find_by_name_large.txt","372");
    FindByName("AVL", "./input/Small.csv", "./output/output_avl_find_by_name_small.txt","372");
    FindByName("AVL", "./input/Medium.csv", "./output/output_avl_find_by_name_medium.txt","372");

    
    FindByDate("BST", "./input/Large.csv", "./output/output_bst_find_by_date_large.txt","2008-08-03");
    FindByDate("BST", "./input/Small.csv", "./output/output_bst_find_by_date_small.txt","2008-08-03");
    FindByDate("BST", "./input/Medium.csv", "./output/output_bst_find_by_date_medium.txt","2008-08-03");
    FindByDate("AVL", "./input/Large.csv", "./output/output_avl_find_by_date_large.txt","2008-08-03");
    FindByDate("AVL", "./input/Small.csv", "./output/output_avl_find_by_date_small.txt","2008-08-03");
    FindByDate("AVL", "./input/Medium.csv", "./output/output_avl_find_by_date_medium.txt","2008-08-03");

    FindByNameAndSize("BST", "./input/Large.csv", "./output/output_bst_find_by_name_and_size_large.txt","291",94563);
    FindByNameAndSize("BST", "./input/Small.csv", "./output/output_bst_find_by_name_and_size_small.txt","291",94563);
    FindByNameAndSize("BST", "./input/Medium.csv", "./output/output_bst_find_by_name_and_size_medium.txt","291",94563);
    FindByNameAndSize("AVL", "./input/Large.csv", "./output/output_avl_find_by_name_and_size_large.txt","291",94563);
    FindByNameAndSize("AVL", "./input/Small.csv", "./output/output_avl_find_by_name_and_size_small.txt","291",94563);
    FindByNameAndSize("AVL", "./input/Medium.csv", "./output/output_avl_find_by_name_and_size_medium.txt","291",94563);

    FindByNameAndDate("BST", "./input/Large.csv", "./output/output_bst_find_by_name_and_date_large.txt","756","2008-08-03");
    FindByNameAndDate("BST", "./input/Small.csv", "./output/output_bst_find_by_name_and_date_small.txt","756","2008-08-03");
    FindByNameAndDate("BST", "./input/Medium.csv", "./output/output_bst_find_by_name_and_date_medium.txt","756","2008-08-03");
    FindByNameAndDate("AVL", "./input/Large.csv", "./output/output_avl_find_by_name_and_date_large.txt","756","2008-08-03");
    FindByNameAndDate("AVL", "./input/Small.csv", "./output/output_avl_find_by_name_and_date_small.txt","756","2008-08-03");
    FindByNameAndDate("AVL", "./input/Medium.csv", "./output/output_avl_find_by_name_and_date_medium.txt","756","2008-08-03");

    FindFilesCreatedDuring("BST", "./input/Large.csv", "./output/output_bst_find_files_created_during_large.txt","2008-07-26","2008-08-03");
    FindFilesCreatedDuring("BST", "./input/Small.csv", "./output/output_bst_find_files_created_during_small.txt","2008-07-26","2008-08-03");
    FindFilesCreatedDuring("BST", "./input/Medium.csv", "./output/output_bst_find_files_created_during_medium.txt","2008-07-26","2008-08-03");
    FindFilesCreatedDuring("AVL", "./input/Large.csv", "./output/output_avl_find_files_created_during_large.txt","2008-07-26","2008-08-03");
    FindFilesCreatedDuring("AVL", "./input/Small.csv", "./output/output_avl_find_files_created_during_small.txt","2008-07-26","2008-08-03");
    FindFilesCreatedDuring("AVL", "./input/Medium.csv", "./output/output_avl_find_files_created_during_medium.txt","2008-07-26","2008-08-03");
    
    
    
    return 0;
}

