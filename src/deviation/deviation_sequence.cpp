#include "deviation_sequence.hpp"

DeviationSequenceCalculator::DeviationSequenceCalculator(const std::vector<double> &trueSignal)
    : m_trueSignal(trueSignal) {}

std::vector<double> DeviationSequenceCalculator::getDeviationSequence(const std::vector<double> &signal) {
    std::vector<double> deviations(std::min(signal.size(), m_trueSignal.size()));

    for (std::size_t i = 0; i < std::min(signal.size(), m_trueSignal.size()); i ++) {
        deviations[i] = m_trueSignal[i] - signal[i];
    }

    return deviations;
}