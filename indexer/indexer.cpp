#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "../structures/mappy.h"
#include "../structures/vectory.h"

namespace fs = std::filesystem;

class Indexer
{
public:
    // Function to add words from a file to the index
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

    void removeFile(const std::string &name, Mappy &index)
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
            // Remove the word from the index with the document ID
            index.removeWord(word.c_str(), name.c_str());
        }

        file.close();
    }

    // Function to export the index to CSV files
    void toCsv(Mappy &index)
    {
        collectData(index.root); // Collect data from the index and write to CSV
    }

private:
    // Helper function to recursively collect data from Mappy and write to respective CSV files
    void collectData(Mappy *node)
    {
        if (node == nullptr)
            return;

        // In-order traversal to maintain order in the CSVs
        collectData(node->left);

        if (!node->first.empty())
        {
            char firstLetter = tolower(node->first[0]);
            std::string fileName = "./index/" + std::string(1, firstLetter) + ".csv";

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

    // Iterate through files in the specified directory and add them to the index
    for (const auto &entry : fs::directory_iterator(path))
    {
        idx.addFiley(entry.path().string(), index);
    }

    // Export the index to CSV files
    idx.toCsv(index);

    return 0;
}