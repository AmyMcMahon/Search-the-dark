#ifndef MAPPY_H
#define MAPPY_H
#include <iostream>
#include "vectory.h"
#include "structs.h"
using namespace std;

class Mappy
{
public:
    Mappy *root;
    Mappy *left;
    Mappy *right;
    Mappy *par;
    std::string first; // word
    WordData second;   // Count and document counts
    int depth;

    Mappy *create(const char *first, std::string docName);

    int depthy(Mappy *node);
    void balance(Mappy *node);
    void rightRotate(Mappy *x);
    void leftRotate(Mappy *x);

    Mappy *remove(const char *word, const std::string &docName);
    Mappy *removeNode(Mappy *node);

    Mappy *insert(const char *first, const std::string &docName);
    Mappy() : root(nullptr) {};

    void addWord(const char *word, std::string docName);
    void removeWord(const char *word, std::string docName);
};

#endif