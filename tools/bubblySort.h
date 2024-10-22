// lol its quicksort
#ifndef BUBBLYSORT_H
#define BUBBLYSORT_H

#include "../structures/structs.h"
#include "../structures/vectory.h"
#include "../structures/mappy.h"

class bubblySort
{
public:
    int partition(Vectory<DocCount> &vec, int low, int high);
    void quickSort(Vectory<DocCount> &vec, int low, int high);
    int partitionByCount(Vectory<Result> &vec, int low, int high);
    void quickSortByCount(Vectory<Result> &vec, int low, int high);
    int partitionByName(Vectory<Result> &vec, int low, int high);
    void quickSortByName(Vectory<Result> &vec, int low, int high);
};

#endif
