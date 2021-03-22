#include <iostream>
#include "Tkachuk.h"
#include "Hernuf.h"
using namespace std;

int main(int argc, char *argv[])
{
    string args;
    for (int i = 1; i < argc; i++)
    {
        args += argv[i];
    }
    string *expression = new string[argc];
    int expression_size = argc;
    expressionSeparate(args, expression, &expression_size);
    delete[] expression;
}