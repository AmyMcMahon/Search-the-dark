#include <iostream>
#include <string>
#include "vectory.h"
#include "../tools/indexy.h"
#include "../tools/bubblySort.h"
#include "mappy.h"
#include <algorithm>
using namespace std;

class Nodey
{
public:
    Nodey *childrens[26];
    bool endofWord;
    int popularity;

    Nodey()
    {
        endofWord = false;
    }
};

class Triey
{
public:
    Nodey *root;

    Triey();
    void populateTriey(Vectory<trieData> words);
    Vectory<string> search(string input);
    Vectory<string> rank(Vectory<DocCount> &all_matches);
    void lookForWords(Nodey *current, string input, Vectory<DocCount> &all_matches);
    bool lookForWord(string word);
    void print(Nodey *node, string prefix) const;
    void print() const;
};