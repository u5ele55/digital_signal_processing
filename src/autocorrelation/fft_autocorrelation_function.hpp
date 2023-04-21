#ifndef FFT_AUTOCORRELATION_FUNCTION
#define FFT_AUTOCORRELATION_FUNCTION

#include "autocorrelation_function.hpp"

/// @brief Vector of signals must have size equal to some power of 2
class FFTAutocorrelationFunction : public IAutocorrelationFunction {
public:
    std::vector<double> evaluate(const std::vector<double> &signals);
};

#endif