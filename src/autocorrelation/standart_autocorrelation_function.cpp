#include "standart_autocorrelation_function.hpp"
#include "../utilities/math_utilities.hpp"

#include <numeric>
#include <math.h>

double StandartAutocorrelationFunction::evaluateAt(const std::vector<double> &signals, int lag)
{
    int N = signals.size();

    std::vector<double> start(signals.begin(), signals.end() - lag);
    std::vector<double> shifted(signals.begin() + lag, signals.end());

    double middleStart = std::accumulate(start.begin(), start.end(), 0.0) / (N - lag);
    double middleShifted = std::accumulate(shifted.begin(), shifted.end(), 0.0) / (N - lag);

    double middleOfProduct = 0;

    for(int i = 0; i < N - lag; i ++) {
        middleOfProduct += start[i] * shifted[i];
    }
    middleOfProduct /= N - lag;

    double skoStart   = std::sqrt( MathUtilities::dispersion(start) );
    double skoShifted = std::sqrt( MathUtilities::dispersion(shifted) );

    double r = (middleOfProduct - middleStart * middleShifted) / (skoShifted * skoStart);

    return r;
}

std::vector<double> StandartAutocorrelationFunction::evaluate(const std::vector<double> &signals)
{
    int N = signals.size();
    std::vector<double> values(N / 4);

    for (int i = 0; i < N / 4; i ++) {
        values[i] = evaluateAt(signals, i);
    }

    return values;
}