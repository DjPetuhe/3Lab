#include "Hernuf.h"

Stack::Stack(int size)
{
    this->size = 0;
    this->realSize = 2 * size;
    this->array = new string[this->realSize];
}

Stack::Stack()
{
    this->size = 0;
    this->realSize = 20;
    this->array = new string[realSize];
}

void Stack::pop()
{
    if (size > 0)
    {
        this->size -= 1;
    }
    else
    {
        cout << endl
             << "Error! anything to pop!" << endl;
    }
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

string Stack::top()
{
    return this->array[size];
}

bool Stack::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Stack::~Stack()
{
    delete[] this->array;
}

void expressionSeparate(string args, string *expression, int *expressionSize)
{
    int count = 0;
    for (int i = 0; i < args.length(); i++)
    {
        if (args[i] >= 48 && args[i] <= 57)
        {
            if (count > 0 && !(expression[count][0] >= 48 && expression[count][0] <= 57))
            {
                count++;
            }
            expression[count] += args[i];
        }
        else
        {
            if (args[i] != ' ')
            {
                count++;
                expression[count] += args[i];
            }
        }
    }
    *expressionSize = count + 1;
}