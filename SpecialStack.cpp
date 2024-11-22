#include "specialstack.h"

// Constructor
SpecialStack::SpecialStack() {}

// Push an element onto the stack
void SpecialStack::push(int value) {
    mainStack.push(value);
}

// Pop the top element from the stack
void SpecialStack::pop() {
    if (mainStack.empty()) {
        throw underflow_error("Stack is empty. Cannot pop.");
    }
    mainStack.pop();
}

// Peek at the top element without removing it
int SpecialStack::peek() {
    if (mainStack.empty()) {
        throw underflow_error("Stack is empty. Cannot peek.");
    }
    return mainStack.top();
}

// Check if the stack is empty
bool SpecialStack::empty() {
    return mainStack.empty();
}

// Print all elements in the stack
void SpecialStack::printStack() {
    if (mainStack.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<int> temp = mainStack;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}

// Pop the most recent even element
void SpecialStack::popEven() {
    if (mainStack.empty()) {
        throw underflow_error("Stack is empty. Cannot popEven.");
    }

    stack<int> tempStack;
    bool foundEven = false;

    // Transfer elements until the most recent even is found
    while (!mainStack.empty()) {
        int top = mainStack.top();
        mainStack.pop();

        if (!foundEven && top % 2 == 0) {
            foundEven = true;
            continue; // Skip pushing this even number into tempStack
        }

        tempStack.push(top);
    }

    // Restore the remaining elements back into the main stack
    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }

    // If no even number is found, throw an exception
    if (!foundEven) {
        throw underflow_error("No even number found to pop.");
    }
}

// Pop the most recent odd element
void SpecialStack::popOdd() {
    if (mainStack.empty()) {
        throw underflow_error("Stack is empty. Cannot popOdd.");
    }

    stack<int> tempStack;
    bool foundOdd = false;

    // Transfer elements until the most recent odd is found
    while (!mainStack.empty()) {
        int top = mainStack.top();
        mainStack.pop();

        if (!foundOdd && top % 2 != 0) {
            foundOdd = true;
            continue; // Skip pushing this odd number into tempStack
        }

        tempStack.push(top);
    }

    // Restore the remaining elements back into the main stack
    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }

    // If no odd number is found, throw an exception
    if (!foundOdd) {
        throw underflow_error("No odd number found to pop.");
    }
}
