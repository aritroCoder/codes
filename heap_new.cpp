#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

vector<int> heapsort;


void printArray(int* arr, int size){
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void max_heapify(int* head, int size, int n)
{
    // cout<<"heapify";
    int largest_index = n;
    int left = 2 * n + 1;
    int right = 2 * n + 2;
    if (left < size && head[largest_index] < head[left])
        largest_index = left;
    if (right < size && head[largest_index] < head[right])
        largest_index = right;

    // cout<<largest_index<<" "<<left<<" "<<right<< " "<< n<<endl;
    if (largest_index != n)
    {
        swap(head[largest_index], head[n]);
        // cout<<"heapify";
        // printArray(head, largest_index);
        max_heapify(head, size, largest_index);
    }
}

void build_max_heap(int* arr, int size)
{
    for (int i = floor(size/2); i >= 0; i--)
    {
        max_heapify(arr, size, i);
        // printArray(arr, size);
    }

}
void max_heapSort(int *arr, int size){
    int size_cp = size;
    for(int i = 0 ; i<size_cp ; i++){
        build_max_heap(arr, size);
        swap(arr[0], arr[size-1]);
        size--;
    }
}

int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // build_max_heap(arr, sizeof(arr)/sizeof(int));
    max_heapSort(arr, sizeof(arr)/sizeof(int));
    printArray(arr, sizeof(arr)/sizeof(int));
    return 0;
}