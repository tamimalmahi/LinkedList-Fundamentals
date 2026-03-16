#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* dlt_1st_node(struct node* head){
    if(head == NULL) printf("The list is already empty!\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }else
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        return head;
    }
}

struct node* dlt_last_node(struct node* head){
    if(head == NULL) printf("The list is already empty!\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        struct node *temp, *temp2;
        temp = head, temp2 = head;
        while(temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
        return head;
    }
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
    printf("\n");
    head = dlt_1st_node(head);
    print_list(head);
    printf("\n");
    head = dlt_last_node(head);
    head = dlt_last_node(head);
    // head = dlt_last_node(head);
    print_list(head);
    
    return 0;
}