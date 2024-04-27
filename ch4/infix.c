#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mm_malloc.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType *s)
{
    s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
    return 0;
}

// 삽입 함수
void push(LinkedStackType *s, element item)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

// 출력 함수
void print_stack(LinkedStackType *s)
{
    for (StackNode *p = s->top; p!= NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL \n");
}

// 삭제 함수
element pop(LinkedStackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택이 비어있음 \n");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

// main 함수
int main()
{
    // 입력수식 선택
    int num;

    // 수식 배열로 저장
    char exp[MAX_STACK_SIZE];
    
    printf("입력수식을 선택하세요.\n");
    printf("1. 전위식");
    printf("2. 중위식");
    printf("3. 후위식");
    printf("4. 종  료");
    scanf("%d", &num);

    printf("\n");

    printf("수식을 입력하세요 : ");
    scanf("%s", exp);

    printf("\n");

    // 전위식 -> 후위식으로 변경

    // 후위식으로 계산하여 결과 출력

}