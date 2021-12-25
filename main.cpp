// Priority queue using array
#include <iostream>
using namespace std;

int heapSize = 0;

void minHeapify(int heap[], int heapSize, int node)
{
    int minValuePIn = node;
    int leftCIn = 2 * node + 1;
    int rightCIn = 2 * node + 2;

    if(leftCIn < heapSize && heap[leftCIn] < heap[minValuePIn])
    {
        minValuePIn = leftCIn;
    }
    if(rightCIn < heapSize && heap[rightCIn] < heap[minValuePIn])
    {
        minValuePIn = rightCIn;
    }

    if(minValuePIn != node)
    {
        swap(heap[node], heap[minValuePIn]);

        minHeapify(heap, heapSize, minValuePIn);
    }

}

void printHeap(int heap[], int heapSize)
{
    for(int i=0; i<heapSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void delElement(int heap[], int data){
    int found;
    for(int i=0; i<heapSize; i++)
    {
        if(heap[i] == data){
            found = i;
            break;
        }
    }

    swap(heap[found], heap[heapSize-1]);
    heapSize--;
    for(int i=heapSize/2-1; i>=0; i--){
        minHeapify(heap, heapSize, i);
    }

}

void insertElement(int heap[], int data){
    heap[heapSize] = data;
    heapSize++;

    for(int i=heapSize/2-1; i>=0; i--){
        minHeapify(heap, heapSize, i);
    }
}

int peekMin(int heap[]){
    return heap[0];
}

int main()
{

    int heap[20], smallest;

    insertElement(heap, 9);
    insertElement(heap, 7);
    insertElement(heap, 0);
    insertElement(heap, 3);
    insertElement(heap, 5);

    printHeap(heap, heapSize);

    delElement(heap, 9);

    smallest = peekMin(heap);


    printHeap(heap, heapSize);

    return 21;
}