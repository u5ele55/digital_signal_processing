#ifndef SIGNAL_GENERATOR
#define SIGNAL_GENERATOR

#include <vector>

class ISignalGenerator {

public:
    /// @brief Get single signal value at exact time moment 
    /// @param time Moment of time where signal is measured 
    /// @return Signal value at 'time' second
    virtual double signalAt(double time) const = 0;

    /// @brief Get sequence of signals with constant difference in time
    /// @param start Start time of sequence
    /// @param step Time difference between measurements
    /// @param quantity Quantity of measurements
    /// @return Vector of signal values, where value at 'i-th' index corresponds to
    /// signal value at 'start + i * step' moment of time
    virtual std::vector<double> getSignalSequence(
        double start, double step, int quantity) const = 0;
};

#endif