#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int count = 0;

bool isEmpty()
{
    return front == nullptr;
}

void enqueue(int x)
{
    Node* n = new Node();
    n->data = x;
    n->next = nullptr;

    if (!rear)
    {
        front = rear = n;
        count++;
        return;
    }

    rear->next = n;
    rear = n;
    count++;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return;
    }

    Node* t = front;
    front = front->next;

    if (!front)
        rear = nullptr;

    delete t;
    count--;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }

    return front->data;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }

    Node* t = front;
    while (t)
    {
        cout << t->data;
        if (t->next) cout << " -> ";
        t = t->next;
    }

    cout << "\n";
    cout << "Size: " << count << "\n";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout << "Front: " << peek() << "\n";
    dequeue();
    cout << "After dequeue: "; display();
    dequeue();
    dequeue();
    dequeue(); // underflow
    return 0;
}
