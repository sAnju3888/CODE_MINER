

class Graph:
    def __init__(self):
        self.graph = {}
    
    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []
    
    def add_edge(self, v1, v2):
        if v1 in self.graph and v2 in self.graph:
            self.graph[v1].append(v2)
            self.graph[v2].append(v1)
    
    def print(self):
        print(self.graph)
    def dfs_traversal(self, src, result,visited):


        result.append(src)
        visited[src] = True
        for neighbour in self.graph[src]:
            if not visited[neighbour]:
                self.dfs_traversal(neighbour, result,visited)
        return result


def main():
    graphs = Graph()
    # Add vertices
    graphs.add_vertex(0)
    graphs.add_vertex(1)
    graphs.add_vertex(2)
    graphs.add_vertex(3)
    graphs.add_vertex(4)
    graphs.add_vertex(7)
    graphs.add_vertex(9)

    # Add edges
    graphs.add_edge(0, 1)
    graphs.add_edge(0, 2)
    graphs.add_edge(0, 3)
    graphs.add_edge(1, 3)
    graphs.add_edge(3, 2)
    graphs.add_edge(3, 4)
    graphs.add_edge(4, 9)
    graphs.add_edge(9, 7)

    print_all = []
    keys = graphs.graph.keys()
    visited = {key: False for key in keys}
    
    print(graphs.dfs_traversal(0, print_all,visited))


if __name__ == "__main__":
    main()
