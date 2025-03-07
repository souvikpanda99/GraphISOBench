#include "algorithm_factory.h"
#include <iostream>

int main() {
    /*Graph g1, g2;
    g1.loadFromFile("graph1.txt");
    g2.loadFromFile("graph2.txt");*/
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);

    // Define Graph 2 (isomorphic to g1)
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    std::cout << "Choose algorithm (1: VF2, 2: WL, 3: NautyTraces): ";
    int choice;
    std::cin >> choice;

    auto algorithm = AlgorithmFactory::createAlgorithm(static_cast<AlgorithmType>(choice - 1));

    if (algorithm->areIsomorphic(g1, g2)) {
        std::cout << "Graphs are isomorphic!\n";
    } else {
        std::cout << "Graphs are NOT isomorphic!\n";
    }

    return 0;
}
