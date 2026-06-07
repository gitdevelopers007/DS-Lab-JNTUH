#include <stdio.h>

int multiplicationMethod(int key, int tableSize)
{
    double a = 0.618033;
    double product = key * a;
    double fraction = product - (int)product;

    return (int)(tableSize * fraction);
}

int main()
{
    int key, tableSize;

    printf("Multiplication Method\n");

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter hash table size: ");
    scanf("%d", &tableSize);

    printf("Hash Value: %d\n",
           multiplicationMethod(key, tableSize));

    return 0;
}


//Multiplication Method

Enter key: 1234
Enter hash table size: 10

Hash Value: 6//
