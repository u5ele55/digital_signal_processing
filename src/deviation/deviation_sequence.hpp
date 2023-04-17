#ifndef DEVIATION_SEQUENCE
#define DEVIATION_SEQUENCE

#include <vector>

class DeviationSequenceCalculator {
private:
    std::vector<double> m_trueSignal;
public:
    explicit DeviationSequenceCalculator(const std::vector<double> &trueSignal);
    
    /// @brief Calculates deviations of signal relative to true signal values that was given in constructor
    /// @param signal Vector of signal values with deviations
    /// @return Vector of deviations
    std::vector<double> getDeviationSequence(const std::vector<double> &signal);
};

#endif