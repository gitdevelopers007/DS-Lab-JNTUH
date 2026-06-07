#include <stdio.h>
void shellSort(int arr[], int n)
{
int gap, i, j, temp;
// Start with a big gap, then reduce the gap
for (gap = n / 2; gap > 0; gap = gap / 2)
{
// Perform insertion sort for this gap size
for (i = gap; i < n; i++)
{
temp = arr[i];
// Shift earlier gap-sorted elements up
// to find the correct location for arr[i]
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
{
arr[j] = arr[j - gap];
}
arr[j] = temp;
}
}
}
int main()
{
int n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d integers:\n", n);
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
shellSort(arr, n);
printf("Sorted array in ascending order:\n");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
return 0;
}


//Sample Output Enter number of elements: 6
Enter 6 integers:
45
12
78
34
23
9
Sorted array in ascending order:
9 12 23 34 45 78//