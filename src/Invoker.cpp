//
// Created by Artemis on 26/05/2023.
//

#include "Invoker.h"
#include "cmd/DisplayCommand.h"
#include "cmd/DisplayCoinsCommand.h"
#include "cmd/ResetStockCommand.h"
#include "cmd/ResetCoinsCommand.h"

namespace ppd {
    ReturnType Invoker::doCommand(int cmd) {
        ReturnType response = SUCCESS;

        if (cmd == 1) {
            DisplayCommand dc;
            response = dc.execute(*this);
        }
        else if (cmd == 2) {

        }
        else if (cmd == 3){

        }
        else if (cmd == 4) {

        }
        else if (cmd == 6) {
            DisplayCoinsCommand dcc;
            response = dcc.execute(*this);
        }
        else if (cmd == 7) {
            ResetStockCommand rsc;
            response = rsc.execute(*this);
        }
        else if (cmd == 8) {
            ResetCoinsCommand rsc;
            response = rsc.execute(*this);
        }
        else if (cmd == 9) {
            response = EOFILE;
        }

        return response;
    }
}