#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define length 10
void push(int array[], int x);
void pop();
int topp(int array[]);
bool isempty();
void print(int array[]);
int top = -1;
int main() {
   
    int array[10];
    push(array, 2); print(array);
    push(array, 5); print(array);
    push(array, 10); print(array);
    pop(); print(array);
    push(array, 12); print(array);
    printf("%d \n",topp(array));
    printf("%s\n", isempty() ? "true" : "false");

    return 0;
}

void push(int array[], int x) {
    
    if(top==length){
        printf("stack overflow ");
        return ;
    }
    array[++top] = x;
}
void pop() {
    if (top==-1){
        printf("There is No element left in stack to pop");
        return;
    }
    top--;
}
int topp(int array[]){
    return array[top];
}
bool isempty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void print(int array[]){
    for(int i=0;i<=top;i++){
        printf("%d \t",array[i]);
    }
    printf("\n");
}