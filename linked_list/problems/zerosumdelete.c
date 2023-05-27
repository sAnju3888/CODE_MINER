#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
  int data;
  struct Node* next;
};
void Insert_at_end(int val);
void Insert_at_start(int val);
void print(struct Node* ab);
void zero_sum_check();
struct Node* head;
int sum = 0;
int size=0;
int main(){
    //print middle number in the list
    Insert_at_end(1);
    Insert_at_end(2);
    Insert_at_end(-5);
    Insert_at_end(5);
    Insert_at_end(7);
    zero_sum_check();
    struct Node* ab;
    ab = head; 
    print(ab);
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
