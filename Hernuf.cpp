#include "Hernuf.h"

Stack::Stack(int size)
{
    this->size = size;
    this->realSize = 2 * size;
    this->array = new string[this->realSize];
}

Stack::Stack()
{
    this->size = 20;
    this->array = new string[40];
}

void Stack::pop()
{
    this->size -= 1;
}

void Stack::push(string str)
{
    this->size += 1;
    if (size == realSize)
    {
        realSize = 2 * size;
        string *array2 = new string[realSize];
        for (int i = 0; i < size; i++)
        {
            array2[i] = this->array[i];
        }
        delete[] array;
        this->array = array2;
    }
    this->array[size] = str;
}