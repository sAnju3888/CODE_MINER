#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};
struct Node *enter_value(int key){
    
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = key;
    temp->next = NULL;
    return temp;
    
}

struct Node *Insert(struct Node *head,int value){
    
    if (head == NULL){
        head = enter_value(value);
    }
    else{
        struct Node *tp = (struct Node*)malloc(sizeof(struct Node));
        tp->val = value;
        tp->next = NULL;
        struct Node *temp = head; 
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = tp;
    }
    return head;
}
void print_all(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if (temp->next != NULL){
        printf("%d -> ",temp->val);
        }
        else{
            printf("%d",temp->val);
        }
        temp = temp->next;
    }
    printf("\n");
}

struct Node *Insert_at_beg(struct Node *head,int value){
    if (head == NULL){
        head = enter_value(value);
    }
    else{
        struct Node *t2 = enter_value(value);
        t2->next = head;
        head = t2;
    }
    
    return head;
}

struct Node* delete_last(struct Node* head){
    if (head == NULL || head->next == NULL){
        printf("NOTHING TO DELETE");
        return NULL;
    }
    else if (head->next->next == NULL){
        free(head->next->next);
        head->next = NULL;
    }
    else{
        
        struct Node *temp = head; 
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next->next);
        temp->next = NULL;
        return head;
        
    }
}

struct Node* delete_front(struct Node* head){
    if(head == NULL){
        printf("NO ELEMENTS");
        return NULL;
    }
    else if (head->next == NULL){
        free(head);
        return NULL;
    }
    else{
        struct Node* ab = head;
        head = ab->next;
        free(ab);
        return head;
    }
    
}

struct Node* rev(struct Node* head){
    
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
struct Node* rev_recursion(struct Node* head , struct Node* dupe){
    
    if (dupe->next == NULL){
        head = dupe;
        return head;
        
    }
    struct Node* new_head = rev_recursion(head,dupe->next);
    struct Node* q = dupe->next;
    q->next = dupe;
    dupe->next = NULL;
    return new_head;
}

struct Node* rev_recursion_k(struct Node* head,int k){
    int count = 0; 
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    
    while ( current != NULL && count <k){
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
        count ++;
    }
    if (count >= k){
        head->next = rev_recursion_k(current,k);
    }
    return prev;
    
}

int main(){
  struct Node *head = NULL; 
  head = Insert(head,2);
  head = Insert(head,3);
  head = Insert_at_beg(head,1);
  head = Insert(head,4);
  head = Insert(head,5);
  head = Insert(head,6);
  head = Insert(head,7);
  head = Insert(head,8);
  head = Insert(head,9);
  head = Insert(head,10);
  
  printf("Normal: \n");
  print_all(head);
  
  printf("Delete End Element: \n");
  head = delete_last(head); 
  print_all(head);
  
  printf("Delete Front: \n");
  head = delete_front(head);
  print_all(head);
  
  printf("reverse iterational: \n");
  head = rev(head);
  print_all(head);
  
  printf("reverse recursive: \n");
  struct Node* dupe = head; 
  head = rev_recursion(head , dupe);
  print_all(head);
  
  printf("reverse with group size k: \n");
  head = rev_recursion_k(head,2);
  print_all(head);
    
}
