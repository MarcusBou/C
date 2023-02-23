#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void add(struct node** head_ref, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = *head_ref;

    if(*head_ref == NULL){
       *head_ref = newnode;
        newnode->prev = newnode;
        return;
    }

    while(last->next != *head_ref){
        last = last->next;
    }

    newnode->prev = last;
    last->next = newnode;
    return;
}

void printList(struct node* n)
{
    struct node *curr = n;
    while (curr->next != n) {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    struct node* head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = head;
    head->prev = head;
    head->data = 2;

    add(&head, 50);
    add(&head, 20);
    add(&head, 60);
    add(&head, 60);

    printList(head);

    return 0;
}
