#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void brute_pattern_search(char *str,char *str2){
    int n = strlen(str);
    int m = strlen(str2);
    int k;
    int res = 0;
    bool check;
    for (int i=0;i<=(n-m);i++){
        k = 0;
        check = true;
        if (str[i] == str2[k]){
            
            for(int j=1;j<m;j++){
                if (str[i+j] != str2[j]){
                check = false;
                break;
                }
            }
            if (check == true){
                res += 1;
            }
        }
        
    }
    printf("%d",res);
}
void lpscompute(char *str2,int m,int  *lps){
    int len = 0;
    int i = 1;
    while (i < m){
        if (str2[i] == str2[len]){
            lps[i] = len + 1;
            i ++;
            len ++;
        }
        
        else{
            if (len != 0 ){
                len = lps[len-1];
                
            }
            else{
                lps[i] = 0;
                i ++;
            }
        }
    }
        for(int s=0;s<m;s++){
        printf("%d",lps[s]);
    }
}
int main(){
    char str[100];
    char str2[100];
    printf("Enter An string");
    scanf("%s",str);
    
    printf("Enter an pattern ");
    scanf("%s",str2);
    //brute_pattern_search(str,str2);
    int n = strlen(str);
    int m = strlen(str2);
    int i =  0;
    int j = 0;
    int lps[m];
    for(int s=0;s<m;s++){
        lps[s] = 0;
    }
    lpscompute(str2,m,lps);
    
    while (i < n){
        if (str[i] == str2[j]){
            i ++;
            j ++;
        }
        else{
            if (j != 0){
                j =  lps[j-1];
            }
            else{
                i ++;
            }
        }
        
        if (j == m){
        
            printf("Substring found");
            printf("%d",i-j);
            j = lps[j-1];
        }
    }


    

    
    
    
}