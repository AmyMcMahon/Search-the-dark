// lol its quicksort
#include "bubblySort.h"
#include <algorithm>

int bubblySort::partition(Vectory<DocCount> &vec, int low, int high)
{

    int pivot = vec[high].count;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (vec[j].count >= pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void bubblySort::quickSort(Vectory<DocCount> &vec, int low, int high)
{

    if (low < high)
    {

        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
