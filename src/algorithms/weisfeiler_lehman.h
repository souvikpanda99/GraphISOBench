#ifndef WEISFEILER_LEHMAN_H
#define WEISFEILER_LEHMAN_H

#include "graph_isomorphism_algorithm.h"
#include <unordered_map>
#include <string>

class WLAlgorithm : public GraphIsomorphismAlgorithm {
private:
    std::unordered_map<int, std::string> computeLabels(const Graph& g);

public:
    bool areIsomorphic(const Graph& g1, const Graph& g2) override;
};

#endif
