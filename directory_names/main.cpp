#include <iostream>
#include <filesystem>
#include <queue>

namespace fs = std::filesystem;

void list_folders_recursively(const fs::path& path, int indent=0) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            const auto& sub_folder = entry.path();
            std::cout << std::string(indent, ' ') << sub_folder << std::endl;
            list_folders_recursively(sub_folder, indent+2);
        }
    }
}

void list_folders(const fs::path& path) {

    std::queue<std::pair<fs::path, int>> paths;

    // push folders in current folder on to queue
    for (const auto& entry: fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            paths.emplace(entry.path(), 0);
        }
    }

    while (!paths.empty()) {
        // pop one folder off the queue and go into that folder
        auto current = paths.front();
        std::cout << std::string(current.second, ' ') << current.first << std::endl;
        paths.pop();

        // push folders in the current folder on the the queue
        for (const auto& entry: fs::directory_iterator(current.first)) {
            if (entry.is_directory()) {
                paths.emplace(entry.path(), current.second + 2);
            }
        }
    }
}

int main() {

    auto path = fs::path(".");

    list_folders(path);

    return 0;
}