//
// Created by Artemis on 26/05/2023.
//

#include "MenuCommand.h"

namespace ppd {
    MenuCommand::MenuCommand() {
        this->introString = "\nMain Menu:\n"
                      "  1.Display Items\n"
                      "  2.Purchase Items\n"
                      "  3.Save and Exit\n"
                      "Administrator-Only Menu:\n"
                      "  4.Add Item\n"
                      "  5.Remove Item\n"
                      "  6.Display Coins\n"
                      "  7.Reset Stock\n"
                      "  8.Reset Coins\n"
                      "  9.Abort Program\n"
                      "Select your option (1-9):";

        helpString = "help: input an integer from 1 to 9 to use a command"
                     " from the command list, or type 'help' for help messages.";
    }

    ReturnType MenuCommand::runSubFunction(Invoker cmdInvoker) {
        int userInput;


        auto response = getInt(userInput);

        if (response == SUCCESS) {
            response = cmdInvoker.doCommand(userInput);
        }

        return response;
    }
} // ppd