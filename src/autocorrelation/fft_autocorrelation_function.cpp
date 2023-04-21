#include "fft_autocorrelation_function.hpp"
#include "../utilities/math_utilities.hpp"

std::vector<double> FFTAutocorrelationFunction::evaluate(const std::vector<double> &signals)
{
    std::vector< std::complex<double> > values(signals.size());
    for (size_t i = 0; i < signals.size(); i ++) {
        values[i] = signals[i];
    }

    // Ф(n) ~ Re ifft( |fft(values)|^2 )

    values = MathUtilities::fft(values);
    for (auto &value : values) {
        value = value.real() * value.real() + value.imag() * value.imag();
    }
    values = MathUtilities::ifft(values);

    // Proportionality coeffitient
    double prop = values[0].real();

    std::vector<double> result(values.size() / 4);
    for (size_t i = 0; i < result.size(); i ++) {
        result[i] = values[i].real() / prop;
    }

    return result;
}