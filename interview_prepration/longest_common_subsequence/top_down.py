class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.common(0,0,text1,text2,lookup={})
    def common(self,i,j,text1,text2,lookup):
        lookup = {} if lookup is None else lookup 
        if (i,j) in lookup:
            return lookup[(i,j)]
        if i >= len(text1) or j >= len(text2):
            return 0 
        if text1[i] == text2[j]:
            lookup[(i,j)] = 1+ self.common(i+1,j+1,text1,text2,lookup)
            return lookup[(i,j)]
        else:
            lookup[(i,j)] = max(self.common(i,j+1,text1,text2,lookup),self.common(i+1,j,text1,text2,lookup))
            return lookup[(i,j)]
    
    # Time complexity: O(m*n)
    # Space complexity: O(m*n) + O(m+n) for recursion stack
        
def main():
    sol = Solution()
    print(sol.longestCommonSubsequence("abcde","ace"))
    print(sol.longestCommonSubsequence("abc","abc"))
    print(sol.longestCommonSubsequence("abc","def"))
    print(sol.longestCommonSubsequence("bl","yby"))
    print(sol.longestCommonSubsequence("ezupkr","ubmrapg"))
    print(sol.longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy"))

if __name__ == "__main__":
    main()