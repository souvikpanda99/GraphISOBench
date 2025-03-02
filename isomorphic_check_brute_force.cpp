#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <sstream>


using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency matrix

    Graph(int V) : V(V) {
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    vector<int> getDegreeSequence() {
        vector<int> degrees(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                degrees[i] += adj[i][j];
            }
        }
        sort(degrees.begin(), degrees.end());
        return degrees;
    }
};

// Function to check if a given permutation preserves adjacency
bool isValidMapping(Graph &G1, Graph &G2, vector<int> &mapping) {
    for (int i = 0; i < G1.V; i++) {
        for (int j = 0; j < G1.V; j++) {
            if (G1.adj[i][j] != G2.adj[mapping[i]][mapping[j]]) {
                return false;
            }
        }
    }
    return true;
}

// Backtracking function to check isomorphism
bool checkIsomorphism(Graph &G1, Graph &G2, vector<int> &perm, vector<bool> &used, vector<int> &mapping) {
    if (perm.size() == G1.V) {
        return isValidMapping(G1, G2, perm);
    }

    for (int i = 0; i < G1.V; i++) {
        if (!used[i]) {
            used[i] = true;
            perm.push_back(i);
            if (checkIsomorphism(G1, G2, perm, used, mapping))
                return true;
            perm.pop_back();
            used[i] = false;
        }
    }
    return false;
}

// Wrapper function to check graph isomorphism
bool areIsomorphic(Graph &G1, Graph &G2) {
    if (G1.V != G2.V) return false;  // Different number of vertices
    if (G1.getDegreeSequence() != G2.getDegreeSequence()) return false; // Degree sequence check

    vector<int> perm;
    vector<bool> used(G1.V, false);
    vector<int> mapping(G1.V, -1);

    return checkIsomorphism(G1, G2, perm, used, mapping);
}

int main() {
    int V = 4;
    Graph G1(V), G2(V);

    G1.addEdge(0, 1);
    G1.addEdge(1, 2);
    G1.addEdge(2, 3);
    G1.addEdge(3, 0);

    G2.addEdge(0, 2);
    G2.addEdge(2, 1);
    G2.addEdge(1, 3);
    G2.addEdge(3, 0);

    if (areIsomorphic(G1, G2))
        cout << "Graphs are Isomorphic" << endl;
    else
        cout << "Graphs are NOT Isomorphic" << endl;

    return 0;
}
