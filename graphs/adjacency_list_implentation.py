class Graph:
    def __init__(self):
        self.adj_list = {}
    
    def add_vertex(self,v):
        if v not in self.adj_list:
            self.adj_list[v] = []
    
    def remove_vertex(self,u):
        if u in self.adj_list:
            del self.adj_list[u]

        #deleting vertex present in u [neighbours]
        for v in self.adj_list:
            if u in self.adj_list[v]:
                v.remove(u)
    
    def add_edge(self,u,v):
        if u in self.adj_list and v in self.adj_list:
            self.adj_list[u].append(v)
            # if it is undirected graph then if there is edge between u and v then there exist edge b/w v and u 
            #self.adj_list[v].append(u)
            
            #weighted graph na self.adj_list[v].append((u,w))
            #weighted acyclic graph self.adj_list[u].append((v,w))
    
    def remove_edge(self,u,v):

        if u in self.adj_list and v in self.adj_list[u]:
            self.adj_list[u].remove(v)
            # if its undirected graph  self.adj_list[v].remove(u)

    def build(self,v,e):
        for ve in v:
            self.add_vertex(ve)
        for a,b in e:
            self.add_edge(a,b) 
        print(self.adj_list)


def main():
    graph = Graph()
    v = [0,1,2,3,4,5,6,7]
    e = [(0,1),(0,2),(0,3),(1,5)]
    graph.build(v,e)



if __name__=="__main__":
    main()