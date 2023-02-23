#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};


void add(struct node** head_ref, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    newnode->data = value;
    newnode->next = *head_ref;

    if(*head_ref == NULL){
        *head_ref = newnode;
        return;
    }

    while(last->next != *head_ref){
        last = last->next;
    }
    last->next = newnode;
    return;
}

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
        struct node *curr = *head_ref;
        while(curr->next != *head_ref){
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->next = *head_ref;
        (*head_ref) = newnode;
        return;
    }

    for(int i = 0; i < index - 1; i++){
        if(last->next != *head_ref){
            last = last->next;
        }
        else{
            newnode->next = *head_ref;
            last->next = newnode;
            return;
        }
    }

    newnode->next = last->next;
    last->next = newnode;
    return;

}

void removeEle(struct node** head_ref, int index){
    struct node *last = *head_ref;
    if(*head_ref == NULL){
        return;
    }

    if(index == 0){
        struct node *curr = *head_ref;
        while(curr->next != *head_ref){
            curr = curr->next;
        }
        curr->next = last->next;
        (*head_ref) = last->next;
        return;
    }

    for(int i = 0; i < index - 1; i++){
        if(last->next == *head_ref){
            return;
        }
        last = last->next;
    }
    struct node *temp1 = last;
    last = last->next;
    struct node *deleteTemp = last;
    if(deleteTemp == *head_ref){
        return;
    }
    last = last->next;
    struct node *temp2 = last;
    temp1->next = temp2;
}

int ElementSearch(struct node* head_ref, int searchValue){
    struct node *last = head_ref;
    int i = 0;
    while(last->next != head_ref){
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
    struct node* current = n;
    while (current->next!= n) {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf(" %d ", current->data);
}

void printIndex(struct node* n, int index){
    struct node* current = n;
    for(int i = 0; i < index; i++){
        if(current->next == n){
            printf("Out of index");
            return;
        }
        current = current->next;
    }
    printf("\n%d",current->data);
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
    third->next = head;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);

    insert(&head, 0, 11);

    int e = ElementSearch(head, 10);

    printf("%d\n", e);

    removeEle(&head, 7);

    printList(head);

    printIndex(head, 2);
}
