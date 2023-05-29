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
void Insert_between(int x,int ind);
struct Node* head;
int main(){
    head = NULL; 
    Insert_at_head(4);
    Insert_at_head(2);
    Insert_at_tail(6);
    Insert_between(3,2);
    
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


void Insert_between(int x,int ind){
    struct Node* tmp = getnewnode(x);
    struct Node* ptr = head;

    for(int i=1;i<ind-1;i++){
        ptr = ptr->next;
    }
    struct Node* store = ptr->next;
    tmp->prev = ptr;
    tmp->next = store;
    ptr->next = tmp;
    tmp->next->prev = tmp;
    
}
