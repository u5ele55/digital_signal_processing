#ifndef AUTOCORRELATION_FUNCTION
#define AUTOCORRELATION_FUNCTION

#include <vector>

class IAutocorrelationFunction {
public:
    /// @brief Calculates function for given signal values
    /// @param signals Vector of signal values
    /// @return Values of function for lags from 0 to N / 4, where N is size of `signals`
    virtual std::vector<double> evaluate(const std::vector<double> &signals) = 0;

    virtual ~IAutocorrelationFunction() {}
};

#endif