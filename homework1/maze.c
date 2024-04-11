/*
숙제 #1 미로탐색

기한 : 
학번 : 202100249
이름 : 김선희
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 6
#define MAX_SIZE 100

//
typedef struct element
{
    short r;
    short c;
} element;

//
typedef struct StackType
{
    element data[MAX_SIZE];
    int top;
} StackType;

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
	{'e', '0', '0', '0', '1', '1'},
	{'1', '1', '0', '1', '1', '1'},
	{'1', '1', '0', '1', '1', '1'},
	{'1', '0', '0', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

//
void init_stack(StackType *s) {
    s->top = -1;
}

//
int is_empty(StackType *s) {
    return (s->top == -1);
}

// 
int is_full(StackType *s) {
    return (s->top == MAZE_SIZE - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러 \n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

// 
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

// 
void push_loc(StackType *s, int r, int c) {
    if (r < 0 || c < 0) return;

    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element temp;
        temp.r = r;
        temp.c = c;
        push(s, temp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");

    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }

        printf("\n");
    }
}

// 교재에 있는 메인함수
int main(void) {
    int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)){
			printf("\n실패!\n");
			exit(1);
		}
		else {
            here = pop(&s);
        }
	}
	printf("\n성공!\n");
	return 0;
}