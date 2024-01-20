class Graph:
    def __init__(self):
        self.graph = {}
    def add_vertex(self,vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []
    def add_edge(self,v1,v2):
        if v1 in self.graph and v2 in self.graph:
            #undirected graph 
            self.graph[v1].append(v2)
            self.graph[v2].append(v1)

    def adj_matrix(self):
        rows,columns = len(self.graph),len(self.graph)
        matrix = [[0 for i in range(rows)] for j in range(columns)]
        for r in range(rows):
            for c in range(columns):
                if r in self.graph and c in self.graph and c in self.graph[r]:
                    matrix[r][c] = 1
        return matrix 

    
    def print(self):
        for v in self.graph:
            print(v,self.graph[v])


def main():
    g = Graph()
    g.add_vertex(1)
    g.add_vertex(2)
    g.add_vertex(3)
    g.add_vertex(4)
    g.add_vertex(5)

    g.add_edge(1,2)
    g.add_edge(1,3)
    g.add_edge(2,4)
    g.add_edge(3,5)

if __name__ == "__main__":
    main()