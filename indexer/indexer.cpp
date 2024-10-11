#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

namespace fs = std::filesystem;

struct Doccy
{
    std::string doccy_name;
    int count;

    Doccy(std::string name, int count)
    {
        this->doccy_name = name;
        this->count = count;
    }

    Doccy() : doccy_name(""), count(0) {}
};

class indexer
{
public:
    void addFiley(const std::string &name, std::map<std::string, std::pair<int, std::vector<Doccy>>> &index)
    {
        std::ifstream file(name);

        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return;
        }

        std::map<std::string, int> docWordCount;
        std::string word;
        while (file >> word)
        {

            for (int i = 0, len = word.size(); i < len; i++)
            {
                // check whether parsing character is punctuation or not
                word[i] = tolower(word[i]);
                if (ispunct(word[i]))
                {
                    word.erase(i--, 1);
                    len = word.size();
                }
            }
            docWordCount[word]++;
        }

        for (const auto &pair : docWordCount)
        {
            const std::string &word = pair.first;
            int docCount = pair.second;

            if (index.find(word) == index.end())
            {
                index[word].first = docCount;
                index[word].second.push_back(Doccy(name, docCount));
            }
            else
            {
                index[word].first += docCount;
                index[word].second.push_back(Doccy(name, docCount));
            }
        }

        file.close();
    }

    void toCsv(const std::map<std::string, std::pair<int, std::vector<Doccy>>> &index)
    {
        std::ofstream file("index.csv");

        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return;
        }

        for (const auto &pair : index)
        {
            const std::string &word = pair.first;
            const std::pair<int, std::vector<Doccy>> &info = pair.second;

            file << word << "," << info.first << ",";

            for (const Doccy &doc : info.second)
            {
                file << doc.doccy_name << "," << doc.count << "\t";
            }

            file << std::endl;
        }

        file.close();
    }
};

int main()
{
    indexer idx;
    std::map<std::string, std::pair<int, std::vector<Doccy>>> index;
    std::string path = "./books";

    for (const auto &entry : fs::directory_iterator(path))
    {
        idx.addFiley(entry.path().string(), index);
    }

    idx.toCsv(index);

    return 0;
}
