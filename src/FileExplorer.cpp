#include "FileExplorer.hpp"

std::vector<std::string> generateDateList(const std::string &startDateStr, const std::string &endDateStr)
{
    std::vector<std::string> dateList;

    // Parse start date
    std::tm startDate = {};
    std::istringstream startDateStream(startDateStr);
    startDateStream >> std::get_time(&startDate, "%Y-%m-%d");

    // Parse end date
    std::tm endDate = {};
    std::istringstream endDateStream(endDateStr);
    endDateStream >> std::get_time(&endDate, "%Y-%m-%d");

    // Convert start date and end date to time points
    auto startTime = std::chrono::system_clock::from_time_t(std::mktime(&startDate));
    auto endTime = std::chrono::system_clock::from_time_t(std::mktime(&endDate));

    // Generate dates in between
    for (auto time = startTime; time <= endTime; time += std::chrono::hours(24))
    {
        auto date = std::chrono::system_clock::to_time_t(time);
        std::tm *dateTm = std::localtime(&date);
        char buffer[11]; // Buffer for storing formatted date
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", dateTm);
        dateList.push_back(buffer);
    }

    return dateList;
}

FileExplorer::FileExplorer(string type, string csv_file)
{
    if (type == "BST")
    {
        nameIndex = new BSTIndex();
        dateIndex = new BSTIndex();
    }
    else if (type == "AVL")
    {
        nameIndex = new AVLIndex();
        dateIndex = new AVLIndex();
    }
    fs = new FileSystem();
    fs->load_files_from_csv(csv_file);
    // fs->print_file_entry();
    nameIndex->createIndex(fs->entries, "Filename");
    dateIndex->createIndex(fs->entries, "Date");
    std::cout << nameIndex->getRootHeight() << std::endl;
    std::cout << nameIndex->getTotalNodesCount() << std::endl;
    std::cout << dateIndex->getRootHeight() << std::endl;
    std::cout << dateIndex->getTotalNodesCount() << std::endl;
    // index->createIndex(fs->entries, indexType);
    // index->print();
}

FileExplorer::~FileExplorer()
{
    delete nameIndex;
    delete dateIndex;
    delete fs;
}

void FileExplorer::FindByName(string filename, string output_path)
{
    std::pair<std::vector<int>, int> result;
    result = nameIndex->search(filename);
    // save the result to a file
    ofstream out(output_path);
    out << "Number of nodes traversed: " << result.second << endl;
    for (auto &record : result.first)
    {
        out << fs->entries[record].path << endl;
    }
}

void FileExplorer::FindByDate(string date, string output_path)
{
    std::pair<std::vector<int>, int> result;
    result = dateIndex->search(date);
    // save the result to a file
    ofstream out(output_path);
    out << "Number of nodes traversed: " << result.second << endl;
    for (auto &record : result.first)
    {
        out << fs->entries[record].path << endl;
    }
}

void FileExplorer::FindByNameAndDate(string filename, string date, string output_path)
{
    std::pair<std::vector<int>, int> result;
    result = nameIndex->search(filename);
    std::pair<std::vector<int>, int> result2;
    result2 = dateIndex->search(date);
    std::vector<int> result3;
    int NodesTraversed = result.second + result2.second;
    std::set_intersection(result.first.begin(), result.first.end(), result2.first.begin(), result2.first.end(), std::back_inserter(result3));
    // save the result to a file
    ofstream out(output_path);
    out << "Number of nodes traversed: " << NodesTraversed << endl;
    for (auto &record : result3)
    {
        out << fs->entries[record].path << endl;
    }
}

void FileExplorer::FindByNameAndSize(string filename, int size, string output_path)
{
    std::pair<std::vector<int>, int> result;
    result = nameIndex->search(filename);
    std::vector<int> result2;
    for (auto &record : result.first)
    {
        if (fs->entries[record].Size == size)
        {
            result2.push_back(record);
        }
    }
    
    // save the result to a file
    ofstream out(output_path);
    out << "Number of nodes traversed: " << result.second << endl;
    for (auto &record : result2)
    {
        out << fs->entries[record].path << endl;
    }
}

void FileExplorer::FindFilesCreatedDuring(string date1, string date2, string output_path)
{
    // Create a list of dates from date1 to date2
    std::vector<std::string> dateList = generateDateList(date1, date2);
    // Iterate through the dateList and search for files created on each date
    std::vector<int> recordsFound;
    int nodesTraversed = 0;
    for (const auto &date : dateList)
    {
        std::cout << "Searching for files created on " << date << std::endl;
        std::pair<std::vector<int>, int> result = dateIndex->search(date);
        for (const auto &record : result.first)
        {
            nodesTraversed += result.second;
            // Check if the record is already in the recordsFound list
            if (std::find(recordsFound.begin(), recordsFound.end(), record) != recordsFound.end())
            {
                continue;
            }
            recordsFound.push_back(record);
        }
    }
    // Save the result to a file
    ofstream out(output_path);
    out << "Number of nodes traversed: " << nodesTraversed << endl;
    for (auto &record : recordsFound)
    {
        out << fs->entries[record].path << endl;
    }
}
