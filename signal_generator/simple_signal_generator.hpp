#ifndef SIMPLE_SIGNAL_GENERATOR
#define SIMPLE_SIGNAL_GENERATOR

#include "signal_generator.hpp"

class SimpleSignalGenerator : public ISignalGenerator {
    double m_amplitude;
    double m_frequency;
    double m_phase;
public:
    SimpleSignalGenerator(double amplitude, double frequency, double phase);
    double signalAt(double time) const;
    std::vector<double> getSignalSequence(
        double start, double step, int quantity) const;
};

#endif