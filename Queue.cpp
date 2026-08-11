#include<iostream>
// #include<queue>
using namespace std;
#define n 5

int front = 0, rear = 0,queue[n];
void enqueue(int x)
{
    if(rear >= n)
    {
        cout << "OVERFLOW!!!";
        return;
    }

    rear = rear + 1;
    queue[rear] = x;

    if(front == 0)
    {
        front = 1;
    }
}

void dequeue()
{
    // queue already empty
    if(front == 0)
    {
        cout<<"UNDERFLOW!!!";
        exit(1);
    }
    
    int x = queue[front];

    if(front == rear)
    {
        front = 0;
        rear = 0;
    }
    else{
        front = front + 1;
    }
    cout<<"Element Deleted from the queue is : "<<x<<endl;
}
void display(){
    for(int i = front; i<=rear; i++)
    {
        cout << queue[i] << endl;
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
                cin>>x;
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
                break;
            default:
                cout << "Invalid Case";
            }
    }
}