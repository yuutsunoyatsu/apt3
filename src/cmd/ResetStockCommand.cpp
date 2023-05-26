//
// Created by Artemis on 26/05/2023.
//

#include <sstream>
#include "ResetStockCommand.h"

namespace ppd {
    ResetStockCommand::ResetStockCommand() {
        std::stringstream ss;
        ss << "Resetting stock to default value of "
           << DEFAULT_STOCK_LEVEL << "...";
        introString = ss.str();

        helpString = "";
    }

    ReturnType ResetStockCommand::runSubFunction(Invoker cmdInvoker) {
        auto& coinsList = cmdInvoker.sdb->getList();
        for (auto& item: coinsList) {
            item.onHand = DEFAULT_STOCK_LEVEL;
        }
        return SUCCESS;
    }
} // ppd