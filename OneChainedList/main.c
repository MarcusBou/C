#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** head_ref, int index, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    newnode->data = value;

    if(*head_ref == NULL){
        *head_ref = newnode;
        newnode->next = *head_ref;
        return;
    }

    if(index == 0){
        newnode->next = (*head_ref);
        (*head_ref) = newnode;
        return;
    }

    for(int i = 0; i < index - 1; i++){
        if(last->next != NULL){
            last = last->next;
        }
        else{
            newnode->next = NULL;
            last->next = newnode;
            return;
        }
    }

    newnode->next = last->next;
    last->next = newnode;
    return;

}

void add(struct node** head_ref, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    newnode->data = value;
    newnode->next = NULL;

    if(*head_ref == NULL){
        *head_ref = newnode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
    return;
}

void removeEle(struct node** head_ref, int index){
    struct node *last = *head_ref;
    if(*head_ref == NULL){
        return;
    }

    if(index == 0){
        (*head_ref) = last->next;
    }

    for(int i = 0; i < index - 1; i++){
        if(last->next == NULL){
            return;
        }
        last = last->next;
    }
    struct node *temp1 = last;
    last = last->next;
    struct node *deleteTemp = last;
    last = last->next;
    struct node *temp2 = last;
    temp1->next = temp2;
}

int ElementSearch(struct node* head_ref, int searchValue){
    struct node *last = head_ref;
    int i = 0;
    while(last != NULL){
        if(last->data == searchValue){
            return i;
        }
        i++;
        last = last->next;
    }
    return -1;
}

void printList(struct node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

void printIndex(struct node* n, int index){
    for(int i = 0; i < index; i++){
        if(n == NULL){
            printf("Out of index");
            return;
        }
        n = n->next;
    }
    printf("\n%d",n->data);
}

int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second ->next = third;

    third->data = 3;
    third->next = NULL;

    add(&head, 10);
    add(&head, 30);
    add(&head, 40);

    insert(&head, 0, 55);

    printList(head);

    removeEle(&head, 4);

    printf("\n");

    printList(head);

    int ele = ElementSearch(head, 10);

    printf("\n%d", ele);

    printIndex(head, ele);
}
