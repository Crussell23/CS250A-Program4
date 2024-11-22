#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class SpecialStack
{
    private:
        stack<int> mainStack;

    public:
        SpecialStack();
        void push(int value);
        void pop();
        int peek();
        bool empty();
        void printStack();
        void popEven();
        void popOdd();

};

#endif // SPECIALSTACK_H

