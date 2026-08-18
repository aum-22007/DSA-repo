#include<iostream>
using namespace std;

#define n 5

int front = 0, rear = 0, queue[n + 1];

void enqueue(int y)
{
    if(rear == n)
    {
        rear = 1;
    }
    else
    {
        rear = rear + 1;
    }
    if(front == rear)
    {
        cout << "OVERFLOW!!!" << endl;
        if(rear == 1)
        {
            rear = n;
        }
        else
        {
            rear = rear - 1;
        }

        return;
    }
    queue[rear] = y;
    if(front == 0)
    {
        front = 1;
    }
}

void dequeue()
{
    int y;
    if(front == 0)
    {
        cout << "UNDERFLOW!!!" << endl;
        return;
    }
    y = queue[front];
    if(front == rear)
    {
        front = 0;
        rear = 0;

        cout << "Element Deleted from the queue is : " << y << endl;
        return;
    }
    if(front == n)
    {
        front = 1;
    }
    else
    {
        front = front + 1;
    }

    cout << "Element Deleted from the queue is : " << y << endl;
}

void display()
{
    if(front == 0)
    {
        cout << "QUEUE IS EMPTY!!!" << endl;
        return;
    }

    int i = front;

    while(true)
    {
        cout << queue[i] << endl;

        if(i == rear)
        {
            break;
        }

        if(i == n)
        {
            i = 1;
        }
        else
        {
            i = i + 1;
        }
    }

    cout << endl;
}

int main()
{
    int choice;

    while(true)
    {
        cin >> choice;

        switch(choice)
        {
            case 1:
                int x;
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid Case" << endl;
        }
    }
}