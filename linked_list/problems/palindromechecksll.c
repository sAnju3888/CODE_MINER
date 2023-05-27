#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

struct Node{
  int data;
  struct Node* next;
};
void Insert_at_end(int val);
void Insert_at_start(int val);
void print(struct Node* ab);
void zero_sum_check();
void  remove_duplicate();
void  checkpalindrome();
void reverse(struct Node* ab);
struct Node* head;
struct Node* tail;
int sum = 0;
int size=0;
int main(){
    // drop duplicate  element from sorted linked list 
    Insert_at_end(1);
    Insert_at_end(2);
    Insert_at_end(-5);
    Insert_at_end(5);
    Insert_at_end(7);
    zero_sum_check();
    struct Node* ab;

    Insert_at_end(7);
    Insert_at_end(7);
    Insert_at_end(7);
    Insert_at_end(5);
    remove_duplicate();
    ab = head; 
    print(ab);
    printf("\n");
    tail = head;
    reverse(head);
    print(head);
    checkpalindrome();
    
    
    
    

}
void Insert_at_end(int val){
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        struct Node* ptr;
        ptr =  head; 
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void Insert_at_start(int val){
     struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    
    head = temp;
    
    
}

void print(struct Node* ab){
    if (ab==NULL){
        return;
    }
    else{
        printf("%d \t",ab->data);
        size++;
        print(ab->next);
    }
}
void zero_sum_check(){
    struct Node* yu;
    yu = head;
    while(yu!=NULL){
        sum = sum + yu->data;
         if(sum<0){
            printf("at %d  sum is negative bro \n",yu->data);
            head = yu->next;
            break;
        }
        yu = yu->next;
    }
}

void remove_duplicate(){

     struct Node* q;
    struct Node* ptr;
    ptr = head;

    while(ptr!=NULL){
        // comparing i and i+1 index skipping lastindex+1 
        if(ptr->next!=NULL && ptr->data==ptr->next->data  ){
            q = ptr->next;
            ptr->next = q->next;
            
        }
        else{
            ptr = ptr->next;
        }
    }
    
}

void reverse(struct Node* p){
    if(p->next==NULL){
        head = p;
        return;
    }
    else{
        reverse(p->next);
        struct Node* q = p->next;
        q->next = p;
        p->next = NULL;
    }
    
}
void checkpalindrome() {
    // cmpare reverse linked list and normal one
    struct Node* a = head;
    struct Node* b = tail;
    int ck = 0;
    bool check = true;

    while (a != b && a != NULL && b != NULL) {
        if (a->data != b->data) {
            check = false;
            break;
        }
        a = a->next;
        b = b->next;
    }

    if (check) {
        printf("The linked list is a palindrome");
    } else {
        printf("The linked list is not a palindrome");
    }
}#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

struct Node{
  int data;
  struct Node* next;
};
void Insert_at_end(int val);
void Insert_at_start(int val);
void print(struct Node* ab);
void zero_sum_check();
void  remove_duplicate();
void  checkpalindrome();
void reverse(struct Node* ab);
struct Node* head;
struct Node* tail;
int sum = 0;
int size=0;
int main(){
    // drop duplicate  element from sorted linked list 
    Insert_at_end(1);
    Insert_at_end(2);
    Insert_at_end(-5);
    Insert_at_end(5);
    Insert_at_end(7);
    zero_sum_check();
    struct Node* ab;

    Insert_at_end(7);
    Insert_at_end(7);
    Insert_at_end(7);
    Insert_at_end(5);
    remove_duplicate();
    ab = head; 
    print(ab);
    printf("\n");
    tail = head;
    reverse(head);
    print(head);
    checkpalindrome();
    
    
    
    

}
void Insert_at_end(int val){
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        struct Node* ptr;
        ptr =  head; 
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void Insert_at_start(int val){
     struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    
    head = temp;
    
    
}

void print(struct Node* ab){
    if (ab==NULL){
        return;
    }
    else{
        printf("%d \t",ab->data);
        size++;
        print(ab->next);
    }
}
void zero_sum_check(){
    struct Node* yu;
    yu = head;
    while(yu!=NULL){
        sum = sum + yu->data;
         if(sum<0){
            printf("at %d  sum is negative bro \n",yu->data);
            head = yu->next;
            break;
        }
        yu = yu->next;
    }
}

void remove_duplicate(){

     struct Node* q;
    struct Node* ptr;
    ptr = head;

    while(ptr!=NULL){
        // comparing i and i+1 index skipping lastindex+1 
        if(ptr->next!=NULL && ptr->data==ptr->next->data  ){
            q = ptr->next;
            ptr->next = q->next;
            
        }
        else{
            ptr = ptr->next;
        }
    }
    
}

void reverse(struct Node* p){
    if(p->next==NULL){
        head = p;
        return;
    }
    else{
        reverse(p->next);
        struct Node* q = p->next;
        q->next = p;
        p->next = NULL;
    }
    
}
void checkpalindrome() {
    // cmpare reverse linked list and normal one
    struct Node* a = head;
    struct Node* b = tail;
    int ck = 0;
    bool check = true;

    while (a != b && a != NULL && b != NULL) {
        if (a->data != b->data) {
            check = false;
            break;
        }
        a = a->next;
        b = b->next;
    }

    if (check) {
        printf("The linked list is a palindrome");
    } else {
        printf("The linked list is not a palindrome");
    }
}