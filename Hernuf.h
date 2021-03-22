#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    string *array;
    int size;
    int realSize;
    Stack(int);
    Stack();
    ~Stack();

public:
    void push(string);
    void pop();
    string top();
    bool isEmpty();
};