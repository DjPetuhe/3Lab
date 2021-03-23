#include<iostream>
#include "Tkachuk.h"
#include "Hernuf.h"

using namespace std;


int do_it (int a, int b, char c) {
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
        for (int i = 1; i <= a; i++) {
            res *= b;
        }
        return res;
    } 
    return 0;
}


int calculation (string *s, int size) {
    Stack n, o;
    int p1, p2, r;
    char c;

    for (int i = 0; i < size; i++) {

        if (s[i][0] >= '0' && s[i][0] <= '9') {

            n.push(s[i]);

        } else if (s[i] == "+" || s[i] == "-") {

            if (!o.isEmpty() && (o.top() == "*" || o.top() == "/" || o.top() == "-" || o.top() == "+")) {

                while (!o.isEmpty() && (o.top() == "*" || o.top() == "/" || o.top() == "-" || o.top() == "+"))
                {
                    p1 = stoi(n.top());
                    n.pop();
                    p2 = stoi(n.top());
                    n.pop();
                    c = o.top()[0];
                    o.pop();
                    r = do_it(p2, p1, c);
                    n.push(to_string(r));
                }
            } 
            o.push(s[i]);

        } else if (s[i] == "*" || s[i] == "/") {
            
            if (!o.isEmpty() && (o.top() == "*" || o.top() == "/")) {

                while (o.top() == "*" || o.top() == "/")
                {
                    p1 = stoi(n.top());
                    n.pop();
                    p2 = stoi(n.top());
                    n.pop();
                    c = o.top()[0];
                    o.pop();
                    r = do_it(p2, p1, c);
                    n.push(to_string(r));
                }
                
            } 
            
            o.push(s[i]);

        } else if (s[i] == "(") {

            o.push(s[i]);

        } else if (s[i] == ")") {

            while (o.top() != "(")
            {
                p1 = stoi(n.top());
                n.pop();
                p2 = stoi(n.top());
                n.pop();
                c = o.top()[0];
                o.pop();
                r = do_it(p2, p1, c);
                n.push(to_string(r));
            }
            
            o.pop();

        } else if (o.top() != "^") {
            p1 = stoi(n.top());
            n.pop();
            i++;
            p2 = stoi(s[i]);
            c = '^';
            r = do_it(p2, p1, c);
            n.push(to_string(r));
        }
    }

    while(!o.isEmpty() && !n.isEmpty()) {
        p1 = stoi(n.top());
        n.pop();
        p2 = stoi(n.top());
        n.pop();
        c = o.top()[0];
        o.pop();
        r = do_it(p2, p1, c);
        n.push(to_string(r));
    }

    return stoi(n.top());
}