#ifndef VF2_ALGORITHM_H
#define VF2_ALGORITHM_H

#include "graph_isomorphism_algorithm.h"

class VF2Algorithm : public GraphIsomorphismAlgorithm {
private:
    bool match(const Graph& g1, const Graph& g2, 
               std::unordered_map<int, int>& mapping, 
               std::vector<bool>& used, int depth); 
public:
    bool areIsomorphic(const Graph& g1, const Graph& g2) override;
};

#endif
