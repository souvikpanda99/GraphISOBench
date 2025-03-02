#include "graph.h"

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
