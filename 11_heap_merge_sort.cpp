#include <iostream>
using namespace std;

void swapVal(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void print(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty\n";
        return;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

// =====================
//      HEAP SORT
// =====================

void heapify(int arr[], int n, int i)
{
    if (n <= 0 || i < 0 || i >= n)
        return;

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i)
    {
        swapVal(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    if (n <= 1)
    {
        cout << "Nothing to sort\n";
        return;
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swapVal(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// =====================
//     MERGE SORT
// =====================

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < 0 || r < 0)
    {
        cout << "Invalid indices\n";
        return;
    }

    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int a[] = {5, 3, 8, 1, 9, 2};
    int n = 6;

    cout << "Before Heap Sort:  "; print(a, n);
    heapSort(a, n);
    cout << "After Heap Sort:   "; print(a, n);

    cout << "\n";

    int b[] = {5, 3, 8, 1, 9, 2};
    cout << "Before Merge Sort: "; print(b, n);
    mergeSort(b, 0, n - 1);
    cout << "After Merge Sort:  "; print(b, n);

    int empty[] = {};
    heapSort(empty, 0);
    return 0;
}
