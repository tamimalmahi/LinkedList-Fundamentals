#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main(){
    struct node* head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node* current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 9;
    current->next = NULL;
    head->next = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 12;
    current->next = NULL;
    head->next->next = current;

    printf("The linkedlist: %d %d %d", head->data, head->next->data, head->next->next->data);
    return 0;
}