#include "vf2.h"

bool VF2Algorithm::match(Graph const& g1, Graph const& g2, 
                         std::unordered_map<int, int>& mapping, 
                         std::vector<bool>& used, int depth) {
    if (depth == g1.getNumVertices()) return true; // All vertices mapped

    for (int v2 = 0; v2 < g2.getNumVertices(); ++v2) {
        if (!used[v2]) {
            mapping[depth] = v2;
            used[v2] = true;

            bool valid = true;
            for (int i = 0; i < depth; ++i) {
                if (mapping.count(i)) {
                    int u1 = i, v1 = mapping[i];
                    int u2 = depth, v2_mapped = mapping[depth];

                    if (g1.getAdjacencyList()[u1].size() != g2.getAdjacencyList()[v1].size()) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && match(g1, g2, mapping, used, depth + 1)) {
                return true;
            }

            used[v2] = false;
        }
    }
    return false;
}

bool VF2Algorithm::areIsomorphic(const Graph& g1, const Graph& g2) {
    if (g1.getNumVertices() != g2.getNumVertices()) return false;

    std::unordered_map<int, int> mapping;
    std::vector<bool> used(g2.getNumVertices(), false);

    return match(g1, g2, mapping, used, 0);
}
