#include "core.hpp"

#include <iostream>

void Core::start() {
    std::cout << "Choose signal generator type: \n";
    std::cout << "1. Asin(wt + p)\n";

    int generatorType;
    std::cin >> generatorType;

    chooseGenerator(generatorType);

    std::cout << "Choose signal filter type: \n";
    std::cout << "1. Windowing method\n";

    int filterType;
    std::cin >> filterType;

    chooseFilter(filterType);

    // TODO: some info about deviations

    std::cout << "Choose autocorrelation function: \n";
    std::cout << "1. Standart method\n2. FFT method\n";

    int autocorrType;
    std::cin >> autocorrType;

    chooseAutocorrelation(autocorrType);


}

void Core::chooseGenerator(int type) {
    while (type < 0 || type > 1) {
        std::cout << "Enter valid type!\n";
        std::cin >> type;
    }
    
    if (type == 1) {
        
    }
}

void Core::chooseAutocorrelation(int type){

}
void Core::chooseFilter(int type) {

}
