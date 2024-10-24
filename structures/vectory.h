#ifndef VECTORY_H
#define VECTORY_H
#include <stdexcept>

template <typename T>
class Vectory
{
    T *arry;
    int cappy;
    int current;

public:
    Vectory();
    ~Vectory();
    void push_back(T data);
    void erase(int index);
    int size() const;
    bool empty();
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    T *begin();
    T *end();
    T *begin() const;
    T *end() const;
    Vectory(Vectory &&other) noexcept;
    Vectory &operator=(Vectory &&other) noexcept;

    Vectory(const Vectory &other);
    Vectory &operator=(const Vectory &other);
    int search(const T &value) const;
};

// Constructor
template <typename T>
Vectory<T>::Vectory()
{
    arry = new T[1];
    cappy = 1;
    current = 0;
}

// Destructor
template <typename T>
Vectory<T>::~Vectory()
{
    delete[] arry;
}

// Method to add elements to the array - if the array is full, double the size
template <typename T>
void Vectory<T>::push_back(T data)
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

// Method to remove an element from the array
template <typename T>
void Vectory<T>::erase(int index)
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

// Method to return the size of the array
template <typename T>
int Vectory<T>::size() const
{
    return current;
}

// Method to check if the array is empty
template <typename T>
bool Vectory<T>::empty()
{
    return size() == 0;
}

// Overloaded [] operator to access elements in the array
template <typename T>
T &Vectory<T>::operator[](size_t index)
{
    if (index >= current)
    {
        throw std::out_of_range("Index out of range");
    }
    return arry[index];
}

// Overloaded [] operator to access elements in the array - const
template <typename T>
const T &Vectory<T>::operator[](size_t index) const
{
    if (index >= current)
    {
        throw std::out_of_range("Index out of range");
    }
    return arry[index];
}

// Method to return a pointer to the first/last element in the array
template <typename T>
T *Vectory<T>::begin() { return arry; }
template <typename T>
T *Vectory<T>::end() { return arry + current; }

// Method to return a pointer to the first/last element in the array - const
template <typename T>
T *Vectory<T>::begin() const
{
    return arry;
}
template <typename T>
T *Vectory<T>::end() const
{
    return arry + current;
}

// Move constructor
template <typename T>
Vectory<T>::Vectory(Vectory &&other) noexcept
    : arry(other.arry), cappy(other.cappy), current(other.current)
{
    other.arry = nullptr; // Leave other in a valid state
    other.cappy = 0;
    other.current = 0;
}

// Move assignment operator
template <typename T>
Vectory<T> &Vectory<T>::operator=(Vectory &&other) noexcept
{
    if (this != &other)
    {
        delete[] arry;
        arry = other.arry;
        cappy = other.cappy;
        current = other.current;
        other.arry = nullptr;
        other.cappy = 0;
        other.current = 0;
    }
    return *this;
}

// Copy constructor
template <typename T>
Vectory<T>::Vectory(const Vectory &other)
    : arry(new T[other.cappy]), cappy(other.cappy), current(other.current)
{
    for (int i = 0; i < current; ++i)
    {
        arry[i] = other.arry[i]; // Deep copy each element
    }
}

// Copy assignment operator
template <typename T>
Vectory<T> &Vectory<T>::operator=(const Vectory &other)
{
    if (this != &other)
    {
        delete[] arry;

        // Allocate new memory and copy
        arry = new T[other.cappy];
        cappy = other.cappy;
        current = other.current;
        for (int i = 0; i < current; ++i)
        {
            arry[i] = other.arry[i];
        }
    }
    return *this;
}

template <typename T>
int Vectory<T>::search(const T &value) const
{
    for (int i = 0; i < current; ++i)
    {
        if (arry[i] == value)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}
#endif // VECTORY_H
