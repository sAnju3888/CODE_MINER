#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
void push(int x);
void pop();
void print();
struct Node* top = NULL;
int main(){
    push(2);print();
    push(5);print();
    push(10);print();
    pop();print();
    
}

void push(int x){
    struct Node* tmp =  (struct Node*)malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = top;
    top = tmp;
}
void pop(){
    if(top==NULL){
        return;
    }
    struct Node* tmp = top;
    top = top->next;
    free(tmp);
}

void print(){
    struct Node* ptr4 = top;
    while(ptr4!=NULL){
        printf("%d \t",ptr4->data);
        ptr4 = ptr4->next;
    }
    printf("\n");
}

