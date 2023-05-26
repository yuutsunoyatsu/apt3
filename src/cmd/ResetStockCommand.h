#ifndef APT3_RESETSTOCKCOMMAND_H
#define APT3_RESETSTOCKCOMMAND_H

#include "../Command.h"

namespace ppd {
    #define DEFAULT_STOCK_LEVEL 20

    class ResetStockCommand : public Command{
    public:
        ResetStockCommand();
        ReturnType runSubFunction(Invoker cmdInvoker) override;
    };

} // ppd

#endif //APT3_RESETSTOCKCOMMAND_H
