#include "DisplayCommand.h"
#include <iomanip>

namespace ppd {
    DisplayCommand::DisplayCommand() {
        introString = "Displaying all stock items:";
        helpString = "";
    }

    ReturnType DisplayCommand::runSubFunction(Invoker cmdInvoker) {
        auto& itemList = cmdInvoker.sdb->getList();

        std::cout << "Items Menu\n"
                     "----------\n"
                     "ID   |Name                                   | Available | Price\n"
                     "-------------------------------------------------------------------\n";

        // Each line of items
        for (const auto& item: itemList) {
            std::cout << std::setfill(' ');
            std::cout << std::left << std::setw(5)
                 << item.id << "|";
            std::cout << std::left << std::setw(39)
                 << item.name << "|";
            std::cout << std::left << std::setw(10)
                 << item.onHand << " |";
            std::cout << std::fixed << std::setprecision(3)
                 << "$ " << item.price.dollars << ".";
            std::cout << std::setfill('0') << std::setw(2) <<
                 item.price.cents << std::endl;
        }

        return SUCCESS;
    }
} // ppd