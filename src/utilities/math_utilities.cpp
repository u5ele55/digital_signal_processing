#include "math_utilities.hpp"
#include <numeric>

#include <cmath>

static const std::complex<double> J(0, 1);
static const double PI = acos(-1); 

double MathUtilities::dispersion(const std::vector<double> &values) {
    int n = values.size();
    double meanValue = std::accumulate(values.begin(), values.end(), 0.0) / n;

    double dispersion = 0;
    for(const double &x : values) {
        dispersion += (x - meanValue) * (x - meanValue);
    }
    dispersion /= n;

    return dispersion;
}

/// @brief 
/// @param values Vector of complex values
/// @param degree_mlt Multiplier in exponenent degree 
/// @return Result of base transform operations
static std::vector< std::complex<double> > dft_base(
    const std::vector< std::complex<double> > &values, double degree_mlt = -1
) {
    int N = values.size();
    std::vector< std::complex<double> > X(N);

    for (int i = 0; i < N; i ++) {
        X[i] = 0;
        for (int n = 0; n < N; n ++) {
            double mlt = i * n;
            X[i] += values[n] * exp(degree_mlt * J * 2.0 * PI * (mlt / N)); 
        }
    }

    return X;
}

std::vector< std::complex<double> > MathUtilities::dft(
    const std::vector< std::complex<double> > &values)
{
    return dft_base(values);
}

/// @brief Base function for both fft and ifft
/// @param values Vector of complex values
/// @param degree_mlt Multiplier in exponenent degree 
/// @return Result of base transform operations
static std::vector< std::complex<double> > fft_base(
    const std::vector< std::complex<double> > &values, double degree_mlt = -1) 
{
    typedef std::vector< std::complex<double> > vector_cx;
    // Extending size to 2^k >= values.size()
    size_t l2 = std::log2(values.size());
    size_t N = 1 << l2;
    if (N != values.size()) {
        throw std::invalid_argument("vector must have size equal to some power of 2");
    }

    if (N <= 8) {
        return dft_base(values, degree_mlt);
    }

    vector_cx x_even(N / 2), 
              x_odd(N / 2);

    for(size_t i = 0; i < N / 2; i ++) {
        x_even[i] = values[2*i];
        x_odd[i] = values[2*i + 1];
    }


    vector_cx X_even = fft_base(x_even, degree_mlt), 
              X_odd = fft_base(x_odd, degree_mlt),
              X(N);
    
    for (size_t i = 0; i < N / 2; i ++) {
        X[i] = X_even[i] + X_odd[i] * exp(degree_mlt * J * 2.0 * PI * (static_cast<double>(i) / N));
        X[i + N / 2] = X_even[i] + X_odd[i] * exp(
            degree_mlt * J * 2.0 * PI * (static_cast<double>(i + N / 2) / N)
            );
    }

    return X;
}

std::vector< std::complex<double> > MathUtilities::fft(
    const std::vector< std::complex<double> > &values)
{
    return fft_base(values);
}

std::vector< std::complex<double> > MathUtilities::ifft(
    const std::vector< std::complex<double> > &values)
{
    auto res = fft_base(values, 1);
    for(auto &v : res) {
        v /= values.size();
    }
    return res;
}