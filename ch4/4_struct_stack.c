#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct studentTag
{
    char name[10];
    int age;
    double gpa;
} student;

int main()
{
    student *p = (student *)malloc(sizeof(student));

    if (p == NULL)
    {
        fprintf(stderr, "메모리 부족\n");
        exit(1);
    }

    strcpy(p->name, "Park");
    (*p).age = 20;
    free(p);
    return 0;
}


typedef struct ListNode
{
    int data;
    struct ListNode *link;
} ListNode;

