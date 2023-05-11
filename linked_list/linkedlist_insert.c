#include<stdio.h>
#include<stdlib.h>

struct Node {
    
    int data;
    struct Node* next;
};

struct Node* head;
void insert(int val);
void print();

int main(){
    int i,n,j;
    head = NULL;
    printf("ENTER HOW MANY NUMBERS: \n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("ENTER NUMBER %d \n",i+1);
        scanf("%d",&j);
        insert(j);
        print();
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
    struct Node* pointer = (struct Node*)malloc(sizeof(struct Node));
    pointer = head; 
    while(pointer!=NULL){
        printf("%d ",pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
    
}