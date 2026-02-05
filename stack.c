#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX_SIZE - 1;
}

void push(int value){
    if(isFull()){
        printf("Stack overflow! Cannot add more elements.\n");
    } else{
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow! Cannot remove elements. \n");
        return -1;
    } else{
        int item = stack[top--];
        printf("Popped %d from the stack.\n", item);
        return item;
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack is empty.\n");
        return -1;
    } else{
        return stack[top];
    }
}

int main(){

    push(10);
    push(20);
    push(30);

    printf("Top element is %d.\n", peek());

    pop();
    pop();
    pop();
    pop();

    return 0;
}