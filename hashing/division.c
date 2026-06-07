#include <stdio.h>

int divisionMethod(int key, int tableSize)
{
    return key % tableSize;
}

int main()
{
    int key, tableSize;

    printf("Division Method\n");

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter hash table size: ");
    scanf("%d", &tableSize);

    printf("Hash Value: %d\n",
           divisionMethod(key, tableSize));

    return 0;
}

//Division Method

Enter key: 1234
Enter hash table size: 10

Hash Value: 4 //