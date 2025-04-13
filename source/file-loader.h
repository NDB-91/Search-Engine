#ifndef _FILE_LOADER_H_
#define _FILE_LOADER_H_

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

class FileLoader {
public:
    FileLoader(const std::string& directoryPath);

    std::vector<std::pair<std::string, std::string>> loadDocuments();

private:
    std::string _directoryPath;

    std::string readFile(const std::filesystem::path& filePath);
};

#endif