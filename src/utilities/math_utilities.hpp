#ifndef MATH_UTILITIES
#define MATH_UTILITIES

#include <vector>

class MathUtilities {
public:
    /// @brief Calculates dispersion of values
    /// @param values Vector of values
    /// @return Non-negative value - dispersion
    static double dispersion(const std::vector<double> &values);
};

#endif