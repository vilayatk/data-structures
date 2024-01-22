#include <iostream>

class Stack {
    const static int n = 5;
    int top = -1;
    int array[n];

public:
    void push(int value) {
        if (n == top + 1) {
            std::cout << "Exception: Overflow" << std::endl;
            return;
        }
        top++;
        array[top] = value;
    }

    void pop() {
        if (top == -1) {
            std::cout << "Exception: Underflow" << std::endl;
            return;
        }
        array[top] = 0;
        top--;
    }

    void print() {
        std::cout << "top points to " << array[top]<< std::endl;
        for(int i = top; i >=0 ; i--) {
            std::cout << "[" << array[i] << "]" << "=";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(1); // Overflow
    s.print();

    s.pop();
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop(); // Underflow
}