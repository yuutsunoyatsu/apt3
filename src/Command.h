#ifndef APT3_COMMAND_H
#define APT3_COMMAND_H

#include "Utils.h"
#include "StockDatabase.h"
#include "CoinsDatabase.h"
#include "Invoker.h"

namespace ppd {

    class Command {
    private:
        virtual ReturnType runSubFunction(Invoker cmdInvoker) = 0;

    protected:
        std::string introString;
        std::string helpString;
    public:
        ReturnType execute(Invoker& cmdInvoker);
    };

}

#endif //APT3_COMMAND_H
