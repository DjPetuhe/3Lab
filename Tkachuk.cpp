#include<iostream>
#include "Tkachuk.h"
#include "Hernuf.h"

using namespace std;


int do_it (Stack &nums, Stack &operations) {

    int a, b;
    char c;

    b = stoi(nums.top());
    nums.pop();
    a = stoi(nums.top());
    nums.pop();
    c = operations.top()[0];
    operations.pop();

    if (c == '+') {
        return a + b;
    } else if (c == '-') {
        return a - b;
    } else if (c == '*') {
        return a * b;
    } else if (c == '/') {
        return a / b;
    } else if (c == '^') {
        int res = 1;
        for (int i = 1; i <= b; i++) {
            res *= a;
        }
        return res;
    } 
    return 0;
}



int calculation (string *s, int size) {
    Stack nums, operations;
    int res;

    for (int i = 0; i < size; i++) {
        if (s[i][0] >= '0' && s[i][0] <= '9') {
            nums.push(s[i]);

        } else if (s[i] == "+" || s[i] == "-") {
            if (!operations.isEmpty() && (operations.top() == "*" || operations.top() == "/" || operations.top() == "-" || operations.top() == "+"  || operations.top() == "^")) {
                while (!operations.isEmpty() && (operations.top() == "*" || operations.top() == "/" || operations.top() == "-" || operations.top() == "+" || operations.top() == "^"))
                {
                    res = do_it(nums, operations);
                    nums.push(to_string(res));
                }
            } 

            if (i == 0 || !(s[i-1][0] >= '0' && s[i-1][0] <= '9')) {
                nums.push("0");
            }

            operations.push(s[i]);

        } else if (s[i] == "*" || s[i] == "/") {
            if (!operations.isEmpty() && (operations.top() == "*" || operations.top() == "/" || operations.top() == "^")) {
                while (operations.top() == "*" || operations.top() == "/" || operations.top() == "^")
                {
                    res = do_it(nums, operations);
                    nums.push(to_string(res));
                }
            } 

            operations.push(s[i]);

        } else if (s[i] == "(") {
            operations.push(s[i]);

        } else if (s[i] == ")") {
            while (operations.top() != "(")
            {
                res = do_it(nums, operations);
                nums.push(to_string(res));
            }

            operations.pop();

        } else if (operations.top() != "^") {
            operations.push(s[i]);
        }
    }

    while(!operations.isEmpty() && !nums.isEmpty()) {
        res = do_it(nums, operations);
        nums.push(to_string(res));
    }

    return stoi(nums.top());
}