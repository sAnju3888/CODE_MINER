class Graph:
    def __init__(self):
        self.adj_mat = []
    
    def add_vertex(self):
        #adding an extra column
        for col in self.adj_mat:
            col.append(0)
        #adding an extra row
        self.adj_mat.append([0]*len(self.adj_mat[0]))
    
    def delete_vertex(self,u):
        self.adj_mat[-1],self.adj_mat[u] = self.adj_mat[u],self.adj_mat[-1]
        self.adj_mat.pop()

        for row in self.adj_mat:
            row[u],row[-1] = row[-1],row[u]
            row.pop()
    def add_edge(self,u,v):
        self.adj_mat[u][v] = 1

        #undirected
        #self.adj_mat[u][v] = 1
    def remove_edge(self,u,v):
        self.adj_mat[u][v] = 0
    
    def initialize(self,vertice,edge):
        self.adj_mat = [[0]*len(vertice) for _ in range(len(vertice))]
        for src,dst in edge:
            self.adj_mat[src][dst] = 1
        print(self.adj_mat)
        




def main():
    graph = Graph()
    v = [0,1,2,3,4,5,6,7]
    e = [(0,1),(0,2),(0,3),(1,5)]

    graph.initialize(v,e)






if __name__=="__main__":
    main()