#ifndef ALGORITHM_FACTORY_H
#define ALGORITHM_FACTORY_H

#include "vf2.h"
#include "weisfeiler_lehman.h"
#include "nauty_traces.h"
#include <vector>
#include <memory>

enum AlgorithmType { VF2, WEISFEILER_LEHMAN, NAUTY_TRACES, ALL_ALGORITHMS };

class AlgorithmFactory {
public:
    static std::unique_ptr<GraphIsomorphismAlgorithm> createAlgorithm(AlgorithmType type) {
        switch (type) {
            case VF2:
                return std::make_unique<VF2Algorithm>();
            case WEISFEILER_LEHMAN:
                return std::make_unique<WLAlgorithm>();
            case NAUTY_TRACES:
                return std::make_unique<NautyTracesAlgorithm>();
            case ALL_ALGORITHMS:
                throw std::invalid_argument("Use createAllAlgorithms() to run all algorithms.");
            default:
                throw std::invalid_argument("Invalid algorithm type");
        }
    }

    static std::vector<std::unique_ptr<GraphIsomorphismAlgorithm>> createAllAlgorithms() {
        std::vector<std::unique_ptr<GraphIsomorphismAlgorithm>> algorithms;
        algorithms.push_back(std::make_unique<VF2Algorithm>());
        algorithms.push_back(std::make_unique<WLAlgorithm>());
        algorithms.push_back(std::make_unique<NautyTracesAlgorithm>());
        return algorithms;
    }
};

#endif
