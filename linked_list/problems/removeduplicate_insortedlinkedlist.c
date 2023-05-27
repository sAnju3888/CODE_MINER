void remove_duplicate(){

     struct Node* q;
    struct Node* ptr;
    ptr = head;

    while(ptr!=NULL){
        // comparing i and i+1 index skipping lastindex+1 
        if(ptr->next!=NULL && ptr->data==ptr->next->data  ){
            q = ptr->next;
            ptr->next = q->next;
            
        }
        else{
            ptr = ptr->next;
        }
    }
    
}