#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int value;
    struct No *next;
} No;

No* create(int value){
    No* new = (No*) malloc(sizeof(No));
    new->value = value;
    new->next = NULL;
    return new;
}

void insertIntoStart(No **list, int value){
    No* new = create(value);
    new->next = *list;
    *list = new;
}

void show(No *list){
    while(list != NULL){
        printf("%d -> ", list->value);
        list = list->next;
    }
    printf("NULL\n");
}

int main(){

//    No* list = create(1);
    No* list = NULL;
    insertIntoStart(&list, 1);
    insertIntoStart(&list, 2);
    insertIntoStart(&list, 3);
    show(list);

    return 0;
}