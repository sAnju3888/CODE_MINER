void rec_print(struct Node* p){
    if(p==NULL){
       return ;
    }
    else{
                printf("\n");
        printf("%d sui",p->data);
        rec_print(p->next);
    }
}

void rec_print_reverse(struct Node* p){
    if(p==NULL){
        return;
    }else{
        printf("\n");
        rec_print_reverse(p->next);
         printf("\n");
         printf("%d dog",p->data);
        
    }
}
