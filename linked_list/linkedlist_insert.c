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
void delete_n(int index);
void print();

int main(){
    int i,n,j,ins,index;
    bool b = true;
    head = NULL;
    printf("ENTER HOW MANY NUMBERS: \n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){//1
        printf("ENTER NUMBER %d \n",i+1);
        scanf("%d",&j);
        b = true;
        while(b){//2
        printf(" INSERT TO BEG(1) OR INSERT AT END(2) OR INSERT at Nth position(3) OR DELETE AT  Nth position(4)");
        scanf("%d",&ins);
        if(ins==1){//3
          insert(j);  
          print();
           b = false;
        }else if (ins==2){//3
         insert_end(j);
         print();
         b = false;
        }else if (ins==3){//3
         printf("Print at which index you need to insert ");
         scanf("%d",&index);
        while (index>size+1){//4
        printf("Index out of Range!!!!");
        printf("\n");
        printf("Print at which index you need to insert ");
         scanf("%d",&index);
             
         }//3
        insert_n(j,index);

         print();
         b = false;
        }//2
        else if (ins==4){//2
         printf("Print at which index you need to delete ");
         scanf("%d",&index);
        while (index>size+1){//3
        printf("Index out of Range!!!!");
        printf("\n");
        printf("Print at which index you need to delete ");
         scanf("%d",&index);
             
         }//2
        delete_n(index);
         print();
         b = false;
        } else{
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

void delete_n(int index){
    int i=0;

    struct Node* del1;
    struct Node* del2;
    del1 = head;
    if (index==1){
        head = del1->next;
        free(del1);
        return;
    }
     for(i=0;i<index-2;i++){
        del1 = del1->next;
    }
     del2 = del1->next;//n 
    del1->next = del2->next;
    free(del2);
    
    
}
