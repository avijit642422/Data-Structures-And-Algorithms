#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void create(){
    struct node *head=NULL;
    struct node *first=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    first=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    if(first==NULL || second==NULL || third==NULL){
        printf("memory allocation faild");
        free(first);
        free(second);
        free(third);
        return;
    }else{
    first->data=10;
    second->data=20;
    third->data=30;

    first->prev=NULL;
    second->prev=first;
    third->prev=second;

    first->next=second;
    second->next=third;
    third->next=NULL;
    head=first;
    }
}
    void traversal(){
        struct node *current;
        current=head;
        while(current !=NULL){
            printf("%d",current->data);
            current=current-> next;

        }

    }
    // 3. Insert at Beginning
struct node *insertBeginning(struct node *head,int data) {
   struct node *newnode;
   newnode =( struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory Allocation Failed\n");
        return head;
    }

    newnode->data = data;
    newnode->prev=NULL;
    newnode->next = head;
    if(head !=NULL){
        head->prev=NULL;
    }
    head = newnode;
    return head;
}
struct node *insertend(int data) {
   struct node *newnode;
   struct node *current;
   newnode =( struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory Allocation Failed\n");
        return head;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return head;
    }
    current=head;
    while(current->next !=NULL){
        current->next=newnode;
        newnode->prev=current;
        return head;
    }
}
void deletebeg(){
    struct node *temp;
    if(head==NULL){
        printf("list empty");
        return;
    }
    temp=head;
    head=head->next;
    if(head !=NULL){
        head->prev=NULL;
    }
    free(temp);
}
void deleteend(){
    struct node *temp;
    if(head==NULL){
        printf("list empty");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct node *current;
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);

}

  int main(){
        create();
        traversal();
        insertbeg(5);
        insertend(40);
        deletebeg();
        deleteend();
        return 0;
    }
 
