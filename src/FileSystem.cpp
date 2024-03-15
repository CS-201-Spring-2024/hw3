#include "FileSystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

void FileSystem::LoadFilesFromCsv(const string &csv_file)
{
    ifstream file(csv_file);
    if (!file.is_open())
    {
        cerr << "Error opening file " << csv_file << endl;
    }
    string line;

    getline(file, line); // Skip header
    while (getline(file, line))
    {
        stringstream ss(line);
        FileSystemEntry entry;
        getline(ss, entry.Filename, ',');
        getline(ss, entry.Type, ',');
        ss >> entry.Size;
        ss.ignore();
        // Read and parse timestamps
        string accessedOnStr, modifiedOnStr;
        getline(ss, accessedOnStr, ',');
        getline(ss, modifiedOnStr, ',');
        entry.modifiedOn = ParseTimestamp(modifiedOnStr);
        entry.accessedOn = ParseTimestamp(accessedOnStr);

        ss.ignore();
        getline(ss, entry.path, ',');
        entries.push_back(entry);
    }
    file.close();
}

void FileSystem::PrintFileEntry()
{
    // print the file entry
    for (const auto &entry : entries)
    {
        // print each column on a new line
        cout << "Filename: " << entry.Filename << "\n";
        cout << "Type: " << entry.Type << "\n";
        cout << "Size:" << entry.Size << "\n";
        cout << "createdOn: " << entry.accessedOn << "\n";
        cout << "modifiedOn: " << entry.modifiedOn << "\n";
        cout << "path: " << entry.path << "\n";
        cout << "\n";
    }
}

string FileSystem::ParseTimestamp(const string &timestampStr)
{
    // Convert timestamp string to tm struct
    struct tm tm = {};
    stringstream ss(timestampStr);
    ss >> get_time(&tm, "%Y-%m-%dT%H:%M:%S");
    if (ss.fail())
    {
        cerr << "Error parsing timestamp: " << timestampStr << endl;
        return ""; // Return empty string if parsing fails
    }

    // Format tm struct to desired date string
    stringstream formatted_date;
    formatted_date << std::put_time(&tm, "%Y-%m-%d");
    return formatted_date.str();
}