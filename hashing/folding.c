#include <stdio.h>

int foldingMethod(int key, int tableSize)
{
    int sum = 0;

    while(key > 0)
    {
        sum = sum + (key % 100);
        key = key / 100;
    }

    return sum % tableSize;
}

int main()
{
    int key, tableSize;

    printf("Folding Method\n");

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter hash table size: ");
    scanf("%d", &tableSize);

    printf("Hash Value: %d\n",
           foldingMethod(key, tableSize));

    return 0;
}


//Folding Method

Enter key: 1234
Enter hash table size: 10

Hash Value: 6//
