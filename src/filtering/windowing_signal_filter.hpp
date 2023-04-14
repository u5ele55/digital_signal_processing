#ifndef WINDOWING_SIGNAL_FILTER
#define WINDOWING_SIGNAL_FILTER

#include "signal_filter.hpp"

class WindowingSignalFilter : public ISignalFilter {
    int m_windowSize;
public:
    WindowingSignalFilter(int windowSize);
    std::vector<double> filteredSequence(const std::vector<double> &sequence);
};

#endif