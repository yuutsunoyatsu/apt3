#include "SaveCommand.h"

namespace ppd {
    SaveCommand::SaveCommand() {
        introString = "Saving data to files...";
        helpString = "";
    }

    ReturnType SaveCommand::runSubFunction(ppd::Invoker cmdInvoker) {
        cmdInvoker.cdb->saveData();
        cmdInvoker.sdb->saveData();

        return EOFILE;
    }
} // ppd