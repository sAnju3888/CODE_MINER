#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head,int x);
void print(struct Node* head);
void merge_sorted(struct Node** head,struct Node** head2,struct Node** head3);

int main(){
    struct Node* head=NULL; 
    struct Node* head2 = NULL;
    struct Node* head3 = NULL; 
  

    insert(&head,2);
    insert(&head,5);
    print(head);
    printf("\n");
    insert(&head2,1);
    insert(&head2,3);
    print(head2);
    merge_sorted(&head,&head2,&head3);
}

void insert(struct Node** head,int x){

    struct Node* ab = (struct Node*)malloc(sizeof(struct Node));
    ab->data = x; 
    ab->next = NULL;
    
    if (*head==NULL){
        *head = ab;
        return;
    }
    struct Node* abc=*head;
    while (abc->next!=NULL){
        abc = abc->next;
        }
    abc->next = ab;
    
}
void merge_sorted(struct Node** head,struct Node** head2,struct Node** head3){
    printf("\n");
    int size = 0;
    struct Node* x = *head3; 
    struct Node* ab = *head; 
    struct Node* cd = *head2;
    *head3 = NULL; 
    
    while(ab!=NULL && cd!=NULL){
        
        if(ab->data <= cd->data){
            if( *head3==NULL){
            *head3 = ab;
            x = *head3;
            }
            else{
            x->next = ab;
            x = x->next;
            }   
            ab = ab->next;
        }
    else{
        if( *head3==NULL){
            *head3 = cd;
            x = *head3;
        }
        else{
            x->next = cd;
            x = x->next;
        }
        cd = cd->next;
    }
    }
    
        while (ab != NULL) {
        x->next = ab;
        x = x->next;
        ab = ab->next;
    }

    while (cd != NULL) {
        x->next = cd;
        x = x->next;
        cd = cd->next;
    }
    print(*head3);


}

void print(struct Node* head){
       struct Node* abc=head;
    while (abc!=NULL){
        printf("%d ",abc->data);
        abc = abc->next;
        }
    
}

