#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mm_malloc.h>
#define MAX_STACK_SIZE 100

// ==================== 링크드리스트 연산 시작 ====================

typedef char element;

typedef struct StackNode
{
    element data;
    struct StackNode *link;
} StackNode;

typedef struct
{
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

// 피크 함수
element peek(LinkedStackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->top->data;
}

// 출력 함수
void print_stack(LinkedStackType *s)
{
    for (StackNode *p = s->top; p != NULL; p = p->link)
    {
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
    else
    {
        StackNode *temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}
// ==================== 링크드리스트 연산 끝 ====================

// 괄호검사
int check_matching(const char *in)
{
    LinkedStackType s;
    char ch, open_ch;

    int i, n = strlen(in);
    init(&s);

    for (i = 0; i < n; i++)
    {
        ch = in[i];

        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            // printf("push 된 아이템 확인 : %c \n", ch);
            push(&s, ch);
            break;

        case ')':
        case ']':
        case '}':
            // printf("pop 된 아이템 확인 : %c \n", ch);
            if (is_empty(&s))
            {
                return 0;
            }
            else
            {
                open_ch = pop(&s);

                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
                {
                    return 0;
                }
                break;
            }
        }
    }

    if (!is_empty(&s))
    {
        return 0;
    }
    return 1;
}

// 연산자의 우선순위를 반환
int prec(char op)
{
    switch (op)
    {
    case '(':case ')':
        return 0;
    case '+':case '-':
        return 1;
    case '*':case '/':
        return 2;
    }
    return -1;
}

// 중위식 -> 후위식으로 변환
char* infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);

    char changeArray[MAX_STACK_SIZE];

    LinkedStackType s;

    init(&s);

    int index = 0;
    for ( i = 0; i < len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
            {
                changeArray[index++] = pop(&s);
                // printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        
        case '(':
            push(&s, ch);
            break;
        
        case ')':
            top_op = pop(&s);
            while (top_op != '(')
            {
                changeArray[index++] = top_op; // 변경: 스택에서 pop한 연산자를 changeArray에 저장
                top_op = pop(&s);
            }
            break;

        default:
            changeArray[index++] = ch; // 변경: 피연산자는 바로 changeArray에 저장
            break;
        }
    }

    while (!is_empty(&s))
    {
        changeArray[index++] = pop(&s); // 변경: 스택에 남은 연산자를 changeArray에 저장
    }
    changeArray[index] = '\0'; // 문자열 끝에 널 종료 문자 추가

    return changeArray;
}

// 후위식 계산
int eval(char exp[])
{
    int op1, op2;                   // 계산을 위한 변수 설정
    int len = strlen(exp);          // 문자열 길이
    char ch;

    LinkedStackType s;
    init(&s);

    for (int i = 0; i < len; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            int value = ch - '0';
            push(&s, value);
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch)
            {
            case '+':
                push(&s, op1 + op2);
                break;

            case '-':
                push(&s, op1 - op2);
                break;

            case '*':
                push(&s, op1 * op2);
                break;

            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

// main 함수
int main()
{
    // 입력수식 선택
    int num;

    // 수식 배열로 저장
    char exp[MAX_STACK_SIZE];

    printf("입력수식을 선택하세요 : \n");
    printf("1. 전위식\n");
    printf("2. 중위식\n");
    printf("3. 후위식\n");
    printf("4. 종  료\n");
    printf("선택 : ");
    scanf("%d", &num);

    printf("\n");

    printf("수식을 입력하세요 : ");
    scanf("%s", exp);

    printf("\n");

    // 중위식 출력
    printf("중위식 : %s\n\n", exp);

    // 괄호 검사
    int check_matching_result = check_matching(exp);
    // printf("괄호검사 작동 확인 : %d\n", check_matching_result);

    if (check_matching_result == 1)
    {
        printf("괄호검사에 성공했습니다!\n\n");
    }
    else
    {
        printf("괄호검사에 실패했습니다!\n\n");
        exit(1);
    }

    char postfix[MAX_STACK_SIZE];                       // 변환된 후위식 저장할 배열

    // 후위식으로 계산하여 결과 출력
    char* postfixPointer = infix_to_postfix(exp);       // postfixPointer 는 infix_to_postfix 에서 반환한 changeArray 받는 포인터 변수
    strcpy(postfix, postfixPointer);                    // postfix 배열에 저장
    printf("후위식 : %s\n", postfix);
    printf("\n");

    // 후위식으로 계산
    int result = eval(postfix);
    printf("후위식으로 계산 : %d", result);

    return 0;
}