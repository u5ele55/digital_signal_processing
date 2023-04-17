#include "deviation_distribution_function.hpp"

#include <algorithm>

DeviationDistributionFunction::DeviationDistributionFunction(const std::vector<double> &deviations)
    : m_deviations(deviations) 
{
    std::sort(m_deviations.begin(), m_deviations.end());
}
    
std::vector< std::pair<double, double> > DeviationDistributionFunction::getFunctionValues() {
    std::vector< std::pair<double, double> > jumps;
    int N = m_deviations.size();

    double prevValue = m_deviations[0], value;
    int valuesCnt = 1;

    for(int i = 1; i < N; i ++) {
        value = m_deviations[i];
        if (value != prevValue) {
            jumps.emplace_back(prevValue, static_cast<double>(valuesCnt) / N);
        } 
        prevValue = value;
        valuesCnt ++;
    }

    jumps.emplace_back(value, static_cast<double> (valuesCnt) / N);

    return jumps;
}