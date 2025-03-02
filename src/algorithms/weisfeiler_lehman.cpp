#include "weisfeiler_lehman.h"
#include <set>
#include <sstream>
#include <iostream>

std::unordered_map<int, std::string> WLAlgorithm::computeLabels(const Graph& g) {
    std::unordered_map<int, std::string> labels;
    for (int i = 0; i < g.getNumVertices(); i++) {
        labels[i] = "0"; // Initialize with a generic label 
    }
    int iterationlimit = log(g.getNumVertices()); // this might need to be changed
    std::cout << "Max no of iteration : " <<iterationlimit <<std::endl;
    for (int iteration = 0; iteration < iterationlimit; iteration++) { 
        std::unordered_map<int, std::string> newLabels;
        for (int i = 0; i < g.getNumVertices(); i++) {
            std::set<std::string> neighborLabels;
            for (int neighbor : g.getAdjacencyList()[i]) {
                neighborLabels.insert(labels[neighbor]);
            }
            
            std::stringstream ss;
            ss << labels[i] << "-";
            for (const auto& lbl : neighborLabels) {
                ss << lbl << ",";
            }

            newLabels[i] = ss.str();
        }
        labels = newLabels;
    }
    return labels;
}

bool WLAlgorithm::areIsomorphic(const Graph& g1, const Graph& g2) {
    if (g1.getNumVertices() != g2.getNumVertices()) return false;

    auto labels1 = computeLabels(g1);
    auto labels2 = computeLabels(g2);

    std::multiset<std::string> set1, set2;
    for (auto& [key, value] : labels1) set1.insert(value);
    for (auto& [key, value] : labels2) set2.insert(value);

    return set1 == set2;
}
