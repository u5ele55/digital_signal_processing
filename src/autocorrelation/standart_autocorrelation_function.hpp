#ifndef STANDART_AUTOCORRELATION_FUNCTION
#define STANDART_AUTOCORRELATION_FUNCTION

#include "autocorrelation_function.hpp"

/// @brief Uses  
class StandartAutocorrelationFunction : public IAutocorrelationFunction {
private:
    /// @brief Calculates single value of the function 
    /// @param signals Signal values
    /// @param lag Shift relative to beginning of the `signals`
    /// @return Correlation coeffitient
    double evaluateAt(const std::vector<double> &signals, int lag);
public:
    std::vector<double> evaluate(const std::vector<double> &signals);
};

#endif