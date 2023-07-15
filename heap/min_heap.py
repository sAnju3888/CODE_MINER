class Heap:
    def __init__(self,arr=None):
        self.heap = arr


    def insert(self,val):
        if len(self.heap)==0:
            return self.heap.append(val)
        self.heap.append(val)
        self.heapifyup(len(self.heap)-1)
        return self.heap
    
    def heapifyup(self,index):
        parentindex = (index-1)/2
        parentindex = int(parentindex)
        while index!=0:
            if(self.heap[index]<self.heap[parentindex]):
                self.heap[index],self.heap[parentindex] = self.heap[parentindex],self.heap[index]
                index = parentindex 
                parentindex = (index-1)/2
                parentindex = int(parentindex)
    
    def heapifydown(self,index):
        leftchildindex = 2*index+1 
        rightchildindex = 2*index+2 
        # while performing down there are two child a root has so it has two child to compare   
        while leftchildindex<len(self.heap) and self.heap[index]>self.heap[leftchildindex] or rightchildindex<len(self.heap) and self.heap[index]>self.heap[rightchildindex]:
                    #incase of no right child its obvious to go to leftchild
            smallest = rightchildindex >= len(self.heap) or leftchildindex if self.heap[leftchildindex]<self.heap[rightchildindex]  else rightchildindex

            self.heap[index],self.heap[smallest] = self.heap[smallest],self.heap[index]
            index = smallest 
            leftchildindex = 2*index+1
            rightchildindex = 2*index+2 
        
        return self.heap


    def delete(self):
        root = self.heap[0]
        self.heap[0] = self.heap[len(self.heap)-1]
        self.heap.pop(len(self.heap)-1)
        self.heapifydown(0)
        return self.heap

    
    def isparentIndex(self,index):

        parentindex = (index-1)/2
        if parentindex <len(self.heap):
            return f"parent of {self.heap[index]} is:{self.heap[int(parentindex)]}"
        else:
            return -1
    
    def getleftchildIndex(self,index):


        leftchildindex = 2*index+1
        if 2*index+1 <len(self.heap):

            return f"left child of {self.heap[index]} is {self.heap[leftchildindex]}" 
        return -1
    def getrightchildIndex(self,index):
        
        rightchildindex = 2*index+2
        if 2*index+2 < len(self.heap):
            return f"right child of {self.heap[index]} is {self.heap[rightchildindex]}"
        return -1 
    
    


    



def main():
    # min heap is type of data structure used to take out maximum/minumum thing in array with a less time complexity 
    # Child order property should be maintained by every node it states that every node should be less than its child  if it is min 
    # major application of heap lies in areas of using most recently used or most lastly used 
    min_heap = Heap([3,6,4,9,12,8,7,14,15,13,18,11,9])
    print(min_heap.isparentIndex(3))
    print(min_heap.insert(1))
    print(min_heap.delete())


    

    

if __name__=="__main__":
    main()