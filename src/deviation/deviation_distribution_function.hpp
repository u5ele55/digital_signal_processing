#ifndef DEVIATION_DISTRIBUTION_FUNCTION
#define DEVIATION_DISTRIBUTION_FUNCTION

#include <vector>

class DeviationDistributionFunction {
private:
    std::vector<double> m_deviations;
public:
    explicit DeviationDistributionFunction(const std::vector<double> &deviations);
    
    /// @brief As distribution is discrete, its distribution function is step function. Thus, it can be represented 
    /// as set of points where function changes its values.
    /// @return Vector of pairs where first value is coordinate of step point and second is function value in this point.
    /// Vector is sorted by point coordinates. 
    std::vector< std::pair<double, double> > getFunctionValues();
};

#endif