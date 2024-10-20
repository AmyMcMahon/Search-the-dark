#ifndef INDEXY_H
#define INDEXY_H

#include <filesystem>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "../structures/mappy.h"
#include "../structures/vectory.h"

namespace fs = std::filesystem;

struct Result
{
    std::string title;
    std::string filePath;
    int relevance;
};

struct trieData
{
    std::string word;
    int count;
};

class Indexy
{
public:
    Indexy();
    void addFiley(const std::string &name, Mappy &index);
    void removeFile(const std::string &name, Mappy &index);
    void toCsv(Mappy &index);
    void createIndex();
    Vectory<Result> getBooks(const std::string &searchStr);
    Vectory<trieData> readFileTrie(char word);

private:
    Vectory<Result> sortResultsByRelevance(const Vectory<DocCount> &books);
    void collectData(Mappy *node);
};

#endif