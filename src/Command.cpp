//
// Created by Artemis on 26/05/2023.
//

#include <iostream>
#include "Command.h"
#include "StockDatabase.h"
#include "CoinsDatabase.h"

namespace ppd {
    ReturnType Command::execute(Invoker& cmdInvoker) {

        ReturnType commandResult = SUCCESS;
        std::cout << introString << std::endl;

        auto response = runSubFunction(cmdInvoker);

        if (response == HELP){
            std::cout << helpString << std::endl;
        }
        else if (response == EOFILE) {
            commandResult = EOFILE;
        }

        return commandResult;
    }
}