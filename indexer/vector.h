#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vectory
{
    T *arry;
    int cappy;
    int current;

public:
    Vectory()
    {
        arry = new T[1];
        cappy = 1;
        current = 0;
    }

    ~Vectory()
    {
        delete[] arry;
    }

    void push_back(T data)
    {
        if (current == cappy)
        {
            T *temp = new T[2 * cappy];

            for (int i = 0; i < cappy; i++)
            {
                temp[i] = arry[i];
            }

            delete[] arry;
            cappy *= 2;
            arry = temp;
        }

        arry[current] = data;
        current++;
    }

    T &operator[](size_t index)
    {
        if (index >= current)
        {
            throw std::out_of_range("Index out of range");
        }
        return arry[index];
    }

    T *begin() { return arry; }
    T *end() { return arry + current; }
};