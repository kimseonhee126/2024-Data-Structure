#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// page : 122

// ===== 스택 코드의 시작 =====
typedef char element;

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 초기화 함수
void init_stack(StackType *s) {
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType *s, element item) {
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러 \n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

// 삭제함수
element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

// 피크 함수
element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else return s->data[s->top];
}

// ===== 스택 코드의 시작 =====

int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch)
        {
        case '(': case '[': case '{':
            push(&s,ch);
            break;
        
        case ')': case ']': case '}':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);

                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        }
    }

    if (!is_empty(&s)) return 0;
    return 1;
}

int main(void) {
    char *p = "{ A[(i+1)]=0; }";

    if (check_matching(p) == 1) {
        printf("%s 괄호 검사 성공\n", p);
    }
    else {
        printf("%s 괄호 검사 실패 \n", p);
    }
    return 0;
}