#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
    
public:
    Graph(int vertices = 0);
    
    void addEdge(int u, int v);
    void loadFromFile(const std::string& filename);
    void printGraph() const;

    int getNumVertices() const { return numVertices; }
    const std::vector<std::vector<int>>& getAdjacencyList() const { return adjacencyList; }
    void generateRandomGraph(int edges);
    Graph generateIsomorphicGraph() const;
};

#endif
