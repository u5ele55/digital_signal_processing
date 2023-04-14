#include <math.h>
#include <random>

#include "normal_noise_signal_generator.hpp"

NormalNoiseSignalGenerator::NormalNoiseSignalGenerator(
    double amplitude, double frequency, double phase, double dispersion)
    : m_amplitude(amplitude)
    , m_frequency(frequency)
    , m_phase(phase)
    , m_dispersion(dispersion)
    , m_distribution(0, m_dispersion)
    {}

double NormalNoiseSignalGenerator::signalAt(double time) {
    double randomNoise = m_distribution(m_generator);
    return m_amplitude * sin(m_frequency * time + m_phase) + randomNoise;
}

std::vector<double> NormalNoiseSignalGenerator::getSignalSequence(
    double start, double step, int quantity) 
{
    std::vector<double> result(quantity, 0);
    double time;
    for(int i = 0; i < quantity; i ++) {
        time = start + i * step;
        result[i] = signalAt(time);
    }
    return result;
}