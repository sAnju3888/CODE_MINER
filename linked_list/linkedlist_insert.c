#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {
    
    int data;
    struct Node* next;
};

struct Node* head;
void insert(int val);
void insert_end(int val);
void print();

int main(){
    int i,n,j,ins;
    bool b = true;
    head = NULL;
    printf("ENTER HOW MANY NUMBERS: \n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("ENTER NUMBER %d \n",i+1);
        scanf("%d",&j);
        b = true;
        while(b){
        printf(" INSERT TO BEG(1) OR INSERT AT END(2)");
        scanf("%d",&ins);
        if(ins==1){
          insert(j);  
          print();
           b = false;
        }else if (ins==2){
         insert_end(j);
         print();
         b = false;
        }
        else{
            b = true;
        }
        }
        
       
    }
    
 return 0;   
}

void insert(int val){
    // typecasting
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    //updation
    head = temp;
    
}

void print(){
    struct Node* pointer = head;
    while(pointer!=NULL){
        printf("%d ",pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
    
}

void insert_end(int val){
    struct Node* ptr;
    struct Node* tem = (struct Node*)malloc(sizeof(struct Node));
    tem->data = val;
    tem->next = NULL;
    
    if (head == NULL) {
        head = tem;
        return;
    }
    ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = tem;
    
}
