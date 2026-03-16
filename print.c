#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_list(struct node* head){
    if(head == NULL) printf("The list is empty.\n");
    else
    {
        struct node* temp = head;
        int i = 1;
        while(temp != NULL)
        {
            printf("%d. %d\n",i, temp->data);
            i++;
            temp = temp->next;
        }
    }
}

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

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 12;
    current->next = NULL;
    head->next->next = current;

    print_list(head);
    return 0;
}