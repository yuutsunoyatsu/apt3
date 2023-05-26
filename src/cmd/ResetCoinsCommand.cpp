//
// Created by Artemis on 26/05/2023.
//

#include <sstream>
#include "ResetCoinsCommand.h"

namespace ppd {
    ResetCoinsCommand::ResetCoinsCommand() {
        std::stringstream ss;
        ss << "Resetting coins to default value of "
        << DEFAULT_COIN_COUNT << "...";
        introString = ss.str();

        helpString = "";
    }

    ReturnType ResetCoinsCommand::runSubFunction(Invoker cmdInvoker) {
        auto& coinsList = cmdInvoker.cdb->getList();
        for (auto& item: coinsList) {
            item.amount = DEFAULT_COIN_COUNT;
        }
        return SUCCESS;
    }
} // ppd