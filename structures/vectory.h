#ifndef VECTORY_H  
#define VECTORY_H
#include <stdexcept>

template <typename T> class Vectory
{
    T *arry;
    int cappy;
    int current;

public:
    Vectory();
    ~Vectory();
    void push_back(T data);
    void erase(int index);
    int size();
    bool empty();
    T &operator[](size_t index);
    T *begin();
    T *end();
};

template <typename T> Vectory<T>::Vectory()
{
    arry = new T[1];
    cappy = 1;
    current = 0;
}

template <typename T> Vectory<T>::~Vectory()
{
    delete[] arry;
}

template <typename T> void Vectory<T>::push_back(T data)
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

template <typename T> void Vectory<T>::erase(int index)
{
    if (index < 0 || index >= current)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < current - 1; i++)
    {
        arry[i] = arry[i + 1];
    }
    current--;
}

template <typename T> int Vectory<T>::size()
{
    return current;
}

template <typename T> bool Vectory<T>::empty()
{
    return size() == 0;
}

template <typename T> T &Vectory<T>::operator[](size_t index)
{
    if (index >= current)
    {
        throw std::out_of_range("Index out of range");
    }
    return arry[index];
}
template <typename T> T *Vectory<T>::begin() { return arry; }
template <typename T> T *Vectory<T>::end() { return arry + current; }


#endif // VECTORY_H
