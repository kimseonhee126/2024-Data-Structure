#include <stdio.h>

void swap(int **px, int **py)
{
    int *temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    int a = 1, b = 2;
    int *ap = &a, *bp = &b;
    printf("a = %d, b = %d\n", a, b);
    swap(&ap, &bp);
    printf("a = %d, b = %d\n", *ap, *bp);
    return 0;
}