#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main(){
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node* current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 9;
    current->next = NULL;

    head->next = current;

    printf("%d\n", head->data);
    printf("%d", head->next->data);
}