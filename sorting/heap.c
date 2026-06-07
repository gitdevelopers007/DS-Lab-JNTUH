#include <stdio.h>
#define MAX 100
// Function to insert an element into Max Heap
void insertHeap(int heap[], int *n, int value)
{
int i;
// Increase heap size
(*n)++;
i = *n;
// Insert element at correct position
while (i > 1 && value > heap[i / 2])
{
heap[i] = heap[i / 2];
i = i / 2;
}
heap[i] = value;
}
// Function to delete root element from Max Heap
int deleteHeap(int heap[], int *n)
{
int parent, child;
int item, temp;
item = heap[1]; // Root element
temp = heap[*n]; // Last element
(*n)--;
parent = 1;
child = 2;
while (child <= *n)
{
// Select larger child
if (child < *n && heap[child] < heap[child + 1])
child++;
// Correct position found
if (temp >= heap[child])
break;
heap[parent] = heap[child];
parent = child;
child = child * 2;
}
heap[parent] = temp;
return item;
}
// Heap Sort Function
void heapSort(int arr[], int n)
{
int heap[MAX];
int heapSize = 0;
int i;
// Step 1: Build Heap
for (i = 0; i < n; i++)
{
insertHeap(heap, &heapSize, arr[i]);
}
// Step 2: Repeatedly delete root element
for (i = n - 1; i >= 0; i--)
{
arr[i] = deleteHeap(heap, &heapSize);
}
}
// Display array
void display(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}

printf("\n");
}
// Main Function
int main()
{
int arr[MAX], n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("\nOriginal Array:\n");
display(arr, n);
heapSort(arr, n);
printf("\nSorted Array in Ascending Order:\n");
display(arr, n);
return 0;
}


//Sample Output : Enter number of elements: 6
Enter elements:
45 12 78 23 9 56
Original Array:
45 12 78 23 9 56
Sorted Array in Ascending Order:
9 12 23 45 56 78//