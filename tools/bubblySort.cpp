// lol its quicksort
#include "bubblySort.h"

int partition(vector<sortData> &vec, int low, int high)
{

    int pivot = vec.count[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (vec.count[j] <= pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void quickSort(vector<sortData> &vec, int low, int high)
{

    if (low < high)
    {

        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}