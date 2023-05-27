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
void print_middle_element();
struct Node* head;
int size=0;
int main(){
    //print middle number in the list 
    Insert_at_end(3);
    Insert_at_end(5);
    Insert_at_start(1);
    Insert_at_end(7);
    Insert_at_end(9);
    Insert_at_end(20);
    Insert_at_start(-55);
    Insert_at_end(100);
    Insert_at_end(120);
    struct Node* ab;
    ab = head;
    print(ab);
    printf("\n");
    printf("size is:%d",size);
    print_middle_element();
    
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

void print_middle_element(){
    if(size%2!=0){
        //one middle
        int middle = size/2;
        struct Node* jk;
        jk = head;
        int cnt = 0;
        while(jk!=NULL){
            if(cnt==middle){
                printf("\n");
                printf("middle element in single linked list is :%d",jk->data);
                break;
            }
            cnt++;
            jk=jk->next;
        }
    }
    else{
        int middle = (size/2)-1;
         struct Node* jk;
        jk = head;
        int cnt = 0;
        int avg = 0;
        while(jk!=NULL){
            if(cnt==middle || cnt==middle+1){
                avg = avg + jk->data;
            }
            cnt++;
            jk=jk->next;
        }
        printf("\n");
        printf("%d middle element in even single linked list",avg/2);
    }
    
}