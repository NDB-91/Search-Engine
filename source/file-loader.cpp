#include "file-loader.h"

FileLoader::FileLoader(const std::string& directoryPath)
    : _directoryPath(directoryPath) {
}

std::vector<std::pair<std::string, std::string>> FileLoader::loadDocuments() {
    std::vector<std::pair<std::string, std::string>> documents;

    for (const auto& entry : std::filesystem::directory_iterator(_directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::string fileName = entry.path().filename().string();
            std::string fileContent = readFile(entry.path());
            documents.emplace_back(fileName, fileContent);
            std::cout << "Loaded document: " << fileName << "\n";
        }
    }

    return documents;
}

std::string FileLoader::readFile(const std::filesystem::path& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath.string());
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}