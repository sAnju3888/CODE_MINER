#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct Node{
    int data;
    struct Node* next;
};
void Insert_end(int val);
void reverse();
struct Node* head;
int main(){
    Insert_end(2);
    Insert_end(4);
    Insert_end(6);
    Insert_end(8);
    reverse();
    
}

void Insert_end(int val){
    struct Node* tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = val;
    tmp ->next = NULL;

    if(head == NULL){
        head = tmp;
        return;
    }
    struct Node* abd;
    abd = head;
    while(abd->next!= NULL){
        abd = abd->next;
    }
    abd->next = tmp;
    
    struct Node* abc;
    abc = head;
    while(abc!= NULL){
        printf("%d \t",abc->data);
        abc = abc->next;
    }
    printf("\n");
}

void reverse(){
    struct Node* curr;
    struct Node*prev;
    struct Node* next;
    
    curr = head;
    prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    
    head = prev;
    struct Node* gio;
    gio = head;
    printf("Reversed Linked List is::");
      while(gio!= NULL){
        printf("%d \t",gio->data);
        gio = gio->next;
    }
    printf("\n");
    
}
