#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* head, int data){
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else{
        ptr = head;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}

struct node* pop(struct node* head){
    if(head == NULL) printf("The queue is empty\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    } else
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        return head;
    }
}

void display(struct node* head){
    int i = 1;
    if(head == NULL) printf("The list is empty.\n");
    else
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("%d. %d\t",i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}

int main(){
    struct node* head = NULL;
    head = push(head, 15);
    head = push(head, 27);
    head = push(head, 21);
    display(head);
    printf("\n");
    head = pop(head);
    display(head);
}