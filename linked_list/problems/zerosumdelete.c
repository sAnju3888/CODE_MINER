void zero_sum_check(){
    struct Node* yu;
    yu = head;
    while(yu!=NULL){
        sum = sum + yu->data;
         if(sum<0){
            printf("at %d  sum is negative bro \n",yu->data);
            head = yu->next;
            break;
        }
        yu = yu->next;
    }
}