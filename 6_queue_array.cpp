#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX];
int front = 0;
int rear = 0;

bool isFull()
{
    return rear == MAX;
}

bool isEmpty()
{
    return front == rear;
}

void enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow\n";
        return;
    }

    arr[rear++] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return;
    }

    front++;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }

    return arr[front];
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = front; i < rear; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    cout << "Front: " << peek() << "\n";
    dequeue();
    cout << "After dequeue: " << peek() << "\n";
    dequeue();
    dequeue();
    dequeue(); // underflow
    return 0;
}
