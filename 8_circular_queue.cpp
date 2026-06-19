#include <iostream>
using namespace std;

const int SIZE = 5;

int arr[SIZE];
int front = -1;
int rear = -1;
int count = 0;

bool isFull()
{
    return count == SIZE;
}

bool isEmpty()
{
    return count == 0;
}

void enqueue(int x)
{
    if (isFull())
    {
        cout << "Circular Queue Overflow\n";
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % SIZE;
    arr[rear] = x;
    count++;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Circular Queue Underflow\n";
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
        count--;
        return;
    }

    front = (front + 1) % SIZE;
    count--;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Circular Queue is empty\n";
        return -1;
    }

    return arr[front];
}

void display()
{
    if (isEmpty())
    {
        cout << "Circular Queue is empty\n";
        return;
    }

    cout << "Elements: ";
    int i = front;
    int printed = 0;
    while (printed < count)
    {
        cout << arr[i] << " ";
        i = (i + 1) % SIZE;
        printed++;
    }

    cout << "\n";
    cout << "Front=" << front << " Rear=" << rear << " Count=" << count << "/" << SIZE << "\n";
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    enqueue(6); // overflow
    dequeue();
    dequeue();
    display();
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // underflow
    return 0;
}
