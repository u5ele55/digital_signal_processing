#ifndef MATH_UTILITIES
#define MATH_UTILITIES

#include <vector>
#include <complex>

class MathUtilities {
public:
    /// @brief Calculates dispersion of values
    /// @param values Vector of values
    /// @return Non-negative value - dispersion
    static double dispersion(const std::vector<double> &values);

    /// @brief Calculates discrete fourier transform for values 
    /// @param values Vector of values (signals) - complex values
    /// @return Vector of complex values - result of the transform
    static std::vector< std::complex<double> > dft(
        const std::vector< std::complex<double> > &values);

    /// @brief Calculates fast fourier transform for values 
    /// @param values Vector of values (signals) - complex values. Its size must be a power of 2
    /// @return Vector of complex values - result of the transform
    static std::vector< std::complex<double> > fft(
        const std::vector< std::complex<double> > &values);
    
    /// @brief Calculates inverse fast fourier transform for values 
    /// @param values Vector of values (signals) - complex values. Its size must be a power of 2
    /// @return Vector of complex values - result of the inverse transform
    static std::vector< std::complex<double> > ifft(
        const std::vector< std::complex<double> > &values);
};

#endif