#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {
    
    int data;
    struct Node* next;
};
//two global variable are  used onnu head (all function using) inonu size()function
int size;
struct Node* head;
void insert(int val);
void insert_n(int val,int index);
void insert_end(int val);
void print();

int main(){
    int i,n,j,ins,index;
    bool b = true;
    head = NULL;
    printf("ENTER HOW MANY NUMBERS: \n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("ENTER NUMBER %d \n",i+1);
        scanf("%d",&j);
        b = true;
        while(b){
        printf(" INSERT TO BEG(1) OR INSERT AT END(2) OR INSERT at Nth position(3)");
        scanf("%d",&ins);
        if(ins==1){
          insert(j);  
          print();
           b = false;
        }else if (ins==2){
         insert_end(j);
         print();
         b = false;
        }else if (ins==3){
         printf("Print at which index you need to insert ");
         scanf("%d",&index);
        while (index>size+1){
        printf("Index out of Range!!!!");
        printf("\n");
        printf("Print at which index you need to insert ");
         scanf("%d",&index);
             
         }
        insert_n(j,index);

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
    size = 0;
    while(pointer!=NULL){
        size++;
        printf("%d ",pointer->data);
        pointer = pointer->next;
    }
   printf("\n");    
    printf(" The size of linked list is %d:",size);
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

void insert_n(int val,int index){

    int i=0;
    struct Node* temp2;
    temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp2->data = val;
    temp2->next = NULL;
    if (index==0){
        head = temp2;
        return;
    }
    else if(index == 1){
    temp2->next = head;
    head = temp2;
    return;
    }
    
    else if(index == size+1){
        insert_end(val);

        return;
        
    }
    
    struct Node* ptr;
    ptr = head;
    for(i=0;i<index-2;i++){
        ptr = ptr->next;
    }
    temp2->next = ptr->next;
    ptr->next = temp2;
    
}
