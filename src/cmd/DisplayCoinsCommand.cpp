//
// Created by Artemis on 26/05/2023.
//

#include <sstream>
#include <iomanip>
#include "DisplayCoinsCommand.h"

namespace ppd {
    DisplayCoinsCommand::DisplayCoinsCommand() {
        introString = "Displaying coins...";
        helpString = "";
    }

    ReturnType DisplayCoinsCommand::runSubFunction(Invoker cmdInvoker) {
        auto& coins = cmdInvoker.cdb->getList();

        std::cout << "\nCoins Summary\n"
                     "-------------\n"
                     "Denomination    |    Count\n"
                     "---------------------------" << std::endl;

        for (const auto& denom: coins) {
            // Create representation string e.g. 1 Dollars or 50 Cents
            std::stringstream centOrDollar;
            if (denom.denomination % 100 == 0) {
                centOrDollar << denom.denomination / 100;
                centOrDollar << " Dollars";
            }
            else {
                centOrDollar << denom.denomination;
                centOrDollar << " Cents";
            }

            // Print row
            std::cout << std::setfill(' ');
            std::cout << std::left << std::setw(16) << centOrDollar.str();
            std::cout << "|";
            std::cout << std::right << std::setw(10) << denom.amount << std::endl;

        }
        std::cout << std::endl;

        return SUCCESS;
    }
} // ppd