#ifndef GRAPH_ISOMORPHISM_ALGORITHM_H
#define GRAPH_ISOMORPHISM_ALGORITHM_H

#include "graph.h"

class GraphIsomorphismAlgorithm {
public:
    virtual bool areIsomorphic(const Graph& g1, const Graph& g2) = 0;
    virtual ~GraphIsomorphismAlgorithm() {}
};

#endif