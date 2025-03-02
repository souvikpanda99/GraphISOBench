#ifndef NAUTY_TRACES_H
#define NAUTY_TRACES_H

#include "graph_isomorphism_algorithm.h"

class NautyTracesAlgorithm : public GraphIsomorphismAlgorithm {
public:
    bool areIsomorphic(const Graph& g1, const Graph& g2) override;
};

#endif
