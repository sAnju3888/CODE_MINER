def generate(i,subword,word,sub):
    if i == len(word):
        sub.append(subword)
        return
    generate(i+1,subword +word[i],word,sub)
    generate(i+1,subword,word,sub)

    # Time complexity: O(2^n)


def main():
    sub = []
    generate(0, "", "abc",sub)
    print(sub)


if __name__ =="__main__":
    main()