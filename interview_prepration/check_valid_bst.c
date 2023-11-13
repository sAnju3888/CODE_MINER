#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct tree{
        int val;
        struct tree* left;
        struct tree* right;
};
struct tree* add(int key){
        struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
        temp->val =  key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
}
struct tree* Insert(int value,struct tree* root){
                if (root == NULL){
                        root = add(value);
                 }
                else if(value  <= root->val){
                        root->left = Insert(value,root->left);
                }
                else{
                        root->right = Insert(value,root->right);
                }
                return root;
}

bool checkif_valid_bst(struct tree* root,int min_value , int max_value){

        if(root == NULL){ return true;}
        else if ( (root->val >= min_value) && (root->val < max_value) && checkif_valid_bst(root->left,min_value,root->val)
                && checkif_valid_bst(root->right,root->val,max_value)){

                return true;
                }
        else{
                return false;
        }


}



struct tree* root = NULL;
int main(){
        root = Insert(7,root);
        root = Insert(4,root);
        root = Insert(9,root);
        root = Insert(1,root);
        root = Insert(6,root);

       if (checkif_valid_bst(root,INT_MIN,INT_MAX)){
        printf("The Given Tree is Valid");
        }
        else{
        printf("The Given Tree is invalid");
        }
return 0;
}
