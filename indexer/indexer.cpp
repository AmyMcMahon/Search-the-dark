#include "../tools/indexy.h"
#include "../structures/mappy.h"
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    Indexy idx;
    Mappy index;
    Vectory<std::string> indexedBooks;
    std::string indexPath = "./indexer/indexedBooks.csv";

    std::ifstream file(indexPath);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
        return 0;
    }
    std::string line;
    while (std::getline(file, line))
    {
        indexedBooks.push_back(line);
    }

    std::string path = "./books";

    // Iterate through files in the specified directory and add them to the index
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (std::find(indexedBooks.begin(), indexedBooks.end(), entry.path().string()) != indexedBooks.end())
        {
            continue;
        }
        idx.addFiley(entry.path().string(), index);
    }
    // Export the index to CSV files
    idx.toCsv(index);

    return 0;
}