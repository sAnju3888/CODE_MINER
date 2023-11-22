#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

bool isgreat(struct tree* root,int value){
if(root== NULL){

        return true;
}

else if (root->val  >= value && isgreat(root->left,value) &&isgreat(root->right,value)){
        return true;
}
else{
        return false;
}
}

bool islesser(struct tree* root,int value){
if(root==NULL){
return true;
}
else if(root->val <= value && islesser(root->left,value) && islesser(root->right,value)){
        return true;
}
else{
        return false;
}

}

bool checkif_valid_bst(struct tree* root){

        if(root == NULL){ return true;}
        else if ((islesser(root->left,root->val)) && (isgreat(root->right,root->val)) && checkif_valid_bst(root->left)
                && checkif_valid_bst(root->right)){

                return true;
                }
        else{
                return false;
        }


}



struct tree* root = NULL;
int main(){
        root = Insert(2,root);
        root = Insert(1,root);
        root = Insert(3,root);
        root = Insert(5,root);
        root = Insert(0,root);

       if (checkif_valid_bst(root)){
        printf("The Given Tree is Valid");
        }
        else{
        printf("The Given Tree is invalid");
        }
return 0;
}