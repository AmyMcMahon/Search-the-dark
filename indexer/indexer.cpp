#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include <cctype>
#include "mappy.h"

namespace fs = std::filesystem;

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
        // We will dynamically open files based on the first letter of the word
        collectData(index.root);
    }

private:
    // Helper function to recursively collect data from Mappy and write to respective CSV files
    void collectData(Mappy *node)
    {
        if (node == nullptr)
            return;

        // In-order traversal to maintain order in the CSVs
        collectData(node->left);

        // Determine the first letter of the word
        if (!node->first.empty())
        {
            char firstLetter = tolower(node->first[0]);
            std::string fileName = "./index/" + std::string(1, firstLetter) + ".csv";

            // Open the respective CSV file in append mode
            std::ofstream file(fileName, std::ios::app);

            if (!file.is_open())
            {
                std::cerr << "Error opening the file: " << fileName << std::endl;
                return;
            }

            // Write the word, its total count, and document counts to the file
            file << node->first << "," << node->second.count << ",";
            for (const DocCount &docCount : node->second.docCounts)
            {
                file << docCount.docName << "," << docCount.count << "\t";
            }
            file << std::endl;

            file.close(); // Close the file after writing the data
        }

        collectData(node->right);
    }
};

int main()
{
    Indexer idx;
    Mappy index;
    std::string path = "./books";

    for (const auto &entry : fs::directory_iterator(path))
    {
        idx.addFiley(entry.path().string(), index);
    }

    idx.toCsv(index);

    return 0;
}
