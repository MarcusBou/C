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
    newnode->next = NULL;

    if(*head_ref == NULL){
       *head_ref = newnode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    newnode->prev = last;
    last->next = newnode;
    return;
}

void insert(struct node** head_ref, int index, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    newnode->data = value;

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head_ref == NULL){
        *head_ref = newnode;
        newnode->next = *head_ref;
        return;
    }

    if(index == 0){
        newnode->next = *head_ref;
        (*head_ref) = newnode;
        return;
    }

    for(int i = 0; i < index - 1; i++){
        if(last->next != *head_ref){
            last = last->next;
        }
        else{
            newnode->next = NULL;
            newnode->prev = last;
            last->next = newnode;
            return;
        }
    }

    newnode->next = last->next;
    newnode->prev = last;
    last->next = newnode;
    return;

}

void removeEle(struct node** head_ref, int index){
    struct node *last = *head_ref;
    if(*head_ref == NULL){
        return;
    }

    if(index == 0){
        last->prev = NULL;
        (*head_ref) = last->next;
    }

    for(int i = 0; i < index - 1; i++){
        if(last == NULL){
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
    temp1->prev = temp1;
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

int main()
{
    struct node* head = NULL;

    add(&head, 50);
    add(&head, 20);
    add(&head, 30);

    insert(&head, 0, 529);

    removeEle(&head, 2);

    printList(head);

    int idx = ElementSearch(head, 30);
    printf("\n%d", idx);

    printIndex(head, idx);

    return 0;
}
