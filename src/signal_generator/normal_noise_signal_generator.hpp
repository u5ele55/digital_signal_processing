#ifndef NORMAL_NOISE_SIGNAL_GENERATOR
#define NORMAL_NOISE_SIGNAL_GENERATOR

#include <random>

#include "signal_generator.hpp"

class NormalNoiseSignalGenerator : public ISignalGenerator {
    double m_amplitude;
    double m_frequency;
    double m_phase;
    double m_dispersion;
    std::default_random_engine m_generator;
    std::normal_distribution<double> m_distribution;
public:
    NormalNoiseSignalGenerator(
        double amplitude, double frequency, double phase, double dispersion);
    double signalAt(double time);
    std::vector<double> getSignalSequence(
        double start, double step, int quantity);
};

#endif