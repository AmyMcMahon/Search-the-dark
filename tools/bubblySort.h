// lol its quicksort
#ifndef BUBBLYSORT_H
#define BUBBLYSORT_H

#include "../structures/vectory.h"

struct sortData
{
    std::string word;
    int count;
};

int partition(Vectory<sortData> &vec, int low, int high);
void quickSort(Vectory<sortData> &vec, int low, int high);

#endif
