#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_at_pos(struct node* head, int data, int pos){
    struct node *ptr, *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    ptr = head;
    pos--;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    new->next = ptr->next;
    ptr->next = new;
}

struct node* insert_at_start(struct node* head, int data){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void insert_at_end(struct node* head, int data){
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
}

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

    insert_at_end(head, 67);
    print_list(head);
    printf("\n");
    head = insert_at_start(head, 99);
    print_list(head);
    printf("\n");
    insert_at_pos(head, 21, 4);
    print_list(head);
}