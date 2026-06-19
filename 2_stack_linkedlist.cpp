#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;
int count = 0;

void push(int x)
{
    Node* n = new Node();
    n->data = x;
    n->next = top;
    top = n;
    count++;
}

void pop()
{
    if (!top)
    {
        cout << "Stack Underflow\n";
        return;
    }

    Node* t = top;
    top = top->next;
    delete t;
    count--;
}

int peek()
{
    if (!top)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    return top->data;
}

bool isEmpty()
{
    return top == nullptr;
}

void display()
{
    if (!top)
    {
        cout << "Stack is empty\n";
        return;
    }

    Node* t = top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }

    cout << "\n";
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    cout << "Top: " << peek() << "\n";
    pop();
    cout << "After pop: " << peek() << "\n";
    pop();
    pop();
    pop(); // underflow
    return 0;
}
