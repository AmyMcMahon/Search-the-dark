#include "../structures/vectory.h"
#include "indexy.h"
#include "bubblySort.h"

class Syntaxy { 
public:
    Syntaxy();
    Vectory<Result> and_search(Vectory<Result> &word1, Vectory<Result> &word2);
    Vectory<Result> or_search(Vectory<Result> word1, Vectory<Result> word2);
    Vectory<Result> not_search(Vectory<Result> word1);
private:
    bubblySort sorter;
    Indexy idx;
};