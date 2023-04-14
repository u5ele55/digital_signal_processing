#ifndef SIGNAL_FILTER
#define SIGNAL_FILTER

#include <vector>

class ISignalFilter {
public:
    /// @brief Creates new vector that consists of filtered values of sequence
    /// @param sequence Values of signal measurements
    /// @return Vector with filtered values
    virtual std::vector<double> filteredSequence(const std::vector<double> &sequence) = 0;
};

#endif