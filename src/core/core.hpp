#ifndef CORE
#define CORE

#include <memory>
#include <fstream>

#include "../signal_generator/signal_generator.hpp"
#include "../autocorrelation/autocorrelation_function.hpp"
#include "../filtering/signal_filter.hpp"

/// @brief Some CLI for program
class Core {
private:
    void chooseGenerator(int type);
    void chooseFilter(int type);
    void chooseAutocorrelation(int type);
    void printAllInfo();
public:
    Core(std::string outputFile = "result.txt");
    void start();
    ~Core();
private:
    std::shared_ptr<ISignalGenerator> m_signalGenerator;
    std::shared_ptr<ISignalFilter> m_signalFilter;
    std::shared_ptr<IAutocorrelationFunction> m_autocorrFunction;

    std::vector<double> m_signals;
    std::ofstream stream;

    double step;
    double startTime;
};

#endif