#include <iostream>
#include "signal_generator/simple_signal_generator.hpp"
#include "signal_generator/normal_noise_signal_generator.hpp"

int main()
{
    ISignalGenerator * generator = new SimpleSignalGenerator(10, 3, 0);    
    ISignalGenerator * noisyGenerator = new NormalNoiseSignalGenerator(10, 3, 0, 0.1);

    int N = 25;
    auto signals = generator->getSignalSequence(0, 0.1, N);
    auto noisySignals = noisyGenerator->getSignalSequence(0, 0.1, N);

    for (int i = 0; i < N; i ++ ) {
        std::cout << signals[i] << " " << noisySignals[i] << '\n';
    }

    delete generator;
    delete noisyGenerator;

    return 0;
}