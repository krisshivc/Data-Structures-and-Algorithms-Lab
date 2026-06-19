#include <iostream>
using namespace std;

const int MAX = 100;

int heap[MAX];
int heapSize = 0;

void swapVal(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

bool isFull()
{
    return heapSize == MAX;
}

bool isEmpty()
{
    return heapSize == 0;
}

void insert(int x)
{
    if (isFull())
    {
        cout << "Priority Queue is full\n";
        return;
    }

    heap[heapSize] = x;
    int i = heapSize++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swapVal(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heapSize && heap[l] > heap[largest]) largest = l;
    if (r < heapSize && heap[r] > heap[largest]) largest = r;

    if (largest != i)
    {
        swapVal(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

int extractMax()
{
    if (isEmpty())
    {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return max;
}

int peekMax()
{
    if (isEmpty())
    {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    return heap[0];
}

void display()
{
    if (isEmpty())
    {
        cout << "Priority Queue is empty\n";
        return;
    }

    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";

    cout << "\n";
}

int main()
{
    insert(5);
    insert(1);
    insert(9);
    insert(3);
    insert(7);
    cout << "Heap: "; display();
    cout << "Max: " << peekMax() << "\n";

    cout << "Extracting: ";
    while (!isEmpty())
        cout << extractMax() << " ";

    cout << "\n";
    extractMax(); // empty
    return 0;
}
