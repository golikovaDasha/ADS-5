// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char a) {
    switch (a)
    {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    }
    return -1;
}
int calc(char op, int a, int b) {
    switch (op)
    {
    case '+': return (a + b);
    case '-': return (a - b);
    case '*': return (a * b);
    case '/': if (b!=0) return (a / b);
    }
    return 0;
}
std::string infx2pstfx(std::string inf) {
    TStack <char, 100> stack;
    std::string res;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] == -1) {
            res.push_back(inf[i]+' ');
        }
        else {
            if (priority(inf[i] == 0)) {
            stack.push();
            }
            else if (stack.isEmpty()) {
                stack.push(inf[i]);
            }
            else if (priority(inf[i]) < priority(stack.get())) {
                stack.push(inf[i]);
            }
            else if (priority(inf[i]) == 1) {
                while (stack.get() != 0) {
                    res.push_back(stack.get()+' ');
                    stack.pop();
                }
                stack.pop();
            }
            else {
                while ((!stack.isEmpty()) && (priority(inf[i]) > priority(stack.get()))) {
                    res.push_back(stack.get()+' ');
                    stack.pop();
                }
            }
        }
        while (!stack.isEmpty()) {
            res.push_back(stack.get()+' ');            
            stack.pop();
        }

    }
    return res;
}


int eval(std::string pref) { 
    TStack <int, 100> stack1;
    int res = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (priority(pref[i] == 4)) {
            stack1.push(pref[i] - '0');
        }
        else if (priority(pref[i]) < 4) {
            int x = stack1.get();
            stack1.pop();
            int y = stack1.get();
            stack1.pop();
            stack1.push(calc(pref[i], y, x));
        }
    }
    res = stack1.get();
    return res;
   }
