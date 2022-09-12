#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

/**
Partition algo:
1. maintain a pointer j that iterates through the array.
2. maintain a pointer i that starts at the place before begining the array.
3. start the loop. Whenever we encounter a element whose value is less than the value of last element,increment i by 1 and swap array[i] with array[j].
4. after j has reached the end of the array, again increment i by 1 and swap array[i] with array[j].
5. This will create a partitioned array with i+1 th element as pivot.
6. Return i+1.
**/

int partition(int *arr, int start, int end)
{
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < arr[end])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void printArray(int *arr, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0;   // starting index of quicksort
    int end = n - 1; // end of array
    quickSort(arr, start, end);
    printArray(arr, n);
    return 0;
}