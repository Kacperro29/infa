#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Dodano element: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stos pusty. Nie można usunąć elementu." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Usunięto element: " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stos pusty." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Górny element stosu: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
