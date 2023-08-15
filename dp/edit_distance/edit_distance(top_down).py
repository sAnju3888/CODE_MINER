def edit_Distance(word1,word2,i,j):
    if i == len(word1):
        return len(word2) - i 
    elif j == len(word2):
        return len(word1) - j 
    elif word1[i] == word2[j]:
        return edit_Distance(word1,word2,i+1,j+1)
    else:
        return 1 + min(edit_Distance(word1,word2,i+1,j+1),
        edit_Distance(word1,word2,i+1,j),
        edit_Distance(word1,word2,i,j+1))
        

def main():
    word1 = "INSIDE"
    word2 = "INSIDEBOX"
    print(edit_Distance(word1,word2,0,0))
    
if __name__ == "__main__":
    main()