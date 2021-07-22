// Building heap time complexity (n*logn)

#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (i != largest)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{

    int startIndex = (n - 2) / 2;

    // Reverse Level  Order Traversal
    for (int i = startIndex; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    // Binary Tree Representation
    // of input array
    //              1
    //           /     \
    //         3         5
    //      /    \     /  \
    //     4      6   13  10
    //    / \    / \
    //   9   8  15 17
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);
    // Final Heap:
    //              17
    //           /      \
    //         15         13
    //       /    \      /  \
    //      9      6    5   10
    //     / \    /  \
    //    4   8  3    1

    return 0;
}

// Sample Output
// Array representation of Heap is:
//17 15 13 9 6 5 10 4 8 3 1