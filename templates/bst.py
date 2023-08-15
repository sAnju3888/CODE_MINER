class tree:
    def __init__(self,x):
        self.data = x
        self.left = None 
        self.right = None
def newnode(x):
    return tree(x)
    

def Insert(root,x):
    if root is None:
        root = newnode(x)
        return root 
    if root.data<=x:
        root.left = Insert(root.left,x)
    else:
        root.right = Insert(root.right,x)
    return root 
def main():
    root = None 
    root = Insert(root,10)
    root = Insert(root,5)
    root = Insert(root,20)