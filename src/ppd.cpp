#include <iostream>
#include "VendingMachine.h"

using namespace ppd;

int main(int argc, char *argv[])
{
    int errorCode = EXIT_SUCCESS;

    if (argc < 3) {
        std::cout << "Usage: ./ppd <stockfile> <coinsfile>\n" << std::endl;
        errorCode = EXIT_FAILURE;
    }
    else {
        VendingMachine vm;

        // Try read in data files
        if (vm.tryParseStock(argv[1]) == ReturnType::FAILURE
        || vm.tryParseCoins(argv[2]) == ReturnType::FAILURE) {
            std::cout << "One or more of the provided files is invalid." << std::endl;
        }
        else {
            // Good to start the vending machine
            vm.start();
        }

    }

    exit(errorCode);
}
