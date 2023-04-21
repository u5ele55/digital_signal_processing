#include <iostream>
#include <memory>

#include "signal_generator/simple_signal_generator.hpp"
#include "signal_generator/normal_noise_signal_generator.hpp"
#include "filtering/windowing_signal_filter.hpp"
#include "autocorrelation/standart_autocorrelation_function.hpp"
#include "autocorrelation/fft_autocorrelation_function.hpp"
#include "deviation/deviation_sequence.hpp"
#include "deviation/deviation_distribution_function.hpp"

#include "utilities/math_utilities.hpp"

int main()
{
    std::shared_ptr<ISignalGenerator> generator(new SimpleSignalGenerator(10, 3, 0));    
    std::shared_ptr<ISignalGenerator> noisyGenerator(new NormalNoiseSignalGenerator(10, 3, 0, 0.1));

    std::shared_ptr<ISignalFilter> wFilter(new WindowingSignalFilter(3));

    std::shared_ptr<IAutocorrelationFunction> autocorr(new StandartAutocorrelationFunction);
    std::shared_ptr<IAutocorrelationFunction> autocorrFFT(new FFTAutocorrelationFunction);

    int N = 64;
    auto signals = generator->getSignalSequence(0, 0.1, N);
    auto noisySignals = noisyGenerator->getSignalSequence(0, 0.1, N);
    auto filtered = wFilter->filteredSequence(noisySignals);

    for (int i = 0; i < N; i ++ ) {
        std::cout << signals[i] << " " << noisySignals[i] << " -> " << filtered[i] << '\n';
    }

    for(const double &v : autocorr->evaluate(filtered)) {
        std::cout << v << " ";
    }
    std::cout << '\n';std::cout << '\n';
    for(const double &v : autocorrFFT->evaluate(filtered)) {
        std::cout << v << " ";
    }
    std::cout << '\n';

    // DeviationSequenceCalculator deviationCalc(filtered);
    // DeviationDistributionFunction devDistrF(deviationCalc.getDeviationSequence(noisySignals));

    // for(const auto &p : devDistrF.getFunctionValues()) {
    //     std::cout << p.first << ' ' << p.second << '\n';
    // }

    // std::cout << '\n'; 

    

    return 0;
}