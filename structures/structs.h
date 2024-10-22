#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include "vectory.h"

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

struct DocCount
{
    std::string docName;
    int count;
};

struct WordData
{
    int count;                   // Total count of the word
    Vectory<DocCount> docCounts; // List of document counts
};

#endif