#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include <cctype>
#include "mappy.h"

namespace fs = std::filesystem;

// struct Doccy {
//     std::string doccy_name;
//     int count;

//     Doccy(std::string name, int count) : doccy_name(name), count(count) {}
//     Doccy() : doccy_name(""), count(0) {}
// };

class Indexer
{
public:
    void addFiley(const std::string &name, Mappy &index)
    {
        std::ifstream file(name);

        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return;
        }

        std::string word;
        while (file >> word)
        {
            // Convert to lowercase and remove punctuation
            for (int i = 0, len = word.size(); i < len; i++)
            {
                word[i] = tolower(word[i]);
                if (ispunct(word[i]))
                {
                    word.erase(i--, 1);
                    len = word.size();
                }
            }
            // Insert the word into the index with the document ID
            index.addWord(word.c_str(), name.c_str());
        }

        file.close();
    }

    void toCsv(Mappy &index)
    {
        std::ofstream file("indexT.csv");

        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return;
        }

        // Assuming you implement a method to traverse the Mappy tree
        // and collect the word data for CSV output
        collectData(index.root, file);

        file.close();
    }

private:
    // Helper function to recursively collect data from Mappy and write to file
    void collectData(Mappy *node, std::ofstream &file)
    {
        if (node == nullptr)
            return;

        // In-order traversal
        collectData(node->left, file);

        // Write the word and its data to the file
        file << node->first << "," << node->second.count << ",";
        for (const DocCount &docCount : node->second.docCounts)
        {
            file << docCount.docName << "," << docCount.count << "\t";
        }
        file << std::endl;

        collectData(node->right, file);
    }
};

int main()
{
    Indexer idx;
    Mappy index; // Use Mappy instead of std::map
    std::string path = "./books";

    for (const auto &entry : fs::directory_iterator(path))
    {
        idx.addFiley(entry.path().string(), index);
    }

    idx.toCsv(index);

    return 0;
}
