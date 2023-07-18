class Graph():

    def __init__(self):
        self.adj_list = {}
    
    def add_vertex(self,u):
        if u not in self.adj_list:
            self.adj_list[u] = []
    def add_edge(self,u,v):
        if u in self.adj_list and v in self.adj_list:
            self.adj_list[u].append(v)
            self.adj_list[v].append(u)
    
    def build(self,v,e):
        for ve in v:
            self.add_vertex(ve)
        for src,dst in e:
            self.add_edge(src,dst)
        print(self.adj_list)
    
    def bfs(self,src,visited,printed):
        queue = []
        queue.append(src)

        while  len(queue)!=0:
            a = queue.pop(0)
            visited[a] = True 
            printed.append(a)
            for neighbours in self.adj_list[a]:
                if visited[neighbours]==False:
                    queue.append(neighbours)
                    visited[neighbours] = True 
        print(printed)

    def min_edge(self,start,end,visited):
        queue = []
        level = 0 
        queue.append((level,start))
        visited[start] = True 

        while len(queue)!=0:
            level,a = queue.pop(0)
            visited[a] = True 
            if a == end:
                return level

            for neighbours in self.adj_list[a]:
                if visited[neighbours]==False:
                    queue.append((level+1,neighbours))
                    visited[neighbours] = True 
        return -1

        if start==end:
            return level 
        




def main():
    graph = Graph()
    v = [0,1,2,3,5,7,8]
    e = [(0,1),(0,3),(1,2),(2,0),(2,3),(2,5),(7,8)]
    graph.build(v,e)
    visited = {key:False for key in v}
    printed = []
    graph.bfs(0,visited,printed)

    visited = {key:False for key in v}
    printed = []
    print(graph.min_edge(0,5,visited))

   

if __name__=="__main__":
    main()