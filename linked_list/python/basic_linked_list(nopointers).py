class Node:
    def __init__(self,data):
        self.data = data 
        self.next = None 

def insert(head,x):
        newnode =  Node(x)
        if head is None:
             head = newnode
             return head
        current = head 
        while current.next is not None:
             current = current.next
        current.next = newnode 
        return head

def printop(head):
     currentnode = head
     while currentnode!=None:
          print(currentnode.data)
          currentnode=currentnode.next



def main():

    head = None 
    head2 = None  
    head = insert(head,1)
    head = insert(head,2)
    head = insert(head,4)
    head = insert(head,8)
    printop(head)


if __name__=="__main__":
    main()