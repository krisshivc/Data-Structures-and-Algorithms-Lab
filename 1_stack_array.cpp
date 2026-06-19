#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }

    arr[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }

    top--;
}

int peek()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    return arr[top];
}

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX - 1;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    cout << "Top: " << peek() << "\n";
    pop();
    cout << "After pop: " << peek() << "\n";
    pop();
    pop();
    pop(); // underflow
    return 0;
}
