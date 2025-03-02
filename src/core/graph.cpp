#include "graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

Graph::Graph(int vertices) : numVertices(vertices) {
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Invalid edge: (" << u << ", " << v << ")\n";
        return;
    }
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u); // Assuming an undirected graph
}

// Generate a random graph with `edges` number of edges
void Graph::generateRandomGraph(int edges) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> vertexDist(0, numVertices - 1);

    for (int i = 0; i < edges; ++i) {
        int u = vertexDist(gen);
        int v = vertexDist(gen);
        if (u != v) { // Avoid self-loops
            addEdge(u, v);
        }
    }
}

// Generate an isomorphic graph by shuffling vertex labels
Graph Graph::generateIsomorphicGraph() const {
    Graph isomorphicGraph(numVertices);
    std::vector<int> mapping(numVertices);
    
    // Create a random permutation of vertex labels
    for (int i = 0; i < numVertices; ++i) {
        mapping[i] = i;
    }
    std::shuffle(mapping.begin(), mapping.end(), std::mt19937(std::random_device{}()));

    // Map edges to new vertex labels
    for (int u = 0; u < numVertices; ++u) {
        for (int v : adjacencyList[u]) {
            isomorphicGraph.addEdge(mapping[u], mapping[v]);
        }
    }

    return isomorphicGraph;
}


void Graph::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::string line;
    bool firstLine = true;

    while (getline(file, line)) {
        std::istringstream iss(line);
        if (firstLine) {
            iss >> numVertices;
            adjacencyList.resize(numVertices);
            firstLine = false;
        } else {
            int u, v;
            if (iss >> u >> v) {
                addEdge(u, v);
            }
        }
    }
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}
