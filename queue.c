#include <stdio.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q){
    return q->rear < q->front;
}

int isFull(Queue *q){
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front++];
}

int main(){
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}