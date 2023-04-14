#include <iostream>
#include "signal_generator/simple_signal_generator.hpp"

int main()
{
    ISignalGenerator * generator = new SimpleSignalGenerator(5, 3, 0);
    
    for (const auto& value : generator->getSignalSequence(0, 0.1, 25)) {
        std::cout << value << '\n';
    }

    delete generator;
}