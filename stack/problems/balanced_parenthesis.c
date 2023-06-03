#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int x);
void print();
bool isempty();
void pop();
int main(){
    // IMPLEMENATION OF STACK 
    char parenthisis[10]="[()()]";
    int i=0;
    while(parenthisis[i]!='\0'){
        if (parenthisis[i]=='(' || parenthisis[i]=='[' || parenthisis[i]=='{'){
            push(parenthisis[i]);
        }
        else {
            if(parenthisis[i]== ')' && stack[top]=='(' || parenthisis[i]== ']' && stack[top]=='[' || parenthisis[i]== '}' && stack[top]=='{' ){
                pop();
                
            }
        }
       
        i++;
        print();
        printf("\n");
    }
    
   
    if(isempty()){
        printf("stacks are balanced");
    }
    else{
        printf("stacks are unbalanced");
    }
}

void push(int x){
    // overflow occurs
    if(top==MAX_SIZE){
        printf("stack overflow");
        return;
    }
    top++;
   stack[top] = x;
   
}

void pop(){
    // nothing to delete
    if(isempty()){
        printf("stack underflow");
    }
    printf("\n");
    top--;
}



void print(){
    for(int i=0;i<=top;i++){
        printf("%c \t",stack[i]);
    }
}

bool isempty(){
    if(top==-1){
        return true;
    }
    return false;
}