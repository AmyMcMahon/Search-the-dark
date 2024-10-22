#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include "vectory.h"

// used when searching trie and index
struct Result
{
    std::string title;
    std::string filePath;
    int relevance;
};

// used when storing data in trie
struct trieData
{
    std::string word;
    int count;
};

// used to hold the info about a word in a doc
struct DocCount
{
    std::string docName;
    int count;
};

// used to hold overall count and list of docCount
struct WordData
{
    int count;
    Vectory<DocCount> docCounts;
};

#endif