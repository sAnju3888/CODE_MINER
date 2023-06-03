#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int x);
void print();
bool isempty();
void pop();
int compute(char v1,char v2,char operator);
int topp();
int main(){
    // IMPLEMENATION OF  Evaluating postfix expression
    //left to right adhanula v2 = first top and v1 = second top after removing first top  v1+v2
  
    char postfix[20]="23*54*+9-";
    int i=0;
    while(postfix[i]!='\0'){

        if (postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'){
            
            int v2 = topp();
            pop();
            int v1 = topp();
            pop();
            int a = compute(v1,v2,postfix[i]);
            push(a);
        }
        else {
            push(postfix[i] - '0');
        }
        
        i++;
    
        printf("\n");
        
    }

    if(!isempty()){
        printf("%d",stack[top]);
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

int topp(){
    return stack[top];
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

int compute(char v1, char v2, char operator) {
    if (operator == '+') {
        return (v1 - '0') + (v2 - '0');
    } else if (operator == '-') {
        return (v1 - '0') - (v2 - '0');
    } else if (operator == '*') {
        return (v1 - '0') * (v2 - '0');
    } else if (operator == '/') {
        return (v1 - '0') / (v2 - '0');
    }
    return 0;
}

