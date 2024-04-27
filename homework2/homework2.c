#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// element 구조체 선언
typedef struct
{
    char name[100];
} element;

typedef struct
{
    element data;
    struct ListNode *link;
} ListNode;

// 에러함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 삽입함수
ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 탐색함수
ListNode* search_list(ListNode *head, element x)
{
    ListNode *p = head;

    while (p != NULL)
    {
        if (strcmp((p->data.name), x.name) == 0)
            return p;
        p = p->link;
    }
    return NULL;
}

// 삭제함수
ListNode delete(ListNode *head, ListNode *pre)
{
    ListNode *removed = NULL;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
}

// split 함수
void split_list(ListNode *head, ListNode *p)
{
    ListNode *temp = head;
    printf("\n");
    printf("list1: ");

    while (temp != p->link)
    {
        printf("%s-> ", temp->data.name);
        temp = temp->link;
    }
    printf("NULL");
    printf("\n");

    temp = p->link;
    printf("list2: ");
    printf("head2-> ");
    while (temp != NULL) 
    {
        printf("%s-> ", temp->data.name);
        temp = temp->link;
    }
    printf("NULL");
}

// 출력함수
void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%s-> ", p->data.name);
    printf("NULL\n");
}

// 메인함수
int main(void)
{
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "PEACH");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "MELON");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "MANGO");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "LEMON");
    head = insert_first(head, data);
    // print_list(head);
    
    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    // print_list(head);

    strcpy(data.name, "head1");
    head = insert_first(head, data);
    print_list(head);

    // 삭제할 단어 입력 받기
    char delete_word[100];
    printf("삭제 단어: ");
    scanf("%s", delete_word);
    strcpy(data.name, delete_word);

    ListNode *p = head;
    ListNode *pre = head;

    // 삭제할 수 있게 전 노드인 pre 구하기
    while (p != NULL && strcmp(p->data.name, data.name) != 0)
    {
        p = p->link;
        if (strcmp(p->data.name, data.name) != 0)
        {
            pre = pre->link;
        }
    }
    // 삭제하기
    delete(head, pre);

    // split 함수 결과 출력하기
    printf("\n");
    print_list(head);
    split_list(head, pre);
    return 0;
}