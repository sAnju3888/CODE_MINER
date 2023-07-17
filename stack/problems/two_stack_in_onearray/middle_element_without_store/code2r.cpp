#include<bits/stdc++.h>

class Solution
{
    public:
    void  rec(stack<int>&s,int middle,int ind){
        int x = s.top();
        s.pop();
        if(ind!=middle){
            rec(s,middle,ind+1);
            s.push(x);
        }
    }
   
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int middle = 0;
        middle = (sizeOfStack/2);
        int ind = 0;
        rec(s, middle,ind);

        
    }
};