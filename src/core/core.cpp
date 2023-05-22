#include "core.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>

#include "../signal_generator/normal_noise_signal_generator.hpp"
#include "../signal_generator/simple_signal_generator.hpp"

#include "../filtering/windowing_signal_filter.hpp"

#include "../autocorrelation/standart_autocorrelation_function.hpp"
#include "../autocorrelation/fft_autocorrelation_function.hpp"

#include "../deviation/deviation_sequence.hpp"
#include "../deviation/deviation_distribution_function.hpp"

Core::Core(std::string outputFile)
{
    stream.open(outputFile);
}

void Core::start()
{
    std::cout << "Choose signal generator type: \n";
    std::cout << "1. Asin(wt + p)\n2. Asin(wt + p) + noise\n";

    int generatorType;
    std::cin >> generatorType;

    chooseGenerator(generatorType);

    std::cout << "Choose signal filter type: \n";
    std::cout << "1. Windowing method\n";

    int filterType;
    std::cin >> filterType;

    chooseFilter(filterType);

    std::cout << "Choose autocorrelation function: \n";
    std::cout << "1. Standart method\n2. FFT method\n";

    int autocorrType;
    std::cin >> autocorrType;

    chooseAutocorrelation(autocorrType);

    printAllInfo();
}

Core::~Core()
{
    stream.close();
}

void Core::printAllInfo() {
    if (m_signals.size() > 16) {
        std::cout << "\n\n Result printed to file \n";
    }

    stream << "\n --- RESULT --- \n\n";
    stream << std::fixed << std::setprecision(3);

    stream << "Generated signal sequence: \n";
    for(size_t i = 0; i < m_signals.size(); i ++) {
        stream << '\t' << startTime + step * i << ' ' << m_signals[i] << '\n';
    }
    stream << '\n';

    stream << "Filtered signal sequence: \n";
    auto filteredSignals = m_signalFilter->filteredSequence(m_signals);
    for(size_t i = 0; i < filteredSignals.size(); i ++) {
        stream << '\t' << startTime + step * i << " " << filteredSignals[i] << '\n';
    }
    stream << '\n';

    stream << "Deviations sequence: \n\t";
    auto deviations = DeviationSequenceCalculator(filteredSignals).getDeviationSequence(m_signals);
    for(const auto &deviation : deviations) {
        stream << deviation << ' ';
    }
    stream << '\n';

    
    stream << "Deviation distribution function:\n";
    auto distrFunc = DeviationDistributionFunction(deviations).getFunctionValues();
    for(const auto &value : distrFunc) {
        stream << '\t' << std::setprecision(8) << value.first << " " << value.second << '\n';
    }
    stream << '\n'; 

    stream << "Autocorrelation function values: \n";
    try {
        auto autoCorrVals = m_autocorrFunction->evaluate(m_signals);
        for(size_t i = 0; i < autoCorrVals.size(); i ++) {
            stream << '\t' << autoCorrVals[i] << '\n';
        }
    } catch (const std::invalid_argument& err) {
        stream << err.what();
    }
    stream << '\n';
}


void Core::chooseGenerator(int type) {
    
    while (type < 1 || type > 2) {
        std::cout << "Enter valid type!\n";
        std::cin >> type;
    }
    double A, w, p;
    double disp;
    if (type == 1 || type == 2) {
        std::cout << "Enter A: "; std::cin >> A;
        std::cout << "Enter w: "; std::cin >> w;
        std::cout << "Enter p: "; std::cin >> p;
        
        if (type == 1) {
            m_signalGenerator.reset(new SimpleSignalGenerator(A, w, p));
        } else {
            std::cout << "Enter dispersion: "; std::cin >> disp;
            m_signalGenerator.reset(new NormalNoiseSignalGenerator(A, w, p, disp));
        }
    }

    std::cout << "Enter start time: "; std::cin >> startTime;
    std::cout << "Enter step: "; std::cin >> step;
    int quantity;
    std::cout << "Enter sample size: "; std::cin >> quantity;

    m_signals = m_signalGenerator->getSignalSequence(startTime, step, quantity);

    stream << "Generator:\n\tA = " << A << "\n\tw = " << w << "\n\tp = " << p << '\n';
    if (type == 2) {
        stream << "\tdispersion = " << disp << '\n';
    }
    stream << "\tstart time: " << startTime << "\n\tstep: " << step << "\n\tsample size: " << quantity << '\n';
}

void Core::chooseFilter(int type) {
    while (type < 1 || type > 1) {
        std::cout << "Enter valid type!\n";
        std::cin >> type;
    }

    if (type == 1) {
        size_t windowSize;
        std::cout << "Enter window size: "; std::cin >> windowSize;
        while (windowSize < 0 || windowSize >= m_signals.size()) {
            std::cout << "Window size should be less than sample size! Enter again: "; 
            std::cin >> windowSize;
        }
        m_signalFilter.reset(new WindowingSignalFilter(windowSize));
    }
}

void Core::chooseAutocorrelation(int type){
    while (type < 1 || type > 2) {
        std::cout << "Enter valid type!\n";
        std::cin >> type;
    }
    
    if (type == 1) {
        m_autocorrFunction.reset(new StandartAutocorrelationFunction);
    } else if (type == 2) {
        m_autocorrFunction.reset(new FFTAutocorrelationFunction);
    }
}