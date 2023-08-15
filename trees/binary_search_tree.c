#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <limits.h>
#include<queue>
using namespace std;
struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* getnewnode(int x){
    struct tree* ab = (struct tree*)malloc(sizeof(struct tree));
    ab->data = x;
    ab->left = NULL;
    ab->right = NULL;
    return ab;
}
struct tree* Insert(struct tree* root,int data){
    if (root==NULL){
        root = getnewnode(data);
    }
    else{
        if(data<=root->data){
            root->left = Insert(root->left,data);
        }
        else{
            root->right = Insert(root->right,data);
        }
    }
    return root;
}
int minimum(struct tree* root){
    if(root->left==NULL){
        return root->data;
    }
    else{
        minimum(root->left);
    }
}

int maximum(struct tree* root){
    if(root->right==NULL){
        return root->data;
    }
    else{
        maximum(root->right);
    }
}
int totalnodes(struct tree* root){
    if (root == NULL){
        return 0;
    }
    else{
        int lc = totalnodes(root->left);
        int rc = totalnodes(root->right);
    return 1+lc+rc;
    }
}
bool checkexist(struct tree* root,int key){
    if (root==NULL){
        return false;
    }
    if (root->data==key){
        return true;
    }
    else{
        if (key>=root->data){
            checkexist(root->right,key);
        }
        else{
            checkexist(root->left,key);
        }
    }
    
}
void rootnode(struct tree* root){
    printf("Root of the Node is :%d",root->data);
}
int height(struct tree* root) {
    if (root == NULL) {
        return -1;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}
void levelorder(struct tree* root){
    if (root==NULL){
       printf("No Elements to print");
       return;
    }
    queue<struct tree*> q;
    q.push(root);
    while (!q.empty()){
        struct tree* ab = q.front();
        printf("%d \t",ab->data);
        if (ab->left!=NULL){ q.push(ab->left);}
        if(ab->right!=NULL){q.push(ab->right);}
        q.pop();
    }
}
bool isleftlesser(struct tree* root,int val){
    if (root==NULL){
        return true;
    }
    if (root->data<=val && isleftlesser(root->left,val)&&isleftlesser(root->right,val)){
        return true;
    }
    else{
        return false;
    }
}
bool isrightgreater(struct tree* root,int val){
    if (root==NULL){
        return true;
    }
    if (root->data>=val && isrightgreater(root->left,val)&&isrightgreater(root->right,val)){
        return true;
    }
    else{
        return false;
    }
}
bool checkifbinarytree(struct tree* root){
    if (root==NULL){
        return true;
    }
    if (isleftlesser(root->left,root->data) && isrightgreater(root->right,root->data) && checkifbinarytree(root->left)&&checkifbinarytree(root->right)){
        return true;
    }
    else{
        return false;
    }
}
bool waytwobstcheck(struct tree* root,int min,int max){
    if (root==NULL){
        return true;
    }
    else{
        if(root->data>=min && root->data<=max &&waytwobstcheck(root->left,min,root->data)&& waytwobstcheck(root->right,root->data,max)){
            return true;
        }
        else{
            return false;
        }
    }
    
}

int main(){
    struct tree* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    printf("Minimum no in BST %d\n",minimum(root));
    printf(" Maximum no in BST %d \n",maximum(root));
    printf(" Total No of Nodes in BST %d \n",totalnodes(root));
    printf("Height of Bst tree %d \n",height(root));
    printf("%d \n",root->data);
    int key = 17;
    if (checkexist(root,key)==true){
        printf("%d Exist In the BST\n",key);
    }
    else{
        printf("%d Doesn't Exist in the Bst\n",key);
    }
    printf("%d Height of the tree is\n ",height(root));
    levelorder(root);
    if (checkifbinarytree(root)==true){
        printf("\nThe given Tree is Binary Tree");
    }
    else{
        printf("\n The given Tree is Not a Binary Tree");
    }
    
    if (waytwobstcheck(root,INT_MIN,INT_MAX)==true){
        printf("\nThe given Tree is Binary Tree");
    }
    else{
        printf("\n The given Tree is Not a Binary Tree");
    }
    

}