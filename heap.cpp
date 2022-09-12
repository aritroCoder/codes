#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void max_heapify(int* head, int i, int size){ //i is index where we have to run max_heapify
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < size && head[left] > head[largest])
        largest = left;
    if(right < size && head[right] > head[largest])
        largest = right;
    if(largest != i){
        swap(head[i], head[largest]);
        max_heapify(head, largest, size);
    }
}

void build_max_heap(int* head, int size){
    for (int i = floor(size/2); i >=0; i--)
    {
        max_heapify(head, i, size);
    }
    
}

int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    build_max_heap(arr, sizeof(arr)/sizeof(int));
    //printing the array
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}