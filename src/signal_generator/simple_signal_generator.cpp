#include <math.h>

#include "simple_signal_generator.hpp"

SimpleSignalGenerator::SimpleSignalGenerator(double amplitude, double frequency, double phase)
    : m_amplitude(amplitude)
    , m_frequency(frequency)
    , m_phase(phase)
    {}

double SimpleSignalGenerator::signalAt(double time) {
    return m_amplitude * sin(m_frequency * time + m_phase);
}

std::vector<double> SimpleSignalGenerator::getSignalSequence(double start, double step, int quantity) {
    std::vector<double> result(quantity, 0);
    double time;
    for(int i = 0; i < quantity; i ++) {
        time = start + i * step;
        result[i] = signalAt(time);
    }
    return result;
}