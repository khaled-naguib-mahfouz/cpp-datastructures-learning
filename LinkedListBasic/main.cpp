#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            std::cout << "Stack underflow, cannot pop from an empty stack." << std::endl;
        }
    }

    T peek() const {
        if (top != nullptr) {
            return top->data;
        } else {
            std::cerr << "Stack is empty, cannot peek." << std::endl;
            return T();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top of the stack: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Top of the stack after pop: " << myStack.peek() << std::endl;

    return 0;
}
