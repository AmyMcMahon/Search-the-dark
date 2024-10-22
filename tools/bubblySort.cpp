// lol its quicksort
#include "bubblySort.h"
#include <algorithm>
#include <cstring>
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

int bubblySort::partitionByName(Vectory<Result> &vec, int low, int high)
{
    string pivot_str = vec[high].title;
    int n = pivot_str.length();
    char pivot[n + 1];
    strcpy(pivot, pivot_str.c_str());
    int i = (low - 1);
    int string_lenght = 0;
    for (int j = low; j <= high - 1; j++)
    {
        string_lenght = vec[j].title.length();
        char temp[string_lenght + 1];
        strcpy(temp, vec[j].title.c_str());

        if (strcmp(temp, pivot) < 0)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);

    return (i + 1);
};
void bubblySort::quickSortByCount(Vectory<Result> &vec, int low, int high)
{
    if (low < high)
    {
        int pi = partitionByCount(vec, low, high);

        quickSortByCount(vec, low, pi - 1);
        quickSortByCount(vec, pi + 1, high);
    }
}

int bubblySort::partitionByCount(Vectory<Result> &vec, int low, int high)
{
    int pivot = vec[high].relevance;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (vec[j].relevance >= pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);

    return (i + 1);
};

void bubblySort::quickSortByName(Vectory<Result> &vec, int low, int high)
{
    if (low < high)
    {
        int pi = partitionByName(vec, low, high);

        quickSortByName(vec, low, pi - 1);
        quickSortByName(vec, pi + 1, high);
    }
};