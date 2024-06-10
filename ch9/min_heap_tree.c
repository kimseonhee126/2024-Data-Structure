#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct
{
    int key;
} element;

typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성함수
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}

// 삽입 함수
void insert_min_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);

    // 부모 노드와 비교하여 더 작으면 위로 올림
    while ((i != 1) && (item.key < h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}


// 삭제 함수
element delete_min_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 루트 노드 값을 반환할 item에 저장
    temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 저장하고 힙 크기를 줄임
    parent = 1;
    child = 2;

    while (child <= h->heap_size)
    {
        // 자식 노드 중 더 작은 값을 찾음
        if((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
        {
            child++;
        }

        // temp의 값이 자식 노드의 값보다 작으면 종료
        if (temp.key <= h->heap[child].key)
        {
            break;
        }

        // 자식 노드의 값을 부모 노드로 올림
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp; // temp 값을 부모 노드에 저장
    return item;
}


// main 함수
int main()
{
    element e1 = {10}, e2 = {30}, e3 = {5};
    element e4, e5, e6;
    HeapType* heap;

    heap = create();
    init(heap);

    insert_min_heap(heap, e1);
    insert_min_heap(heap, e2);
    insert_min_heap(heap, e3);

    e4 = delete_min_heap(heap);
    printf("< %d > ", e4.key);

    e5 = delete_min_heap(heap);
    printf("< %d > ", e5.key);

    e6 = delete_min_heap(heap);
    printf("< %d > ", e6.key);

    free(heap);
    return 0;
}