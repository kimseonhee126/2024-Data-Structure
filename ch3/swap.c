#include <stdio.h>

void swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    int a = 1;
    int b = 2;

    printf("함수 호출 하기 전! : a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("함수 호출 한 후! : a=%d, b=%d\n", a, b);

    return 0;
}