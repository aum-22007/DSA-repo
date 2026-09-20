#include <iostream>
using namespace std;

#define MAX 10

class Stack
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;
    int count;

public:

    // Constructor
    Stack()
    {
        top = nullptr;
        count = 0;
    }

    // PUSH operation
    void push(int value)
    {
        if (count == MAX)
        {
            cout << "Stack Overflow";
            exit(0);
        }

        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;

        top = newNode;
        count++;
    }

    // POP operation
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow";
            exit(0);
        }

        Node* temp = top;

        top = top->next;

        delete temp;

        count--;
    }

    // CHANGE operation
    // Index is counted from TOP, starting from 1
    void change(int index, int value)
    {
        if (index <= 0 || index > count)
        {
            cout << "Indexed item not present in stack";
            exit(0);
        }

        Node* temp = top;

        // Move to the required position from TOP
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }

        temp->data = value;
    }

    // DISPLAY operation
    // Display from TOP to bottom
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
            return;
        }

        Node* temp = top;

        while (temp != nullptr)
        {
            cout << temp->data;

            if (temp->next != nullptr)
            {
                cout << " ";
            }

            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;

    int code;

    while (cin >> code)
    {
        // PUSH
        if (code == 1)
        {
            int value;

            cin >> value;

            s.push(value);
        }

        // POP
        else if (code == 2)
        {
            s.pop();
        }

        // CHANGE
        else if (code == 3)
        {
            int index, value;

            cin >> index >> value;

            s.change(index, value);
        }

        // DISPLAY
        else if (code == 4)
        {
            s.display();
            break;
        }

        // Invalid operation
        else
        {
            cout << "Operation not supported";
            break;
        }
    }

    return 0;
}