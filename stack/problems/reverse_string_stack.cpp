#include<iostream>
#include<stack>
#include <cstring>
using namespace std;

void reverse(char c[],int n){
    stack<char> s;
    //pushing char into stack
    for(int i=0;i<n;i++){
        s.push(c[i]);
    }
    //pop and overwirtting into actual c
   for(int i=0;i<n;i++){
        c[i] = s.top();
        s.pop();
        
    }
    
    
}
int main(){
    char c[51];
    cout << "Enter a string: ";
    cin >>c;
    reverse(c, strlen(c));
    cout << "Reversed string: " << c << endl;

}
