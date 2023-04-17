#include "math_utilities.hpp"
#include <numeric>

double MathUtilities::dispersion(const std::vector<double> &values) {
    int n = values.size();
    double middleValue = std::accumulate(values.begin(), values.end(), 0.0) / n;

    double dispersion = 0;
    for(const double &x : values) {
        dispersion += (x - middleValue) * (x - middleValue);
    }
    dispersion /= n;

    return dispersion;
}