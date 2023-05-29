#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Double linked list implementation
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void Insert_at_head(int x);
struct Node* getnewnode(int x);
void print();
void reverse_print();
void Insert_at_tail(int x);
struct Node* head;
int main(){
    head = NULL; 
    Insert_at_head(2);
    Insert_at_head(24);
    Insert_at_head(48);
    Insert_at_tail(90);
    Insert_at_tail(100);
    print();
    printf("\n");
    reverse_print();
    
}
struct Node* getnewnode(int x){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next =  NULL;
    return newnode;
}

void Insert_at_head(int x){
    struct Node* newnode = getnewnode(x);
    if (head==NULL){
        head = newnode;
        return;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void print(){
    struct Node* ptr;
    ptr = head;
     printf("printing of double linked list is ");
    while(ptr!=NULL){
        printf("%d \t ",ptr->data);
        ptr = ptr->next;
    }
}

void reverse_print(){
    struct Node* ptr2; 
    ptr2 = head;
    while(ptr2->next!=NULL){
        ptr2 = ptr2->next;
    }
    printf("Reverse of double linked list is ");
    while(ptr2!=NULL){
        printf("%d \t",ptr2->data);
        ptr2 = ptr2->prev;
    }
 
  
}

void Insert_at_tail(int x){
    struct Node* tail = getnewnode(x);
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail->prev = temp;
    
    temp->next = tail;
    
    
}