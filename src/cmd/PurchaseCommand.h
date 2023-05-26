//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_PURCHASECOMMAND_H
#define APT3_PURCHASECOMMAND_H

#include "../Command.h"

namespace ppd {

    class PurchaseCommand : public Command {
    public:
        PurchaseCommand();
    private:
        ReturnType runSubFunction(Invoker cmdInvoker) override;

        bool coinLoop(CoinsDatabase *cdb, StockItem& stock);
    };

} // ppd

#endif //APT3_PURCHASECOMMAND_H
